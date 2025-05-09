#include <stdio.h>
#include <stdlib.h>

// DESAFIO NÍVEL MESTRE

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar navios
int posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * d_linha;
        int c = coluna + i * d_coluna;

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != AGUA)
            return 0; 
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * d_linha;
        int c = coluna + i * d_coluna;
        tabuleiro[l][c] = NAVIO;
    }

    return 1;
}

void construir_cone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= (TAMANHO_HABILIDADE / 2) - i && j <= (TAMANHO_HABILIDADE / 2) + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void construir_cruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void construir_octaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origem_linha, int origem_coluna) {
    int centro = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int l = origem_linha + (i - centro);
            int c = origem_coluna + (j - centro);

            if (l >= 0 && l < TAMANHO_TABULEIRO && c >= 0 && c < TAMANHO_TABULEIRO && matriz[i][j] == 1) {
            
                if (tabuleiro[l][c] == AGUA)
                    tabuleiro[l][c] = HABILIDADE;
            }
        }
    }
}

void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Legenda: 0 = Água | 3 = Navio | 5 = Habilidade\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializar_tabuleiro(tabuleiro);

    // posicionando alguns navios 
    posicionar_navio(tabuleiro, 1, 1, 0, 1); // Horizontal
    posicionar_navio(tabuleiro, 4, 2, 1, 0); // Vertical
    posicionar_navio(tabuleiro, 0, 0, 1, 1); // Diagonal ↘
    posicionar_navio(tabuleiro, 2, 9, 1, -1); // Diagonal ↙

    // matrizes das habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    construir_cone(cone);
    construir_cruz(cruz);
    construir_octaedro(octaedro);

    // aplicando as habilidades em diferentes pontos do tabuleiro
    aplicar_habilidade(tabuleiro, cone, 2, 5);
    aplicar_habilidade(tabuleiro, cruz, 6, 6);
    aplicar_habilidade(tabuleiro, octaedro, 8, 2);

    // exibe o tabuleiro completo
    exibir_tabuleiro(tabuleiro);

    return 0;
}
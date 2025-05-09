#include <stdio.h>

// DESAFIO NÍVEL AVENTUREIRO

// definindo tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3


int posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao_linha, int direcao_coluna) {

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcao_linha;
        int c = coluna + i * direcao_coluna;

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
            return 0; 

        if (tabuleiro[l][c] != 0)
            return 0; 
    }

    // Posiciona o navio no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcao_linha;
        int c = coluna + i * direcao_coluna;
        tabuleiro[l][c] = 3;
    }

    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int sucesso = 0;

    // 1º navio - horizontal
    sucesso = posicionar_navio(tabuleiro, 1, 2, 0, 1);
    if (!sucesso) printf("Erro ao posicionar navio 1\n");

    // 2º navio - vertical
    sucesso = posicionar_navio(tabuleiro, 4, 7, 1, 0);
    if (!sucesso) printf("Erro ao posicionar navio 2\n");

    // 3º navio - diagonal principal (↘)
    sucesso = posicionar_navio(tabuleiro, 0, 0, 1, 1);
    if (!sucesso) printf("Erro ao posicionar navio 3\n");

    // 4º navio - diagonal secundária (↙)
    sucesso = posicionar_navio(tabuleiro, 2, 7, 1, -1);
    if (!sucesso) printf("Erro ao posicionar navio 4\n");

    // exibe o tabuleiro final
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
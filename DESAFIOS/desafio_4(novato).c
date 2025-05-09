#include <stdio.h>

// DESAFIO NÍVEL NOVATO

// Tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Matriz 10x10 representando o tabuleiro (0 = água, 3 = navio)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // inicializando o tabuleiro com zero agua 
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Vetores representando os navios (definindo o valor em 3)
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // coordenadas iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 4;  // Posição inicial do navio horizontal
    int linha_vertical = 5, coluna_vertical = 7;      // Posição inicial do navio vertical

    // Verifica se o navio horizontal cabe no tabuleiro e não há sobreposição
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
            }
        }
    }

    // Verifica se o navio vertical cabe no tabuleiro e não há sobreposição
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        }
    }

    // exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
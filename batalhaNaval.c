#include <stdio.h>
#include <stdlib.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void print_matriz(char **table){
    for(int i = 0; table[i]; i++){
        for(int j = 0; table[i][j]; j++){
            printf("%c", table[i][j]);
            if(table[i][j + 1] != '\0')
                printf(", ");
        }
        printf("\n");
    }
}

void clean_matriz(char **table){
    for(int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}
void novato(){
    char **table = calloc(sizeof(char *), 6);
    for(int i = 0; i < 5; i++){
        table[i] = calloc(sizeof(char), 6);
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if (i == 4 && j > 1)
                table[i][j] = 'N';
            else if(j == 0 && i < 3)
                table[i][j] = 'N';
            else
                table[i][j] = '0';
        }
    }
    print_matriz(table);
    clean_matriz(table);
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    novato();
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}

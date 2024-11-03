#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void print_matriz(char **table){
    for(int i = 0; table[i]; i++){
        for(int j = 0; table[i][j]; j++){
            printf("%c", table[i][j]);
            if(table[i][j + 1] != '\0')
                printf(" ");
        }
        printf("\n");
    }
}

void clean_matriz(char **table){
    for(int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}

char **criar_tabela(int size){
    size++;
    char **table = calloc(sizeof(char *), size);
    for(int i = 0; i < size - 1; i++){
        table[i] = calloc(sizeof(char), size);
    }
    return table;
}

void novato(){
    char **table = criar_tabela(5);

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
    for(int i = 0; table[i]; i++){
        for(int j = 0; table[i][j]; j++){
            if (table[i][j] == 'N')
                printf("Linha: %d Coluna: %d -> Valor %c \n", i, j, table[i][j]);
        }
    }
    clean_matriz(table);
}

void aventureiro(){
    char **table = criar_tabela(10);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if (i == 8 && j >=0 && j <= 4)
                table[i][j] = '3';
            else if(j == 0 && i < 5)
                table[i][j] = '3';
            else if(i == j && i >=5 && i <= 9)
                table[i][j] = '3';
            else if(j == 9 - i && j > 4)
                table[i][j] = '3';
            else
                table[i][j] = '0';
        }
    }
    print_matriz(table);
    clean_matriz(table);
}

void mestre(){

    char **table = criar_tabela(5);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            table[i][j] = '0';
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j <= 2 * i; j++){
            table[i][4 -i + j] = '1';
        }
    }
   print_matriz(table);
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    printf("Novato\n");
    novato();
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    printf("\nAventureiro\n");
    aventureiro();
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
        printf("\nMestre\n");
    mestre();
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

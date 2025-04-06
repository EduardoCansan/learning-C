/*
3) Faca um programa que alimente duas matrizes de 3x3 com valores decimais, calcule a 
soma, multiplicação, subtração e divisão de uma matriz pela outra
*/

#include <stdio.h>
#include <conio.h>

#define TAMANHO 3

void somarMatrizes(int i, int j) {
    int soma = (i + j);
    printf("%d", soma);
}

void subtrairMatrizes(int i, int j) {
    int subratacao = (i - j);
    printf("%d", subratacao);
}

void multiplicarMatrizes(int i, int j) {
    int multiplicacao = (i * j);
    printf("%d", multiplicacao);
}

void divisaoMatrizes(float i, float j) {
    
    if (j ==0) 
    {
        printf("Divisao Por 0 invalida!");
    }
    else 
    {
        float divisao = (i / j);
        printf("%.2f", divisao);    
    }
}

int main() {

    int matrixUm[TAMANHO][TAMANHO];
    int matrixDois[TAMANHO][TAMANHO];
    int i, j;
    
    printf("Escolha os numeros da Matriz 1\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("Digite o Numero da Matriz: [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixUm[i][j]);
        }
    }
    
    printf("\nEscolha os numeros da Matriz 2\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("Digite o Numero da Matriz: [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixDois[i][j]);
        }
    }
    
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            
            printf("\nSoma da Matriz 1 [%d][%d] e da Matriz 2 [%d][%d]: ", i + 1, j + 1, i + 1, j + 1);
            somarMatrizes(matrixUm[i][j], matrixDois[i][j]);
            
            printf("\nSubratacao da Matriz 1 [%d][%d] e da Matriz 2 [%d][%d]: ", i + 1, j + 1, i + 1, j + 1);
            subtrairMatrizes(matrixUm[i][j], matrixDois[i][j]);
            
            printf("\nMultiplicacao da Matriz 1 [%d][%d] e da Matriz 2 [%d][%d]: ", i + 1, j + 1, i + 1, j + 1);
            multiplicarMatrizes(matrixUm[i][j], matrixDois[i][j]);
            
            printf("\nDivisao da Matriz 1 [%d][%d] e da Matriz 2 [%d][%d]: ", i + 1, j + 1, i + 1, j + 1);
            divisaoMatrizes(matrixUm[i][j], matrixDois[i][j]);
            printf("\n");
            
        }
    }

}
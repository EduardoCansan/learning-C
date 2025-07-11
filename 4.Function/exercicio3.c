/*
3 - Escreva um algoritmo para inserir dados em dois vetores de 10 posições. Realize a multiplicação, soma, subtração e divisão
	dos dados dos vetores e imprima os dados em tela. Alimentar os vetores por funções (Referência).
*/

#include <stdio.h>
#define TAMANHO 10

void somarVetores(int i, int j) {
    int soma = (i + j);
    printf("%d", soma);
}

void subtrairVetores(int i, int j) {
    int subratacao = (i - j);
    printf("%d", subratacao);
}

void multiplicarVetores(int i, int j) {
    int multiplicacao = (i * j);
    printf("%d", multiplicacao);
}

void dividirVetores(float i, float j) {
    
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

int main()
{
    int vetorUm[TAMANHO], vetorDois[TAMANHO];
    int i;

    printf("Digite os valores de do Vetor 1: \n");
    for (i = 0; i < TAMANHO; i++) {
        printf("Escolha o numero do Vetor[%d]: ", i + 1);
        scanf("%d", &vetorUm[i]);
    }
    
    printf("\nDigite os valores de do Vetor 2: \n");
    for (i = 0; i < TAMANHO; i++) {
        printf("Escolha o numero do Vetor[%d]: ", i + 1);
        scanf("%d", &vetorDois[i]);
    }
    
    for (i = 0; i < TAMANHO; i++) {
        printf("\nSoma do Vetor 1 [%d] e do Vetor 2 [%d]: ", i + 1, i + 1);
        somarVetores(vetorUm[i], vetorDois[i]);
        
        printf("\nSubtracao do Vetor 1 [%d] e do Vetor 2 [%d]: ", i + 1, i + 1);
        subtrairVetores(vetorUm[i], vetorDois[i]);
        
        printf("\nMultiplicacao do Vetor 1 [%d] e do Vetor 2 [%d]: ", i + 1, i + 1);
        multiplicarVetores(vetorUm[i], vetorDois[i]);
        
        printf("\nDivisao do Vetor 1 [%d] e do Vetor 2 [%d]: ", i + 1, i + 1);
        dividirVetores(vetorUm[i], vetorDois[i]);
        printf("\n");
    }
    
    return 0;
}
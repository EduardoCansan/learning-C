#include <stdio.h>

int maiorValor(int num[], int tamanho);

int main()
{
    int size = 3, vetorA[size];

    maiorValor(vetorA, size);
    return 0;
}

int maiorValor(int num[], int tamanho) {
    int i, maior = 0;

    for (i = 0; i < tamanho; i++)
    {
        printf("Digite o valor do vetor[%d]: ", i);
        scanf("%d", &num[i]);
    }

    maior = num[0];

    for (i = 0; i < tamanho; i++)
    {
        if(num[i] > maior) {
            maior = num[i];
        }
    }

    printf("Maior valores: %d", maior);
    return maior;
    
}
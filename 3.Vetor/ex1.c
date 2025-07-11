#include <stdio.h>

int main()
{

    int vetorA[6];

    vetorA[0] = 1;
    vetorA[1] = 0;
    vetorA[2] = 5;
    vetorA[3] = -2;
    vetorA[4] = -5;
    vetorA[5] = 7;

    int soma = vetorA[0] + vetorA[1] + vetorA[2];

    vetorA[3] = 100;

    printf("Soma dos 3 primeiros vetores: %d", soma);
    printf("\nVetor[3] = %d", vetorA[3]);

    int i;

    for (i = 0; i < 6; i++)
    {
        printf("\nVetor[%d] = %d", i, vetorA[i]);
    }

    return 0;
}
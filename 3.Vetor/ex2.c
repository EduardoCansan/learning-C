#include <stdio.h>

int main()
{
    
    int vetorA[10], i, par = 0;

    for (i = 0; i < 10; i++)
    {
        printf("Digite o valor do vetor[%d]: ", i);
        scanf("%d", &vetorA[i]);
    }

    for (i = 0; i < 10; i++)
    {
        if(vetorA[i] % 2 == 0) {
            printf("\nVetor[%d] = %d", i, vetorA[i]);
            par ++;
        }
    }

    printf("\nTotal de valores pares: %d", par);
    
    return 0;
}

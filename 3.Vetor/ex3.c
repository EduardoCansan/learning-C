#include <stdio.h>

int main()
{
    
    int vetorA[10], i;

    for (i = 0; i < 10; i++)
    {
        printf("Digite o valor do vetor[%d]: ", i);
        scanf("%d", &vetorA[i]);
    }

    for (i = 0; i < 10; i++)
    {
        if(vetorA[i] < 0) {
            vetorA[i] = 0;
        }
        printf("\nVetor[%d] = %d", i, vetorA[i]);
    }
    
    return 0;
}

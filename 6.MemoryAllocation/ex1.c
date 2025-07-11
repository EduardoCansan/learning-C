#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int *p, vetor[5], i;

    p = (int*)malloc(sizeof(vetor)); // 5x4 = 20

    for (i = 0; i < 5; i++){
        printf("Digite o valor do vetor[%d]: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("\nAqui estao os valores que voce alocou: ");
    for (i = 0; i < 5; i++){
        printf("\nValor do vetor[%d] => %d", i+1, vetor[i]);
    }
    
    free(p);
    p = NULL;

    return 0;
}

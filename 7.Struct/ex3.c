#include <stdio.h>

int i;

typedef struct{
    float x;
    float y;
    float z;
} Vetor; 

int main()
{
    
    Vetor vetor[2];

    printf("Definindo valores a serem alocados para os vetores: \n");
    for (i = 0; i < 2; i++) {
        printf("Escolha o valor para X: ");
        scanf("%f", &vetor[i].x);
        printf("Escolha o valor para Y: ");
        scanf("%f", &vetor[i].y);
        printf("Escolha o valor para Z: ");
        scanf("%f", &vetor[i].z);
    }

    vetor[2].x = vetor[0].x + vetor[1].x;
    vetor[2].y = vetor[0].y + vetor[1].y;
    vetor[2].z = vetor[0].z + vetor[1].z;

    printf("\nSoma dos vetores: ");
    printf("\nVetor x => %.2f + %.2f = %.2f", vetor[0].x, vetor[1].x, vetor[2].x);
    printf("\nVetor y => %.2f + %.2f = %.2f", vetor[0].y, vetor[1].y, vetor[2].y);
    printf("\nVetor z => %.2f + %.2f = %.2f", vetor[0].z, vetor[1].z, vetor[2].z);

    return 0;

}
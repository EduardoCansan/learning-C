#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 4

int main()
{

    int i;
    float num, soma=0;

    for (i = 0; i < TAMANHO; i++)
    {
        printf("Escolhendo o valor %d: ", i + 1);
        scanf("%f", &num);
        soma += num;    
    }

    float media = soma/TAMANHO;

    printf("\nMedia Aritimedica: %.2f", media);
    
    return 0;

}
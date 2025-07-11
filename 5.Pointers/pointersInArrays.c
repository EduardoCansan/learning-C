/*
    Faça um programa que contenha um array de inteiros contendo 5 elementos. Utilizando apenas 
    aritimética de ponteiros, leia o array do teclado e imprima o dobro de cada valor.
*/

#include <stdio.h>

int main()
{

    int i;
    int array[5];
    int *ptr = array;

    for (i = 0; i < 5; i++)
    {
        printf("Digite o valor para o vetor[%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nDobro do valor do Array: ");
    for (i = 0; i < 5; i++)
    {
        printf("\nVetor[%d]: %d", i + 1, 2 * (*(ptr + i)));

    }
    
    // 2 * (*(ptr + i))

    return 0;
}

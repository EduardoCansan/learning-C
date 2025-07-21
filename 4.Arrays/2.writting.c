/*
    Create a loop to calculate the sum of the arrays (or vectors), then print all the results.
*/

#include <stdio.h>
#define SIZE 10

int main()
{
    
    int vetor[SIZE], i;

    for (i = 0; i < SIZE; i++)
    {
        printf("Enter a value to the Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < SIZE; i++)
    {
        if(vetor[i] < 0) {
            vetor[i] = 0;
        }
        printf("\nVetor[%d] = %d", i, vetor[i]);
    }
    
    return 0;
}

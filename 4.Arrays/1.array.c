/*
    1° Create an array with 6 elements and fill it with values. 
    2° Then, add the first 3 elements together.
    3° Set the 4th element to 100.
    4° Use a for loop to print all the values.
*/

#include <stdio.h>

int main()
{

    int vetor[6];

    vetor[0] = 1;
    vetor[1] = 0;
    vetor[2] = 5;
    vetor[3] = -2;
    vetor[4] = -5;
    vetor[5] = 7;

    int sum = vetor[0] + vetor[1] + vetor[2];

    vetor[3] = 100;

    printf("Sum of the first three vetors: %d\n", sum);
    printf("\nVetor[3] = %d\n", vetor[3]);

    int i;

    for (i = 0; i < 6; i++)
    {
        printf("\nVetor[%d] = %d", i, vetor[i]);
    }

    return 0;
}
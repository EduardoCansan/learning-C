/*
    Read a number and print its multiplication table using a function or procedure.
*/

#include <stdio.h>
#define SIZE 10

int timesTable(int x) 
{
    int i;

    for (i = 1; i < SIZE + 1; i++) {
        int result = (x * i); 
        printf("%d * %d = [%d]\n", x, i, result);
    }
}

int main()
{
    
    int numero;


    printf("Choose a number: ");
    scanf("%d", &numero);
        
    
    printf("\nTimes Table of [%d]\n", numero);
    timesTable(numero);

    return 0;
}
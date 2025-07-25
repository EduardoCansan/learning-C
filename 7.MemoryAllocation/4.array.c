/*
    Write a program that uses malloc to add a user-defined number of integers to an array.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int *p, array[5], i;

    p = (int*)malloc(sizeof(array)); // 5x4 = 20

    for (i = 0; i < 5; i++){
        printf("Digit the value of Array[%d]: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nHere are the values you allocated: ");
    for (i = 0; i < 5; i++){
        printf("\nArray[%d] Value => %d", i+1, array[i]);
    }
    
    free(p);
    p = NULL;

    return 0;
}

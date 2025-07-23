/*
    Create a loop to calculate the sum of the arrays, then print all the results.
*/

#include <stdio.h>
#define SIZE 5

int main()
{
    
    int array[SIZE], i;

    for (i = 0; i < SIZE; i++)
    {
        printf("Enter a value to the array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    for (i = 0; i < SIZE; i++)
    {
        if(array[i] < 0) {
            array[i] = 0;
        }
        printf("\nArray[%d] = %d", i, array[i]);
    }
    
    return 0;
}

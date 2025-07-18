/*
    Ask the user to enter 3 numbers, then calculate and display their arithmetic mean.
*/


#include <stdio.h>
#define SIZE 3

int main()
{

    int i;
    float num, sum=0;

    for (i = 0; i < SIZE; i++)
    {
        printf("Enter a value %d: ", i + 1);
        scanf("%f", &num);
        sum += num;    
    }

    float average = sum/SIZE;

    printf("\nArithmetic Mean: %.2f", average);
    
    return 0;

}
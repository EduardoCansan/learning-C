/*
    1° Create an array with 6 elements and fill it with values. 
    2° Then, add the first 3 elements together.
    3° Set the 4th element to 100.
    4° Use a for loop to print all the values.
*/

#include <stdio.h>

int main()
{

    int array[6];

    array[0] = 1;
    array[1] = 0;
    array[2] = 5;
    array[3] = -2;
    array[4] = -5;
    array[5] = 7;

    int sum = array[0] + array[1] + array[2];

    array[3] = 100;

    printf("Sum of the first three arrays: %d\n", sum);
    printf("\nArray[3] = %d\n", array[3]);

    int i;

    for (i = 0; i < 6; i++)
    {
        printf("\nArray[%d] = %d", i, array[i]);
    }

    return 0;
}
/*
    Creates an array of integers. Using only pointer arithmetic, 
    read the values from the keyboard and print double the value of each one.
*/

#include <stdio.h>

int main()
{

    int i;
    int array[5];
    int *ptr = array;

    for (i = 0; i < 5; i++) {
        printf("Digit the array[%d] value: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nDouble value of the array: ");

    for (i = 0; i < 5; i++) {
        printf("\nArray[%d]: %d", i + 1, 2 * (*(ptr + i)));
    }
    
    // 2 * (*(ptr + i))

    return 0;
}
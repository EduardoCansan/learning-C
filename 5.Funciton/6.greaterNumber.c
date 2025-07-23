/*
    Create a function that finds the greatest value in an array provided by the user.
*/

#include <stdio.h>

int greaterValue(int num[], int size) {
    int i, greater = 0;

    for (i = 0; i < size; i++)
    {
        printf("Choose the value: ");
        scanf("%d", &num[i]);
    }

    greater = num[0];

    for (i = 0; i < size; i++)
    {
        if(num[i] > greater) {
            greater = num[i];
        }
    }

    printf("\nThe Greater Value is %d", greater);
    return greater;
    
}

int main()
{
    int size = 3;
    int array[size];

    greaterValue(array, size);
    
    return 0;
}
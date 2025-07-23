/*
    Create a function that builds a pyramid of asterisks based on the number entered by the user.
    Example: [3]
    *
    **
    ***
*/

#include <stdio.h>

int asteriskTower(int size){

    int i, j;

    for (i = 1; i < size + 1; i++) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{

    asteriskTower(10);

    return 0;
}
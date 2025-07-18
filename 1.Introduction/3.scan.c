/*
    Use scanf to let the user enter a number of their choice, then print the result.
*/

#include <stdio.h>

int main() {
   
    int number;

    printf("Digit a number: ");
    scanf("%d", &number);
    
    printf("You chose the number %d!", number);

    return 0;
}

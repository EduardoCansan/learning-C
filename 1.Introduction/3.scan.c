/*
    Use scanf to let the user enter a number of their choice, then print the result.
*/

#include <stdio.h>

int main() {
   
    int number;

    printf("Digit a number: ");
    // Scanf uses the keyboard to input something
    scanf("%d", &number);
    // first you set the type of variable
    // that insert the variable with a '&' to store the value in the variable
    
    printf("You chose the number %d", number);

    return 0;
}

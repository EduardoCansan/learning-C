/*
    Write a program that declares an int, a float, and a char, along with pointers to each of them.
    Assign each variable to its corresponding pointer.
    Then, change the values of the variables using the pointers.
    Finally, print the values before and after the changes.
*/

#include <stdio.h>

int main() {

    int integer = 10;
    float rational = 3.14;
    char character = 'A';

    // Pointers variables
    int *pInteger;
    float *pRational;
    char *pCharacter;

    // Referecing the pointers variables to the 'normal' variables 
    pInteger = &integer;
    pRational = &rational;
    pCharacter = &character;

    printf("Before modify:\n");
    printf("Integer = %d\n", integer);
    printf("Rational = %.2f\n", rational);
    printf("Character = %c\n", character);

    // Modifying values using pointers 
    *pInteger = 20;
    *pRational = 6.28;
    *pCharacter = 'B';

    printf("\nAfter Modify:\n");
    printf("Integer = %d\n", integer);
    printf("Rational = %.2f\n", rational);
    printf("Character = %c\n", character);

    return 0;
}

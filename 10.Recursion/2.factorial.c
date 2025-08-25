/*
    Write a program in C to print the Factorial using recursion.
*/

#include <stdio.h>

int factorial(int num);

int main() {

    int num = 5;
    int i;

    printf("%d! => ", num);

    // print the fatorial in other way
    for (i = num; i > 0; i--) {
        if (i > 1) {
            printf("%d x ", i);            
        }
        else {
            printf("%d ", i);
        }
    }
    
    // show the total result
    printf("\nFactorial of %d is: %d", num, factorial(num));
    
    return 0;
}

int factorial(int num) {

    if(num <= 1) {
        return num;
    }
    return num * factorial(num - 1);
}


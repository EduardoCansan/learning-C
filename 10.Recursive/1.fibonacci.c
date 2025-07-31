/*
    Write a program in C to print the Fibonacci Series using recursion.
*/

#include <stdio.h>

int fibonacci(int num) {

    if (num <= 1) {
        return num;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {

    int num, i;

    printf("Enter the number of terms: ");
    scanf("%d", &num);

    printf("\nFibonacci Sequence: \n");
    
    for (i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
    return 0;
}
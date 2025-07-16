/*
    Here, we'll look at how the ternary operator works in C.
    
    Example syntax: condition ? expression_if_true : expression_if_false;
*/

#include <stdio.h>

int main() {

    int a = 10, b = 20;
    int max, min;

    max = (a > b) ? a : b;
    min = (a < b) ? a : b;

    printf("The biggest number is: %d", max);
    printf("\nThe lowest number is: %d", min);
    return 0;
}
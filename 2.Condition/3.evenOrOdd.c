/*
    This time, check if a number is odd or even using a ternary operator.
*/

#include <stdio.h>

int main() {
    int num = 7;
    const char* result;

    result = (num % 2 == 0) ? "Even" : "Odd";

    printf("The number %d is %s",num ,result);
    return 0;
}

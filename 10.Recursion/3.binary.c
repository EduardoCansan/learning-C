/*
    Write a program in C to print the Binary of an outputted Decimal using recursion.
*/

#include <stdio.h>

int binary (int num);

int main() {

    int num = 3;

    printf("The binary of %d is: %d", num, binary(num));
    
    return 0;
}

int binary(int num) {
    if(num == 0) {
        return num;
    }
    else {
        return (num % 2 + 10 * binary(num / 2));
    }
}
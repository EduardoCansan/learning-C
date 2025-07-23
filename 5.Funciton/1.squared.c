/*
    Create a function that calculates the quadratic value of a number entered by the user.
*/

#include <stdio.h>

int squareNumber(int x) {
    return (x * x);
}

int main()
{

    int num;

    printf("Choose a number: ");
    scanf("%d", &num);

    printf("The square number of %d is %d", num, squareNumber(num));

    return 0;

}
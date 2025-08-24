/* 
    Write a program that declares two integer variables. 
    Compare their memory addresses and display which one has the higher address.
*/


#include <stdio.h>

int main()
{
    
    int A = 0;
    int B = 0;

    printf("Digit the value A: ");
    scanf("%d", &A);

    printf("Digit the value B: ");
    scanf("%d", &B);

    printf("\nMemory Address A (%p)", &A);
    printf("\nMemory Address B (%p)", &B);

    if(&A > &B) {
        printf("\nLargest memory address is and A: %p", &A);    
    
    } else {
        printf("\nLargest memory address is and B: %p", &B);
    }

    return 0;
}

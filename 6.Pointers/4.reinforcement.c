/*
    Create an integer variable, then create a pointer that points to that variable. Print the following information:
     The memory address of the integer
     The value of the pointer (which is the address it points to)
     And finally, the memory address of the pointer itself
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 10;
    int *p = &x;

    printf("\nMemory Address of X: %p", &x);
    printf("\nValue of Pointer(Memory Address that points to P): %p", p);
    printf("\nMemomory Address Pointer: %p", &p);

    return 0;
}

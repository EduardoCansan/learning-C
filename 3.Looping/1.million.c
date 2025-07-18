/*
    Create a loop that counts from 100 to one million, increasing by 100 each time.
*/

#include <stdio.h>
#define MILLION 1000000

int main()
{
    
    int number = 0;

    while (number <= MILLION) {
        printf("Number: %d\n", number);
        number += 100;
    }
    printf("You have reached the desired number 100000");
    
    return 0;
}

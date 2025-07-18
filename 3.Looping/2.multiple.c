/*
    Make a loop that starts from 0 and keeps going, finding numbers that are multiples of 3. 
    Stop after finding the first 5.
*/

#include <stdio.h>

int main()
{
    
    int num = 0, count = 0;

    while (count < 5) {
        if(num % 3 == 0) {
            printf("The number %d is a multiple of 3\n", num);
            count += 1;
        }
        num += 1;
    }
    printf("Task Finished!");
    
    return 0;
}

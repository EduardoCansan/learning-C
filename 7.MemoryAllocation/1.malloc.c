/*
    Create a malloc that allocates space for 5 integers, then print them on the screen.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    int *p = (int*) malloc(5 *sizeof(int)); //Allocate space for 5 integers (5x4) = 20
    
    // It is necessary to set a condition for p to be null.
    // ERROR: If malloc fails, p will be NULL and using p will cause a crash.
    if(p == NULL){
        printf("Error allocating memory\n");
        return 1;
    }

    for(i = 0; i < 5; i++){
        p[i]= i;
        printf("%d ", p[i]);
    }

    free(p); // Free up memory
    p = NULL; // Reset the pointer

    return 0;
}

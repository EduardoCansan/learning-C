/*
    Create a calloc that allocates space for 5 integers, then print them on the screen.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    int *p = (int*) calloc(5, sizeof(int)); // Allocate and clear space for 5 integers

    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        printf("%d ", p[i]); // All start at zero
    }

    free(p);
    return 0;
}

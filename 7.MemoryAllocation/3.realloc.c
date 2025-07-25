/*
    Use malloc to allocate memory for 3 integers and fill them.
    Then use realloc to resize the memory to hold 6 integers.
    After that, fill and print the last 3 numbers, and finally print all 6 numbers on the screen.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    int *p = (int*) malloc(3 * sizeof(int));

    if (p == NULL) {
        printf("Error allocating memory!\n");
        return 1;
    }

    // Write the first 3 values
    for (i = 0; i < 3; i++) {
        p[i] = i + 1;
    }

    // Increases the size to 6 integers
    // We must use a temporary variable to avoid memory leaks   
    int *temp = (int*) realloc(p, 6 * sizeof(int));
    if (temp == NULL) {
        printf("Error allocating memory!\n");
        free(p); // Release the old pointer
        return 1;
    }
    p = temp; // If it worked, update the pointer


    if (p == NULL) {
        printf("Error allocating memory!\n");
        return 1;
    }

    // Write the other 3 value
    for (i = 3; i < 6; i++) {
        p[i] = (i + 1) * 10;
    }

    // Print everything
    for (i = 0; i < 6; i++) {
        printf("%d ", p[i]);
    }

    free(p);
    return 0;
}

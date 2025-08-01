/*
    Write a program in C to sort an array using Shell Sort.
*/

#include <stdio.h>
#define SIZE 8

int i, j;

void shellSort(int array[], int size);

int main() {

    int array[SIZE] = {8, 9, 0, 1, 2, 4, 3, 5};

    printf("Array before Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    shellSort(array, SIZE);

    printf("\nArray after  Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;

}

void shellSort(int array[], int size) {
    
    // Auxiliary variable
    int group = 1;

    // Generate the group size according to the array size
    while (group < size) {
        group = 3 * group + 1;
    }

    // Scan the vector while having groups to sort
    while(group > 1) {

        // Divide the group into 3 parts
        group /= 3;

        // Sweep each group
        for (i = group; i < size; i++) {
            int replace = array[i];
            int j = i - group;

            // Do the replace
            while (j >= 0 && replace < array[j]) {
                array[j + group] = array[j];
                j -= group;
            }

            // Do the replace
            array[j + group] = replace;
        }
    }
}
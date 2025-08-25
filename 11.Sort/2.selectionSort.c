/*
    Write a program in C to sort an array using Selection Sort.
*/

#include <stdio.h>
#define SIZE 6

int i, j;

void selectSort(int array[], int size);

int main() {

    int array[SIZE] = {3, 2, 6, 9, 0, 1};

    printf("Array before Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    selectSort(array, SIZE);

    printf("\nArray after  Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;

}

void selectSort(int array[], int size) {
    int min, replace;

    // First looping to pass all the array
    for (i = 0; i < (size - 1); i++) {
        min = i;
        
        // Second looping to work with the next element
        for (j = (i + 1); j < size; j++) {
            
            if(array[j] < array[min]) {
                min = j;
            }
        }
        
        // Do the replace
        if (i != min) {
            replace = array[i];
            array[i] = array[min];
            array[min] = replace;
        }
    }
}
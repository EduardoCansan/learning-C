/*
    Write a program in C to sort an array using Bubble Sort.
*/

#include <stdio.h>
#define SIZE 5

void bubbleSort(int array[], int size);

int main() {

    int array[SIZE] = {5, 4, 1, 3, 2};
    int i;

    printf("Array before Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    bubbleSort(array, SIZE);

    printf("\nArray after  Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;

}

void bubbleSort(int array[], int size) {

    int i, j, temp, swapped;

    for (i = 0; i < size - 1; i++) {
        
        swapped = 0;  // Flag to optimize if the array is already sorted

        for (j = 0; j < size - i - 1; j++) {

            // Swap if the current element is greater than the next
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }

        // If no two elements were swapped in inner loop, array is sorted
        if (swapped == 0)
            break;
    }
    
}
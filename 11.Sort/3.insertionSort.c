/*
    Write a program in C to sort an array using Insertion Sort.
*/

#include <stdio.h>
#define SIZE 7

int i, j;

void insertSort(int array[], int size);

int main() {

    int array[SIZE] = {10, 20, 60, 90, 30, 50, 40};

    printf("Array before Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    insertSort(array, SIZE);

    printf("\nArray after  Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;

}

void insertSort(int array[], int size) {
    int replace;

    // Travels the entire array
    for (i = 1; i < size; i++) {
        int next = i;
        
        
        // Responsible for the replacement
        while((next != 0) && (array[next] < array[next - 1])) {
            replace = array[next];
            array[next] = array[next - 1];
            array[next - 1] = replace;
            next --;
        }
    }
}
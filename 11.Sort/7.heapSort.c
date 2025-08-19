/*
    Write a program in C to sort an array using Heap Sort.
*/

#include <stdio.h>
#define SIZE 5

int i;

void swap(int *a, int *b);
void heapify(int array[], int size, int i);
void heapSort(int array[], int size);

int main() {

    int array[SIZE] = {3, 15, 9, 1, 27};

    printf("Array before Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    heapSort(array, SIZE);

    printf("\nArray after  Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int size, int i) {
    int largest = i;      
    int left = 2 * i + 1; 
    int right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

void heapSort(int array[], int size) {
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (i = size - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}
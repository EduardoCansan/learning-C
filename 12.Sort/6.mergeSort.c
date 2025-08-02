/*
    Write a program in C to sort an array using Merge Sort.
*/

#include <stdio.h>
#define SIZE 6

int i, j, k;

void merge(int array[], int left, int mid, int right);
void mergeSort(int array[], int left, int right);


int main() {

    int array[SIZE] = {5, 25, 15, 0, 10, 20};

    printf("Array before Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    mergeSort(array, 0, SIZE - 1);

    printf("\nArray after  Sort: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void merge(int array[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[SIZE]; 
    // int temp[100]; // assumes max size is 100 or less 


    while (i <= mid && j <= right) {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid) {
        temp[k++] = array[i++];
    }

    while (j <= right) {
        temp[k++] = array[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) { 
        array[i] = temp[k];
    }

}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}
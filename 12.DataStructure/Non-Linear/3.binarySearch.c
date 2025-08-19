/*
    Write a program in C to create a Binary Search
*/

#include <stdio.h>
#define SIZE 20

int binarySearch(int array[], int key, int size);

int main() {

    int array[SIZE] = {1, 4, 7, 8, 10, 14, 19, 21, 25, 26, 27, 30, 40, 41, 43, 37, 51, 53, 55, 58};

    int key = 53;

    binarySearch(array, key, SIZE);

    return 0;
}

int binarySearch(int array[], int key, int size) {
    int start = 0;
    int end = size - 1;
    int step = 0;

    while(start <= end) {
        
        step++;
        
        // Find the mid of array
        int mid = (start + end) / 2;

        // if key is in the middle
        if(key == array[mid]) {
            printf("The element %d is in position %d and took %d steps.", key, mid, step);
            return mid;
        }

        if(key < array[mid]) {
            end = mid - 1;
        
        } else {
            start = mid + 1;
        }
    }

    printf("The element %d is not in the list, %d steps taken.", key, step);
    return -1;
}
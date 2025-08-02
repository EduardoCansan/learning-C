#include <stdio.h>
#define SIZE 20

int binarySearch(int array[], int key, int size);

int main() {
 
    int array[SIZE] = {1, 4, 7, 8, 10, 14, 19, 21, 25, 26, 27, 30, 40, 41, 43, 37, 51, 53, 55, 58};
    
    int key = 53;

    int ret = binarySearch(array, key, SIZE);

    printf("The element %d it is in position %d", key, (ret + 1));

    return 0;
}

int binarySearch(int array[], int key, int size) {
    int start = 0;
    int end = size - 1;

    while(start <= end) {
        // Find the mid of array
        int mid = (start + end) / 2;

        // if key is in the middle
        if(key == array[mid]) {
            return mid;
        }

        if(key < array[mid]) {
            end = mid - 1;
        
        } else {
            start = mid + 1;
        }
    }

    return -1;
}
/*
    Write a program in C to create a Linear Search
*/

#include <stdio.h>
#define SIZE 20

int linearSearch(int array[], int key, int size);

int main() {

    int array[SIZE] = {1, 4, 7, 8, 10, 14, 19, 21, 25, 26, 27, 30, 40, 41, 43, 37, 51, 53, 55, 58};

    int key = 53;

    linearSearch(array, key, SIZE);

    return 0;
}

int linearSearch(int array[], int key, int size) {
    int i;
    int step = 0;

    for(i = 0; i < size; i++) {
        step++;
        if(array[i] == key) {
            printf("The element %d is in position %d and took %d steps.", key, i, step);
            return i;
        }
    }

    printf("The element %d is not in the list, %d steps taken.", key, step);
    return -1;
}
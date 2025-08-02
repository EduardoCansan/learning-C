#include <stdio.h>
#define SIZE 20

int linearSearch(int array[], int key, int size);

int main() {
 
    int array[SIZE] = {1, 4, 7, 8, 10, 14, 19, 21, 25, 26, 27, 30, 40, 41, 43, 37, 51, 53, 55, 58};
    
    int key = 53;

    int ret = linearSearch(array, key, SIZE);

    printf("The element %d it is in position %d", key, (ret + 1));

    return 0;
}

int linearSearch(int array[], int key, int size) {
    int i;

    for(i = 0; i < size; i++) {
        if(array[i] == key) {
            return i;
        }
    }

    return -1;
}
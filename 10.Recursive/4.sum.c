#include <stdio.h>

int recursiveSum(int num);

int main() {

    int num = 5;

    printf("The sum of the first %d numbers is: %d", num, recursiveSum(num));
    
    return 0;
}

int recursiveSum(int num) {
    if(num <= 1) {
        return num;
    }
    return num + recursiveSum(num - 1);
}


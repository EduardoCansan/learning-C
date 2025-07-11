#include <stdio.h>

int binario(int num);

int main() {

    int num = 5;

    printf("Binario de %d e: %d", num, binario(num));
    
    return 0;
}

int binario(int num) {
    if(num == 0) {
        return num;
    }
    else {
        return (num % 2 + 10 * binario(num / 2));
    }
}


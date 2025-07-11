#include <stdio.h>

int fatorial(int num);

int main() {

    int num = 5;

    printf("Fatorial de %d e: %d", num, fatorial(num));
    
    return 0;
}

int fatorial(int num) {
    if(num <= 1) {
        return num;
    }
    return num * fatorial(num - 1);
}


#include <stdio.h>

int somaRecursiva(int num);

int main() {

    int num = 5;

    printf("A soma no %d primeiros numero e: %d", num, somaRecursiva(num));
    
    return 0;
}

int somaRecursiva(int num) {
    if(num <= 1) {
        return num;
    }
    return num + somaRecursiva(num - 1);
}


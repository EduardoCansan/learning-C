/*
    Mais um exemplo do Operador Ternário.
    Dessa vez para verificar se o número é ímpar ou par.
*/

#include <stdio.h>

int main() {
    int num = 7;
    const char* result;

    result = (num % 2 == 0) ? "Par" : "Impar";

    printf("O numero %d e %s",num ,result);
    return 0;
}

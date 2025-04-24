/*
    Aqui vamos avaliar a Operação Ternária em C
    Exemplo da Syntax: condition ? expression_if_true : expression_if_false;
*/

#include <stdio.h>

int main() {

    int a = 10, b = 20;
    int max, min;

    max = (a > b) ? a : b;
    min = (a < b) ? a : b;


    printf("O maior numero: %d", max);
    printf("\nO menor numero: %d", min);
    return 0;
}
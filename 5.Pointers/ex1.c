#include <stdio.h>

int main() {

    int inteiro = 10;
    float decimal = 3.14;
    char caractere = 'A';

    int *pInteiro;
    float *pDecimal;
    char *pCaractere;

    pInteiro = &inteiro;
    pDecimal = &decimal;
    pCaractere = &caractere;

    // Impressão dos valores originais
    printf("Antes da modificacao:\n");
    printf("inteiro = %d\n", inteiro);
    printf("decimal = %.2f\n", decimal);
    printf("caractere = %c\n", caractere);

    // Modificação dos valores usando os ponteiros
    *pInteiro = 20;
    *pDecimal = 6.28;
    *pCaractere = 'B';

    // Impressão dos valores após a modificação
    printf("\nApos a modificacao:\n");
    printf("inteiro = %d\n", inteiro);
    printf("decimal = %.2f\n", decimal);
    printf("caractere = %c\n", caractere);

    return 0;
}

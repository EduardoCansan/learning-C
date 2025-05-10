/*
    Faça um programa que declare um inteiro, um float e um char, e ponteiros para inteiro, float e char.
    Associe as variáveis aos ponteiros. Modifique os valores das variáveis usando os ponteiros.
    Por fim imprimas os valores das variáveis antes e depois da mudança.
*/

#include <stdio.h>

int main()
{
    
    int inteiro = 1;
    float real = 1.1;
    char character = 'a';

    int* pInteiro;
    float* pReal;
    char* pCharacter;

    printf("Antes da mudanca: S");
    printf("\nInteiro: %d", inteiro);
    printf("\nFloat: %.2f", real);
    printf("\nChar: %c\n", character);

    pInteiro = &inteiro;
    pReal = &real;
    pCharacter = &character;

    *pInteiro = 2;
    *pReal = 2.2;
    *pCharacter = 'A';

    printf("\nDepois da mudanca: ");
    printf("\nInteiro: %d", inteiro);
    printf("\nFloat: %.2f", real);
    printf("\nChar: %c", character);

    return 0;
}
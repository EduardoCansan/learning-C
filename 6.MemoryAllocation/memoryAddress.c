/*
    Faça um programa que contenha duas variáveis inteiras. Leia estas variáveis do teclado.
    Em seguida compare os endereços de memória e exiba o conteúdo com maior endereço.
*/

#include <stdio.h>

int main()
{

    int num1=0, num2=0;

    printf("Digite o valor da Variavel A: ");
    scanf("%d", &num1);

    printf("Digite o valor da Variavel B: ");
    scanf("%d", &num2);

    if(&num1 > &num2) {
        printf("Endereco de memoria da variavel A e maior: %p", num1);
    }
    else {
        printf("Endereco de memoria da variavel B e maior: %p", num2);
    }

    return 0;
}

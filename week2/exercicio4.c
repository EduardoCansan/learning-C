/*
    4 - Leia um número entre 4 e 8 e imprima a tabuada desse número (utilizar funções ou procedimento)
*/

#include <stdio.h>
#define TAMANHO 10

int i;

int tabuadaDoNumero(int x)
{
    for (i = 1; i < TAMANHO + 1; i++) {
        int resultado = (x * i); 
        printf("%d * %d = [%d]\n", x, i, resultado);
    }
}

int main()
{
    
    int numero;

    do {
        printf("\nEscolha um numero entre 4 e 8: ");
        scanf("%d", &numero);
        
    } while (numero < 4 || numero > 8);
    
    printf("Tabuada do %d: \n", numero);
    tabuadaDoNumero(numero);

    return 0;
}
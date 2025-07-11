#include <stdio.h>

int main()
{
    
    int valorA = 0;
    int valorB = 0;

    printf("Digite o valor 1: ");
    scanf("%d", &valorA);

    printf("Digite o valor 2: ");
    scanf("%d", &valorB);

    if(&valorA > &valorB) {
        printf("Maior endereco e A: %p", &valorA);    
    }
    else {
        printf("\nMaior endereco e B: %p", &valorB);
    }

    return 0;
}

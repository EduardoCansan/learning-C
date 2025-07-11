#include <stdio.h>

int main()
{
    
    int i, numero = 0, maior_valor, menor_valor;

    for (i = 0; i < 10; i++)
    {
        printf("Digite um valor: ");
        scanf("%d",  &numero);

        if(i == 0) {
            menor_valor = numero;
            maior_valor = numero;
        }
        else {

            if(numero < menor_valor) 
            {
                menor_valor = numero;
            }
            else if (numero >= maior_valor)
            {
                maior_valor = numero;
            }
        }
    }

    printf("\nMenor valor: %d", menor_valor);
    printf("\nMaior valor: %d", maior_valor);
    
    return 0;
}
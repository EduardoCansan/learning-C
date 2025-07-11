/*
2 - Escreva um algoritmo para ler o número total de eleitores de um município, o número de votos brancos, nulos e válidos.
	Calcular e escrever o percentual que cada um representa em relação ao total de eleitores.
*/

#include <stdio.h>
#include <conio.h>
#define TAMANHO 10

float calcularPorcentagem(int votos, int total)
{
    return (votos * 100.0) / total;
}

int main()
{
    
    int option, valido = 0, branco = 0, nulo = 0;
    
    printf("Faca %d votos confome as opcoes abaixo\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++)
    {
        
        printf("\nVoce quer fazer um voto: \n1. Valido\n2. Branco\n3. Nulo\n");
        printf("\n%dº Voto: ", i + 1);
        scanf("%d", &option);

        if (option == 1)
        {
            printf("Você fez um voto Valido\n");
            valido ++;
        }
        else if (option == 2)
        {
            printf("Você fez um voto em Branco\n");
            branco ++;
        }
        else if (option == 3)
        {
            printf("Você votou nulo\n");
            nulo ++;
        }
        else 
        {
            printf("Opcao Invalida! Escolha uma opção que exista\n");
            i --;
        }

    }
    
    printf("\nObrigado por votar!");
    printf("\nAqui estao as porcentagens dos votos:");
    printf("\nVALIDOS = %.1f%%", calcularPorcentagem(valido, TAMANHO));
    printf("\nBRANCOS = %.1f%%", calcularPorcentagem(branco, TAMANHO));
    printf("\nNULOS = %.1f%%", calcularPorcentagem(nulo, TAMANHO));
    
    return 0;
}
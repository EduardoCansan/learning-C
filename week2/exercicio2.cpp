/*
2 - Escreva um algoritmo para ler o número total de eleitores de um município, o número de votos brancos, nulos e válidos.
	Calcular e escrever o percentual que cada um representa em relação ao total de eleitores.
*/

#include <stdio.h>
#include <conio.h>
#include <cstdio>

int main()
{
    
    int option, validos = 0, branco= 0, nulo= 0;

    for (int i = 0; i < 10; i++)
    {
        
        printf("Voce quer fazer um voto: \n1. Valido\n2. Branco\n3. Nulo\n");
        scanf("%s", &option);

        switch (option)
        {
        case 1:
            validos = validos + 1;
            printf("\nVoto Valido");
            break;
        
        case 2:
            branco = branco + 1;
            printf("\nVoto em Branco");
            break;

        case 3:
            nulo = nulo + 1;
            printf("\nVotou Nulo");
            break;
            
    }

    }
    
    return 0;
}
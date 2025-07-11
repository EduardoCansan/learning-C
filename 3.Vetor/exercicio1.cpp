/*
1) Faca um programa que alimente um vetor com 10 inteiros, calcule e mostre a quantidade de numeros positivos e negativos 
   e a soma de cada um deles. 
*/
#include <stdio.h>
#define TAMANHO 10

int main() {

    // Setando as variaveis  
    int numeros[TAMANHO];
    int positivos = 0, negativos = 0;
    int soma_negativos = 0, soma_positivos = 0;
    
    // Looping para escrever os 10 valores pedidos
    printf("Escolha 10 numeros: \n");
    for (int i =0; i < TAMANHO; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    // Verifica quais são positivos e quais são negativos
    for (int i =0; i < TAMANHO; i++)
    {
        if (numeros[i] < 0)
        {
            soma_negativos += numeros[i];
            negativos++;
        }
        else if (numeros[i] > 0) 
        {
            soma_positivos += numeros[i];
            positivos++;
        }
        
    }
    
    // Output da lógica
    printf("\nTotal de numeros positivos: %d\n", positivos);
    printf("Total de numeros negativos: %d\n", negativos);
    printf("Soma dos numeros positivos: %d\n", soma_positivos);
    printf("Soma dos numeros negativos: %d\n", soma_negativos);
    
    return 0;
    
}
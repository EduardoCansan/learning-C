/*
2) Faca um programa que alimente dois vetor com 10 inteiros, calcule a soma, multiplicação, subtração e divisão 
   de um vetor pelo outro da seguinte forma
   - Vetor1[0] + Vetor2[9]
   - Vetor1[0] - Vetor2[9]   
   - Vetor1[0] * Vetor2[9]   
   - Vetor1[0] / Vetor2[9]   
   
   - Vetor1[1] + Vetor2[8]
   - Vetor1[1] - Vetor2[8]   
   - Vetor1[1] * Vetor2[8]   
   - Vetor1[1] / Vetor2[8]   
   ....
*/

#include <stdio.h>
#define TAMANHO 10

int main() {

    int vetorUm[TAMANHO];
    int vetorDois[TAMANHO];
    
    // Looping para escrever os 10 valores do vetor 1
    printf("Escolha 10 numeros do vetor 1: \n");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetorUm[i]);
    }
    
    // Looping para escrever os 10 valores do vetor 2
    printf("\nEscolha 10 numeros do vetor 2: \n");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetorDois[i]);
    }
    
    for (int i = 0; i < TAMANHO; i++)
    {
        // Pega o tamanho e diminui 1, depois pega o valor inverso de i
        int j = TAMANHO - 1 - i;
        
        // Lógica das Equações Matemáticas
        int somaVetores = vetorUm[i] + vetorDois[j];
        int subVetores = vetorUm[i] - vetorDois[j];
        int multVetores = vetorUm[i] * vetorDois[j];

        // Output das equações matemáticas
        printf("\nVetor[%d] e Vetor[%d]", vetorUm[i - 1], vetorDois[j - 1]);
        printf("\nSOMA: %d", somaVetores);
        printf("\nSUBRTRACAO: %d", subVetores);
        printf("\nMULTIPLICACAO: %d", multVetores);
        
        // Tratamento para divisão por zero e divisao 
        if(vetorDois[j] != 0) 
        {
            float divVetores = (float)vetorUm[i] / vetorDois[j];
            printf("\nDIVISAO: %.2f\n", divVetores);
        } else 
        {
            printf("\nDivisao Por Zero\n");
        }

    }
    
    return 0;
    
}
/*
    Write a program that fills two arrays with 10 integers each.
    Then, perform and display the sum, subtraction, multiplication, and division between the elements of 
    both arrays in reverse order like this:
    
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
#define SIZE 3

int main() {

    int vetorOne[SIZE];
    int vetorTwo[SIZE];
    int i;

    printf("Choose %d numbers [VETOR 1]: \n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &vetorOne[i]);
    }
    
    printf("\nChoose %d numbers [VETOR 2]: \n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &vetorTwo[i]);
    }
    
    for (i = 0; i < SIZE; i++)
    {

        // Get the SIZE, subtract 1, then use the reverse index of i
        int j = SIZE - 1 - i;
        
        // Logic behind the mathematical operations
        int sumVetores = vetorOne[i] + vetorTwo[j];
        int subVetores = vetorOne[i] - vetorTwo[j];
        int multVetores = vetorOne[i] * vetorTwo[j];

        printf("\nVetor[%d] e Vetor[%d]", vetorOne[i - 1], vetorTwo[j - 1]);
        printf("\nSUM: %d", sumVetores);
        printf("\nSUBTRACTION: %d", subVetores);
        printf("\nMULTIPLICATION: %d", multVetores);
        
        // Handling division by zero and division in general
        if(vetorTwo[j] != 0) 
        {
            float divVetores = (float)vetorOne[i] / vetorTwo[j];
            printf("\ndDIVISION: %.2f\n", divVetores);
        } else 
        {
            printf("\nDIVISION BY ZERO\n");
        }

    }
    
    return 0;
    
}
/*
    Write a program that fills two arrays with 10 integers each.
    Then, perform and display the sum, subtraction, multiplication, and division between the elements of 
    both arrays in reverse order like this:
    
    - Array1[0] + Array2[9]
    - Array1[0] - Array2[9]   
    - Array1[0] * Array2[9]   
    - Array1[0] / Array2[9]   

    - Array1[1] + Array2[8]
    - Array1[1] - Array2[8]   
    - Array1[1] * Array2[8]   
    - Array1[1] / Array2[8]   
    ....
*/

#include <stdio.h>
#define SIZE 3

int main() {

    int arrayOne[SIZE];
    int arrayTwo[SIZE];
    int i;

    printf("Choose %d numbers [ARRAY 1]: \n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &arrayOne[i]);
    }
    
    printf("\nChoose %d numbers [ARRAY 2]: \n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &arrayTwo[i]);
    }
    
    for (i = 0; i < SIZE; i++)
    {

        // Get the SIZE, subtract 1, then use the reverse index of i
        int j = SIZE - 1 - i;
        
        // Logic behind the mathematical operations
        int sumArray = arrayOne[i] + arrayTwo[j];
        int subArray = arrayOne[i] - arrayTwo[j];
        int multArray = arrayOne[i] * arrayTwo[j];

        printf("\nArray[%d] e Array[%d]", arrayOne[i - 1], arrayTwo[j - 1]);
        printf("\nSUM: %d", sumArray);
        printf("\nSUBTRACTION: %d", subArray);
        printf("\nMULTIPLICATION: %d", multArray);
        
        // Handling division by zero and division in general
        if(arrayTwo[j] != 0) 
        {
            float divArray = (float)arrayOne[i] / arrayTwo[j];
            printf("\nDIVISION: %.2f\n", divArray);
        } else 
        {
            printf("\nDIVISION BY ZERO\n");
        }

    }
    
    return 0;
    
}
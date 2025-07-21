/*
    Write a program that fills an array with 10 integers.
    Then, calculate and display how many of them are positive and how many are negative, along with the sum of each group.
*/
#include <stdio.h>
#define SIZE 3

int main() {

    int numbers[SIZE];
    int positive = 0, negatives = 0;
    int sum_negatives = 0, sum_positive = 0;
    int i;
    
    printf("Choose %d numbers: \n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    
    for (i = 0; i < SIZE; i++)
    {
        if (numbers[i] < 0)
        {
            sum_negatives += numbers[i];
            negatives++;
        }
        else if (numbers[i] > 0) 
        {
            sum_positive += numbers[i];
            positive++;
        }
        
    }
    
    // Output da lógica
    printf("\nTotal Positive numbers: %d\n", positive);
    printf("Total Negative numbers: %d\n", negatives);
    printf("\nSum Positive numbers: %d\n", sum_positive);
    printf("Sum Negative numbers: %d\n", sum_negatives);
    
    return 0;
    
}
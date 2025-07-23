/*
    Write an algorithm that reads the total number of voters in a city, 
    along with the number of blank, null, and valid votes.
    Calculate and display the percentage each type of vote represents compared to the total number of voters.
*/

#include <stdio.h>
#define SIZE 5

int i;

float calculatePercentage(int votes, int total)
{
    return (votes * 100.0) / total;
}

int main()
{
    
    int option, valid = 0, blank = 0, null  = 0;
    
    printf("Vote %d times following the options\n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        
        printf("\nWhat tipe of vote do you want: \n1. Valid\n2. Blank\n3. Null \n");
        printf("\nOption [%d]: ", i + 1);
        scanf("%d", &option);

        if (option == 1)
        {
            printf("Valid vote choosen!\n");
            valid ++;
        }
        else if (option == 2)
        {
            printf("Blank choosen!\n");
            blank ++;
        }
        else if (option == 3)
        {
            printf("Null choosen!\n");
            null  ++;
        }
        else 
        {
            printf("Invalid option, try again!!!\n");
            i --;
        }

    }
    
    printf("\nThank you for voting!");
    printf("\nHere is the percentage of your votes:");
    printf("\nValid = %.1f%%", calculatePercentage(valid, SIZE));
    printf("\nBlank = %.1f%%", calculatePercentage(blank, SIZE));
    printf("\nNull = %.1f%%", calculatePercentage(null , SIZE));
    
    return 0;
}
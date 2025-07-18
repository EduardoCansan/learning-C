/*
    Create a loop that lets the user input several numbers. 
    At the end, print the highest and the lowest values entered.
*/

#include <stdio.h>

int main()
{
    
    int i, value = 0, greater_value, lowest_value;

    for (i = 0; i < 5; i++)
    {
        printf("Enter a Value: ");
        scanf("%d",  &value);

        if(i == 0) {
            lowest_value = value;
            greater_value = value;
        }
        else {

            if(value < lowest_value) {
                lowest_value = value;
            
            } else if (value >= greater_value) {
                greater_value = value;
            }
        }
    }

    printf("\nLowest Value: %d", lowest_value);
    printf("\nGreater value: %d", greater_value);
    
    return 0;
}
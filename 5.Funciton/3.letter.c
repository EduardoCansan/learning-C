/*
    Create a function that takes a character input from the user and converts it to uppercase.
*/

#include <stdio.h>

int uppercaseCharacter(char letter){
    
    char uppercase;

    uppercase = (letter - 32);

    printf("Character: %c\n", letter);
    printf("Uppercase: %c\n", uppercase);

    return uppercase;

}

int main()
{

    uppercaseCharacter('c');

    return 0;
}

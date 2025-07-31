/*
    Declare the necessary variables to do the following:
    Ask the user for the name of the file (in this example: "file.txt").
    Then, ask for a character the user wants to search for inside that file.
    Read through the file and count how many times that character appears.
    Finally, print the total number of times the chosen character was found.
*/

#include <stdio.h>
#define SIZE 9

int main() {

    FILE *file;
    char nome_fileuivo[SIZE];
    char character = 0;
    char c;
    int character_counter = 0;

    printf("Enter the name of the file to be opened: ");
    fgets(nome_fileuivo, SIZE, stdin);

    printf("Enter the character to be searched: ");
    scanf(" %c", &character);

    file = fopen(nome_fileuivo, "r");

    if(file) {
        for (c = getc(file); c != EOF; c = getc(file)) {
            if(c == character) {
                character_counter += 1;
            }
        }
        printf("There are %d characters in the file %s", character_counter, nome_fileuivo);
        
    } else {
        printf("Unable to open file");
    }
    
    fclose(file);
    file = NULL;

    return 0;
}

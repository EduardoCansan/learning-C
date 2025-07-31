/*
    This folder contains two files. Use "file.txt" to complete the following steps:
    Declare two pointers of type FILE: one called *fileWrite for writing, and another called *fileRead for reading.
    Use a loop to input one character at a time from the keyboard. Keep going until the user types '0' to exit.
    After the input ends, print the full word that was written.
*/

#include <stdio.h>

int main()
{
    
    // Declaring two pointers of type FILE
    FILE *fileWrite, *fileRead;
    char character = 'A';
    
    // Write the file
    fileWrite = fopen("file.txt", "w");
    
    // Looping to write the characters
    if(fileWrite) {
        while(character != '0') {
            printf("Enter ONE character or 0 to exit: ");
            scanf(" %c", &character);
        
            if(character != '0') {
                fputc(character, fileWrite);
            }
        }
    }
    else {
        printf("File not found");
    }

    fclose(fileWrite); // Free up memory
    fileWrite = NULL; // Reset the pointer

    fileRead = fopen("file.txt", "r");

    // Looping to print the characters
    if(fileRead) {
        while ((character = getc(fileRead)) != EOF) {
            printf("%c ", character);
        }
    }
    else {
        printf("Could not open the file");
    }
    
    fclose(fileRead);
    fileRead = NULL;

    return 0;
}
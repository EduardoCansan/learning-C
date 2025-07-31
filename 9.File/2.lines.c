/*
    Declare a FILE *file to open and read the other file "names.txt".
    Use a loop to read through the file line by line.
    Count how many lines are in the file and print the result at the end.
*/

#include <stdio.h>
#define SIZE 10

int main() {

    FILE *file;
    char file_name[SIZE]; // names.txt [9 + 1 (by default)] = [1] 
    int lines = 0;
    char c;

    printf("Enter the name of the file to be opened: ");
    fgets(file_name, SIZE, stdin);

    file = fopen(file_name, "r");
    if(file){
        for(c = getc(file); c != EOF; c = getc(file)) {
            if(c == '\n') {
                lines += 1;
            }
        }
        printf("The %s file has %d lines", file_name, lines);
    }
    else {
        printf("Could not open the file");
    }

    fclose(file);
    file = NULL;

    return 0;

}
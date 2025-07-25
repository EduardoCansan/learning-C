/*
    Create a program where you allocate a certain amount of memory for a string.
    Then let the user type in a word, and finally rewrite that word removing all vowels.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    char *p;

    printf("Enter the size of the word to be entered: ");
    scanf("%d", &size); 
    getchar(); 

    p = (char *)malloc(sizeof(char) * (size + 1));

    if (p == NULL) {
        printf("Error allocating memory!\n");
        return 1;
    }

    printf("Choose a word: ");
    fgets(p, size + 1, stdin);

    printf("String without vowels: ");
    for (i = 0; p[i] != '\0'; i++) {
        char c = p[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            printf("%c", c);
        }
    }

    free(p);
    p = NULL;

    return 0;
}

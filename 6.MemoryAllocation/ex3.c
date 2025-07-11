#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho, i;
    char *p;

    printf("Informe o tamanho da String a ser informada: ");
    scanf("%d", &tamanho); 
    getchar(); 

    p = (char *)malloc(sizeof(char) * (tamanho + 1));

    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Informe a string: ");
    fgets(p, tamanho + 1, stdin);

    printf("String sem vogais: ");
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

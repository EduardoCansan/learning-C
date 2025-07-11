#include <stdio.h>

int main()
{
    
    FILE *arqWrite, *arqRead;
    char caractere = 'A';
    
    arqWrite = fopen("arq.txt", "wa");
    
    if(arqWrite) {
        while(caractere != '0') {
            printf("Informe um caractere ou 0 para sair: ");
            scanf(" %c", &caractere);
        
            if(caractere != '0') {
                fputc(caractere, arqWrite);
            }
        }
    }
    else {
        printf("Arquivo nao encontrado");
    }

    fclose(arqWrite);
    arqWrite = NULL;

    arqRead = fopen("arq.txt", "r");

    if(arqRead) {
        while ((caractere = getc(arqRead)) != EOF) {
            printf("%c ", caractere);
        }
    }
    else {
        printf("Nao foi possivel abrir o arquivo");
    }
    
    fclose(arqRead);
    arqRead = NULL;

    return 0;
}
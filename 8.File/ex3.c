#include <stdio.h>

int main(int argc, char const *argv[])
{

    FILE *arq;
    char nome_arquivo[12];
    char caractere = 0;
    char c;
    int conta_caractere = 0;

    printf("Informe o nome do arquivo a ser aberto: ");
    fgets(nome_arquivo, 12, stdin);

    printf("Informe o caractere a ser pesquiasdo: ");
    scanf(" %c", &caractere);

    arq = fopen(nome_arquivo, "r");

    if(arq) {
        for (c = getc(arq); c != EOF; c = getc(arq)) {
            if(c == caractere) {
                conta_caractere += 1;
            }
        }
        printf("Ha %d caracteres no arquivo %s", conta_caractere, nome_arquivo);
        
    }
    else {
        printf("Nao foi possivel abrir o arquivo");
    }
    
    fclose(arq);
    arq = NULL;

    return 0;
}

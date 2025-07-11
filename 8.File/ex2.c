#include <stdio.h>

int main() {

    FILE *arq;
    char nome_arquivo[12]; // arquivo.txt [11 + 1 (por apadrao)] = [12] 
    int lines = 0;
    char c;

    printf("Informe o nome do arquivo a ser aberto: ");
    fgets(nome_arquivo, 12, stdin);

    arq = fopen(nome_arquivo, "r");
    if(arq){
        for(c = getc(arq); c != EOF; c = getc(arq)) {
            if(c == '\n') {
                lines += 1;
            }
        }
        printf("O arquivo %s possui %d linhas", nome_arquivo, lines);
    }
    else {
        printf("Nao foi possivel abrir o arquivo");
    }

    fclose(arq);
    arq = NULL;

    return 0;

}
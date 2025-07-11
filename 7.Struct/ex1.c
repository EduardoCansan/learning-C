#include <stdio.h>
#define TAMANHO 3

int i;

typedef struct {
    char nome[50];
    int idade;
    char endereco[100];

} Pessoas;

int main(int argc, char const *argv[])
{

    Pessoas pessoa[TAMANHO];

    printf("Criando nossas pessoas:");

    for (i = 0; i < TAMANHO; i++) {
        printf("\nDigite o nome da %d pessoa: ", i + 1);
        scanf("%s", &pessoa[i].nome);
        printf("Digite a idade da %d pessoa: ", i + 1);
        scanf("%d", &pessoa[i].idade);
        printf("Digite o endereco da %d pessoa: ", i + 1);
        scanf("%s", &pessoa[i].endereco);
    }

    printf("\nDados das pessoas: ");
    for (i = 0; i < TAMANHO; i++)
    {
        printf("\nNome da %d pessoa: %s", i+1, pessoa[i].nome);
        printf("\nIdade da %d pessoa: %d", i+1, pessoa[i].idade);
        printf("\nEndereco da %d pessoa: %s\n", i+1, pessoa[i].endereco);
    }
    
    return 0;
}
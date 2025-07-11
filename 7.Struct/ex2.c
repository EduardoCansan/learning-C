#include <stdio.h>
#define TAMANHO 5

int i;

typedef struct {
    char nome[50];
    char matricula[10];
    char curso[50];

} Aluno;

int main()
{

    Aluno aluno[TAMANHO];

    printf("Colocando os dados do aluno:");

    for (i = 0; i < TAMANHO; i++) {
        printf("\nDigite o nome do aluno %d: ", i + 1);
        scanf("%s", &aluno[i].nome);
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%s", &aluno[i].matricula);
        printf("Digite o o curso do aluno %d: ", i + 1);
        scanf("%s", &aluno[i].curso);
    }

    printf("\nDados das pessoas: ");
    for (i = 0; i < TAMANHO; i++)
    {
        printf("\nNome do aluno %d: %s", i+1, aluno[i].nome);
        printf("\nMatricula do aluno %d: %s", i+1, aluno[i].matricula);
        printf("\nCurso do aluno %d: %s\n", i+1, aluno[i].curso);
    }

    return 0;
}
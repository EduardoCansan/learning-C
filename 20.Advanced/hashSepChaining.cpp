#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
const int TABLE_SIZE = 8;

struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct hashNode
{
    struct aluno data;
    struct hashNode *next;
} HashNode;

typedef struct hash
{
    int TABLE_SIZE;
    int qtd;
    HashNode **itens;
} Hash;

Hash *createHash()
{
    Hash* ha = (Hash *) malloc(sizeof(Hash));
    if(ha != NULL)
    {
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (HashNode **) malloc(TABLE_SIZE * sizeof(HashNode *));

        if (ha->itens == NULL)
        {
            free(ha);
            return NULL;
        }

        ha->qtd = 0;
        for (int i = 0; i < ha->TABLE_SIZE; i++)
        {
            ha->itens[i] = NULL;
        }
    }

    return ha;
}

void deleteHash(Hash *ha)
{
    if (ha == NULL) return;

    for (int i = 0; i < ha->TABLE_SIZE; i++)
    {
        HashNode *current = ha->itens[i];
        while (current != NULL)
        {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(ha->itens);
    free(ha);
}

int divisionMethod(int chave)
{
    return chave % TABLE_SIZE;
}

// Insere um aluno
int insert_SeparateChaining(Hash *ha, struct aluno al)
{
    if (ha == NULL) return 0;

    int pos = divisionMethod(al.matricula);

    // Cria um novo nodo para o alunot
    HashNode *newNode = (HashNode *) malloc(sizeof(HashNode));
    if (newNode == NULL) return 0;

    newNode->data = al;
    newNode->next = ha->itens[pos];  // Insere no início da lista encadeada
    ha->itens[pos] = newNode;
    ha->qtd++;

    return 1;
}

// Função para procurar por um aluno a partir de sua matrícula
int search_SeparateChaining(Hash *ha, int mat, struct aluno *al)
{
    if (ha == NULL) return 0;

    int pos = divisionMethod(mat);
    HashNode *current = ha->itens[pos];

    // Percorre a lista encadeada do índice específico
    while (current != NULL)
    {
        if (current->data.matricula == mat)
        {
            *al = current->data;
            return 1;
        }
        current = current->next;
    }

    return 0;
}

// Imprime nossa HashTable
void printHash(Hash *ha)
{
    printf("HASH TABLE:\n");
    if (ha == NULL) return;

    for (int i = 0; i < ha->TABLE_SIZE; i++)
    {
        printf("[%d]: ", i);
        HashNode *current = ha->itens[i];
        while (current != NULL)
        {
            printf("-> [%d, %s] ", current->data.matricula, current->data.nome);
            current = current->next;
        }
        printf("\n");
    }
    printf("\n");
}

// Implementação do createHashFull
Hash* createHashFull(struct aluno *alunos, int quantidade) {
    if (alunos == NULL || quantidade <= 0) return NULL;

    Hash *ha = createHash();
    if (ha == NULL) return NULL;

    for (int i = 0; i < quantidade; i++) {
        insert_SeparateChaining(ha, alunos[i]);
    }

    return ha;
}

// Implementação do insertMultiple_SeparateChaining
int insertMultiple_SeparateChaining(Hash *ha, struct aluno *alunos, int quantidade) {
    if (ha == NULL || alunos == NULL || quantidade <= 0) return 0;

    int inseridos = 0;
    for (int i = 0; i < quantidade; i++) {
        if (insert_SeparateChaining(ha, alunos[i])) {
            inseridos++;
        }
    }

    return inseridos;
}

int main() {

    Hash* h = createHash();

    // Cria um aluno e o insere
    struct aluno aluno1 = {123, "Dio", 10, 9, 8};
    insert_SeparateChaining(h, aluno1);

    printf("Imprimindo o HashTable depois da primeira insercao...");
    printHash(h);

    // Cria um aluno e o insere forçando uma colisão no índice 3
    struct aluno aluno2 = {11, "Humberto", 3, 2, 1};
    insert_SeparateChaining(h, aluno2);

    printf("\nImprimindo o HashTable depois da segunda insercao...");
    printHash(h);

    struct aluno resultado;
    // Verifica a existência de um aluno com matrícula 123
    if (search_SeparateChaining(h, 123, &resultado))
        printf("\nEncontrado: %s, Notas: %.1f, %.1f, %.1f\n", resultado.nome, resultado.n1, resultado.n2, resultado.n3);
    else
        printf("\nAluno nao encontrado....\n");

    // Verifica a existência de um aluno com matrícula 11
    if (search_SeparateChaining(h, 11, &resultado))
        printf("Encontrado: %s, Notas: %.1f, %.1f, %.1f\n", resultado.nome, resultado.n1, resultado.n2, resultado.n3);
    else
        printf("Student not found.\n");

    // Procura por matrícula inexistente
    if (search_SeparateChaining(h, 40, &resultado))
        printf("Encontrado: %s, Notas: %.1f, %.1f, %.1f\n", resultado.nome, resultado.n1, resultado.n2, resultado.n3);
    else
        printf("Aluno nao encontrado....\n");

    // Libera a memória
    deleteHash(h);

    // Implementações novas 

    printf("\n\n\nNOVAS IMPLEMENTAÇÕES: \n");

    struct aluno lista[] = {
        {1234, "Eduardo", 8, 8, 8},
        {2341, "Gabriel", 7, 2, 10},
        {3412, "Jardel", 1, 10, 5},
        {4123, "Isabela", 9, 3, 4}
    };

    int quantidade = sizeof(lista) / sizeof(lista[0]);

    Hash* h1 = createHashFull(lista, quantidade);
    printf("\nHash criada com createHashFull:\n");
    printHash(h1);
    deleteHash(h1);

    Hash* h2 = createHash();
    insertMultiple_SeparateChaining(h2, lista, quantidade);
    printf("\nHash criada com insertMultiple_SeparateChaining:\n");
    printHash(h2);
    deleteHash(h2);

    return 0;
}
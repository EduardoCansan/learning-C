/*
    Para rodar o programa:abort
    - gcc -std=c99 hashEstaticoFechado.c -o hashEstaticoFechado.exe
    - ./hashEstáticoFechado.exe

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10
#define TAMANHO_CHAVE 50

// Estrutura para um nó da lista ligada (encadeamento)
typedef struct No {
    char chave[TAMANHO_CHAVE];
    struct No* proximo;
} No;

// Estrutura da tabela hash
typedef struct {
    No* tabela[TAMANHO_TABELA];
} HashTable;

// Função de hash simples (soma dos valores ASCII módulo tamanho da tabela)
int hash(char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

// Inicializa a tabela com NULLs
void inicializarTabela(HashTable* ht) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        ht->tabela[i] = NULL;
    }
}

// Insere uma chave na tabela
void inserir(HashTable* ht, char* chave) {
    int indice = hash(chave);

    No* novo = (No*) malloc(sizeof(No));
    strcpy(novo->chave, chave);
    novo->proximo = ht->tabela[indice];
    ht->tabela[indice] = novo;
}

// Busca por uma chave na tabela
int buscar(HashTable* ht, char* chave) {
    int indice = hash(chave);
    No* atual = ht->tabela[indice];

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return 1; // Encontrado
        }
        atual = atual->proximo;
    }
    return 0; // Não encontrado
}

// Remove uma chave da tabela
int remover(HashTable* ht, char* chave) {
    int indice = hash(chave);
    No* atual = ht->tabela[indice];
    No* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                ht->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1; // Removido com sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0; // Não encontrado
}

// Exibe a tabela hash
void exibirTabela(HashTable* ht) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        printf("[%d]: ", i);
        No* atual = ht->tabela[i];
        while (atual != NULL) {
            printf("%s -> ", atual->chave);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

// Libera a memória usada pela tabela
void liberarTabela(HashTable* ht) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        No* atual = ht->tabela[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

int main() {
    HashTable ht;
    inicializarTabela(&ht);

    inserir(&ht, "Joao");
    inserir(&ht, "Maria");
    inserir(&ht, "Ana");
    inserir(&ht, "Carlos");

    printf("Tabela Hash:\n");
    exibirTabela(&ht);

    printf("\nBuscando 'Maria': %s\n", buscar(&ht, "Maria") ? "Encontrado" : "Nao encontrado");

    printf("Removendo 'Ana'...\n");
    remover(&ht, "Ana");

    printf("Tabela Hash apos remocao:\n");
    exibirTabela(&ht);

    liberarTabela(&ht);
    return 0;
}

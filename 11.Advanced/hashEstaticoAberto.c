#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10
#define TAMANHO_CHAVE 50

typedef enum { VAZIO, OCUPADO, REMOVIDO } Estado;

typedef struct {
    char chave[TAMANHO_CHAVE];
    Estado estado;
} Elemento;

typedef struct {
    Elemento tabela[TAMANHO_TABELA];
} HashTable;

// Função de hash simples
int hash(char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

// Inicializa a tabela com todos os estados como VAZIO
void inicializarTabela(HashTable* ht) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        ht->tabela[i].estado = VAZIO;
    }
}

// Insere uma chave na tabela usando sondagem linear
int inserir(HashTable* ht, char* chave) {
    int indice = hash(chave);

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int pos = (indice + i) % TAMANHO_TABELA;

        if (ht->tabela[pos].estado == VAZIO || ht->tabela[pos].estado == REMOVIDO) {
            strcpy(ht->tabela[pos].chave, chave);
            ht->tabela[pos].estado = OCUPADO;
            return 1; // Inserido com sucesso
        }
    }
    return 0; // Tabela cheia
}

// Busca por uma chave
int buscar(HashTable* ht, char* chave) {
    int indice = hash(chave);

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int pos = (indice + i) % TAMANHO_TABELA;

        if (ht->tabela[pos].estado == VAZIO) {
            return 0; // Parou de procurar: não está na tabela
        }
        if (ht->tabela[pos].estado == OCUPADO && strcmp(ht->tabela[pos].chave, chave) == 0) {
            return 1; // Encontrado
        }
    }
    return 0; // Não encontrado
}

// Remove logicamente uma chave (marca como REMOVIDO)
int remover(HashTable* ht, char* chave) {
    int indice = hash(chave);

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int pos = (indice + i) % TAMANHO_TABELA;

        if (ht->tabela[pos].estado == VAZIO) {
            return 0; // Não encontrado
        }
        if (ht->tabela[pos].estado == OCUPADO && strcmp(ht->tabela[pos].chave, chave) == 0) {
            ht->tabela[pos].estado = REMOVIDO;
            return 1; // Removido logicamente
        }
    }
    return 0; // Não encontrado
}

// Exibe a tabela hash
void exibirTabela(HashTable* ht) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        printf("[%d]: ", i);
        if (ht->tabela[i].estado == OCUPADO) {
            printf("%s\n", ht->tabela[i].chave);
        } else if (ht->tabela[i].estado == REMOVIDO) {
            printf("<removido>\n");
        } else {
            printf("<vazio>\n");
        }
    }
}

int main() {
    HashTable ht;
    inicializarTabela(&ht);

    inserir(&ht, "Ana");
    inserir(&ht, "Carlos");
    inserir(&ht, "Joao");
    inserir(&ht, "Maria");

    printf("Tabela Hash:\n");
    exibirTabela(&ht);

    printf("\nBuscando 'Maria': %s\n", buscar(&ht, "Maria") ? "Encontrado" : "Nao encontrado");

    printf("Removendo 'Carlos'...\n");
    remover(&ht, "Carlos");

    printf("Tabela Hash apos remocao:\n");
    exibirTabela(&ht);

    return 0;
}

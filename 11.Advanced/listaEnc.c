#include <stdio.h>
#include <stdlib.h>

typedef struct st_no {
    int valor;
    struct st_no *prox;
} No;

int vazia(No *listaEncadeada);
void inicia(No *listaEncadeada);
void libera(No *listaEncadeada);
void exibir(No *listaEncadeada);
void inserirInicio(No *listaEncadeada);
void inserirFim(No *listaEncadeada);
void executarOpcao(No *listaEncadeada, int option);
int menu();

int main() {
    No *listaEncadeada = (No *)malloc(sizeof(No));
    if (!listaEncadeada) {
        printf("Sem memória disponível.\n");
        return 1;
    }

    inicia(listaEncadeada);

    int opt;
    do {
        opt = menu();
        executarOpcao(listaEncadeada, opt);
    } while (opt != 0);

    free(listaEncadeada);
    return 0;
}

int vazia(No *listaEncadeada) {
    return (listaEncadeada->prox == NULL);
}

void inicia(No *listaEncadeada) {
    listaEncadeada->prox = NULL; 
}

void libera(No *listaEncadeada) {
    if (!vazia(listaEncadeada)) {
        No *atual = listaEncadeada->prox;
        No *proxNo;
        while (atual != NULL) {
            proxNo = atual->prox;
            free(atual);
            atual = proxNo;
        }
        listaEncadeada->prox = NULL; 
    }
}

void exibir(No *listaEncadeada) {
    if (vazia(listaEncadeada)) {
        printf("Lista esta vazia...\n");
        return;
    }

    No *temp = listaEncadeada->prox;
    printf("\n");
    while (temp != NULL) {
        printf("%d - ", temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

void inserirInicio(No *listaEncadeada) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Sem memória disponível...\n");
        exit(1);
    }

    printf("Informe o valor: ");
    scanf("%d", &novo->valor);

    novo->prox = listaEncadeada->prox;
    listaEncadeada->prox = novo;
}

void inserirFim(No *listaEncadeada) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Sem memória disponível...\n");
        exit(1);
    }

    printf("Informe o valor: ");
    scanf("%d", &novo->valor);
    novo->prox = NULL; 

    if (vazia(listaEncadeada)) {
        listaEncadeada->prox = novo;
    } else {
        No *temp = listaEncadeada->prox;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void executarOpcao(No *listaEncadeada, int option) {
    switch (option) {
        case 0:
            libera(listaEncadeada);
            printf("Saindo...\n");
            break;
        case 1:
            exibir(listaEncadeada);
            break;
        case 2:
            inserirInicio(listaEncadeada);
            break;
        case 3:
            inserirFim(listaEncadeada);
            break;
        case 4:
            inicia(listaEncadeada);
            printf("Lista zerada.\n");
            break;
        default:
            printf("Comando inválido.\n");
    }
}

int menu() {
    int option;

    printf("\nEscolha a opcao:\n");
    printf("0. Sair\n");
    printf("1. Exibir\n");
    printf("2. Adicionar No no inicio\n");
    printf("3. Adicionar No no fim\n");
    printf("4. Zerar lista\n");
    printf("Opcao: ");
    scanf("%d", &option); 

    return option;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct st_arvore {
    int valor;
    struct st_arvore *sae; // Sub árvore Esquerda
    struct st_arvore *sad; // Sub árvore Direita
} Arvore;

Arvore* criaArvore();
int arvoreEstaVazia(Arvore* t);
void mostraArvore(Arvore* t);
void insereDadoArvore(Arvore** t, int num);
int estaNaArvore(Arvore* t, int num);
void liberaArvore(Arvore* t);

int main() {
    Arvore* t = criaArvore();

    insereDadoArvore(&t, 12);
    insereDadoArvore(&t, 15);
    insereDadoArvore(&t, 10);
    insereDadoArvore(&t, 13);

    printf("Arvore: ");
    mostraArvore(t);

    if (arvoreEstaVazia(t)) {
        printf("\nArvore Vazia...");
    } else {
        printf("\nArvore nao esta vazia!");
    }

    if (estaNaArvore(t, 15)) {
        printf("\nO elemento 15 esta na arvore");
    } else {
        printf("\nO elemento 15 nao está na arvore");
    }

    if (estaNaArvore(t, 3)) {
        printf("\nO elemento 3 esta na arvore");
    } else {
        printf("\nO elemento 3 nao esta na arvore");
    }

    liberaArvore(t);
    return 0;
}

Arvore* criaArvore() {
    return NULL;
}

int arvoreEstaVazia(Arvore* t) {
    return t == NULL;
}

void mostraArvore(Arvore* t) {
    printf("<");
    if (!arvoreEstaVazia(t)) {
        printf("%d", t->valor);
        mostraArvore(t->sae);
        mostraArvore(t->sad);  
    }
    printf(">");
}

void insereDadoArvore(Arvore** t, int num) {
    if (*t == NULL) {
        *t = (Arvore*)malloc(sizeof(Arvore));
        (*t)->valor = num;
        (*t)->sae = NULL;
        (*t)->sad = NULL;
    } else {
        if (num < (*t)->valor) {
            insereDadoArvore(&(*t)->sae, num);
        } else if (num > (*t)->valor) {
            insereDadoArvore(&(*t)->sad, num);
        }
    }
}

int estaNaArvore(Arvore* t, int num) {
    if (arvoreEstaVazia(t)) {
        return 0;
    }
    if (t->valor == num) {
        return 1;
    }
    return estaNaArvore(t->sae, num) || estaNaArvore(t->sad, num);
}

void liberaArvore(Arvore* t) {
    if (!arvoreEstaVazia(t)) {
        liberaArvore(t->sae);
        liberaArvore(t->sad);
        free(t);
    }
}

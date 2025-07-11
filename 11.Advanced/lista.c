#include <stdio.h>
#define TAMANHO 10

int fila[TAMANHO] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0;
int tail = 0;
int i;

// Funcition da Lista: 
void imprimirLista();
void enqueue();
void dequeue();
void clear();

int main() {
    
    int opcao = 0;

    do {
        printf("\n\nSelecione uma opcao: ");
        printf("\n1. Display: ");
        printf("\n2. Enqueue: ");
        printf("\n3. Dequeue: ");
        printf("\n4. Clear: ");
        printf("\n0. Exit: ");
        printf("\n\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            imprimirLista();
            break;
        
        case 2:
            enqueue();
            break;
        
        case 3:
            dequeue();
            break;

        case 4:
            clear();
            break;    

        case 0:
            break;

        default:
            printf("Opcao invalida");
        }

    }
    while (opcao != 0);
    
    printf("\nPrograma finalizado!");
    return 0;
}

void imprimirLista() {
    for (i = 0; i < TAMANHO; i++){
        printf("[%d] ", fila[i]);
    }
}

void enqueue() {
    if(tail < TAMANHO) {
        printf("Informe um valor para colocar na fila: ");
        scanf("%d", &fila[tail]);
        tail += 1;
    }
    else {
        printf("Fila esta cheia...");
    }
}

void dequeue() {
    if(head < tail) {
        fila[head] = 0;
        head += 1;
    }
    else {
        printf("Fila esta vazia...");
    }
}

void clear() {
    for (i = 0; i < TAMANHO; i++){
        fila[i] = 0;
    }
    head = 0;
    tail = 0;    
    
}
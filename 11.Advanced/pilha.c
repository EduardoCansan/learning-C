#include <stdio.h>
#define TAMANHO 10

int pilha[TAMANHO] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0;
int i;

void imprimirLista();
void push();
void pop();
void clear();

int main(){

    int opcao = 0;

    do {
        printf("\n\nSelecione uma opcao: ");
        printf("\n1. Display: ");
        printf("\n2. Push: ");
        printf("\n3. Pop: ");
        printf("\n4. Clear: ");
        printf("\n0. Exit: ");
        printf("\n\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            imprimirLista();
            break;
        
        case 2:
            push();
            break;
        
        case 3:
            pop();
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
        printf("[%d] ", pilha[i]);
    }
}

void push() {
    if(head < TAMANHO) {
        printf("Informe um valor para colocar na fila: ");
        scanf("%d", &pilha[head]);
        head += 1;
    }
    else {
        printf("A pilha esta cheia...");
    }
}

void pop() {
    if(head >= 0) {
        pilha[head-1] = 0;
        head -= 1;
    }
    else {
        printf("A pilha esta vazia...");
    }
}

void clear() {
for (i = 0; i < TAMANHO; i++){
    pilha[i] = 0;
}
head = 0;   
    
}

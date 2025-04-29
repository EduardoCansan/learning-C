/*
    Aumenta ou diminui o tamanho de um pedaço de memória já alocado. Se aumentar, os novos espaços não vêm zerados. 
    Se não tiver espaço para crescer ali, ele move a memória para outro lugar (por isso o ponteiro pode mudar).

    REALLOC => O realloc pode mover a memória para um novo local se necessário. Sempre cheque se o ponteiro não virou NULL depois!
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*) malloc(3 * sizeof(int)); // Aloca espaço para 3 inteiros

    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        p[i] = i + 1;
    }

    // Aumenta o bloco para 6 inteiros
    // Devemos usar uma variável temporária para evitar vazamento de memória.    
    int *temp = (int*) realloc(p, 6 * sizeof(int));
    if (temp == NULL) {
        printf("Erro ao realocar memória!\n");
        free(p); // Liberar o antigo
        return 1;
    }
    p = temp; // Se deu certo, atualiza o ponteiro


    if (p == NULL) {
        printf("Erro ao realocar memória!\n");
        return 1;
    }

    // Adiciona mais ou outros valores
    for (int i = 3; i < 6; i++) {
        p[i] = (i + 1) * 10;
    }

    // Imprime tudo
    for (int i = 0; i < 6; i++) {
        printf("%d ", p[i]);
    }

    free(p);
    return 0;
}

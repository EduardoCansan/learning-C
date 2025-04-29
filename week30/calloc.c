/*
    Aloca memória e já preenche tudo com zero. Você informa quantos blocos e o tamanho de cada um (ex.: 5 números inteiros).
    Útil quando quer ter certeza que a memória começa limpa.

    CALLOC => útil quando você quer garantir que toda memória comece limpa.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*) calloc(5, sizeof(int)); // Aloca e zera espaço para 5 inteiros

    // Pre
    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // é necessário colocar um condição do p ser nulo.
    // ERRO: se malloc falhar, p será NULL e usar p vai causar crash.
    for (int i = 0; i < 5; i++) {
        printf("%d ", p[i]); // Todos começam em 0
    }

    //Sempre importante lembrar de colocar o free e cuidar para usar somente um.
    free(p); // Libera a memória
    return 0;
}

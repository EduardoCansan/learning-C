#include <stdio.h>
#include <stdlib.h>

int main() {
    char *heapMemory = malloc(100 * sizeof(char));

    if (heapMemory == NULL)
    {
        perror("Malloc Failed Bro");
        return 1; // Retorna erro
    }

    free(heapMemory); // Libera a memória
    return 0;
}

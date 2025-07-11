#include <stdio.h>

int main() {

    int i;
    int array[5];
    int *ptr = array;

    for (i = 0; i < 5; i++) {
        printf("Digite o vetor[%d]: ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("\nDobro dos valores:\n");
    for (i = 0; i < 5; i++) {
        printf("Dobro do vetor[%d]: %d\n", i + 1, 2 * (*(ptr + i)));
    }

    return 0;
}

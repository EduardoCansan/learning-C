#include <stdio.h>

int main()
{
    
    int numero = 0, count = 0;

    while (count < 5) {
        if(numero % 3 == 0) {
            printf("O numero %d e multiplo de 3\n", numero);
            count += 1;
        }
        numero += 1;
    }
    printf("Tarefa finalziada!");
    
    return 0;
}

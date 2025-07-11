#include <stdio.h>

int torreDeExclamcao(int tamanho);

int main()
{

    torreDeExclamcao(5);

    return 0;
}

int torreDeExclamcao(int tamanho){

    int i, j;

    for (i = 1; i < tamanho + 1; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("!");
        }
        printf("\n");
        
    }

}
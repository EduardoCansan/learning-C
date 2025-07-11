#include <stdio.h>
#include <stdlib.h>

int numeroQuadratico(int x) {
    return (x * x);
}

int main()
{

    int num[3], i, j;

    for (i = 0; i < 3; i++)
    {
        printf("\nEscolhendo o numero %d: ", i + 1);
        scanf("%d", &num[i]);
    }

    for (i = 0; i < 3; i++)
    {
        printf("\nValor quadrado do nuemro: %d", numeroQuadratico(num[i]));
    }
    

    return 0;

}
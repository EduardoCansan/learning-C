#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int *p, vetor[3], i, qtd;

    p = (int*)malloc(sizeof(vetor)); // 5x4 = 20

    printf("Voce quer alocar quantos valores dentro do vetor: ");
    scanf("%d", &qtd);

    vetor[qtd];

    p = (int*)malloc(sizeof(vetor)); // ?x4 = ?

    if(qtd > 3) {
        for (i = 0; i < qtd; i++){
            printf("Digite o valor do vetor[%d]: ", i+1);
            scanf("%d", &vetor[i]);
        }

        printf("\nAqui estao os valores que voce alocou: ");
        for (i = 0; i < 5; i++){
            printf("\nValor do vetor[%d] => %d", i+1, vetor[i]);
        }
    }
    else {
        printf("Voce escolheu um valor menor que 3 para o vetor, NAO foi possivel continuar");
    }    
    
    free(p);
    p = NULL;

    return 0;
}

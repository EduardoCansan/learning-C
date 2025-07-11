#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i;
    float premio=0, aposta, total_aposta=0, porcentagem, ganho;

    printf("Valor do premio: ");
    scanf("%f", &premio);

    for (i = 0; i < 3; i++)
    {
        printf("Quanto o amigo %d apostou: ", i + 1);
        scanf("%f", &aposta);    
        total_aposta+=aposta;
    }

    printf("Total de aposta entre amigos: %.2f", total_aposta);
    
    return 0;

}
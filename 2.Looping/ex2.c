#include <stdio.h>

int main()
{
    
    int numero = 0;

    while (numero <= 100000) {
        printf("Numero: %d\n", numero);
        numero += 100;
    }
    printf("Voce chegou no numero desejado 100000");
    
    return 0;
}

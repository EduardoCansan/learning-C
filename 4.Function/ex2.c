#include <stdio.h>

int caractereMaiscula(char letra);

int main()
{

    caractereMaiscula('a');

    return 0;
}

int caractereMaiscula(char letra){
    
    char maisculo;

    maisculo = (letra - 32);

    printf("Letra maiscula: %c", maisculo);
    return maisculo;

}

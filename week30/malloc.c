/*
	Aloca um pedaço de memória sem limpar. Você precisa dizer o tamanho em bytes. 
    Depois, você usa esse espaço como quiser. Se não usar free, dá vazamento.

    MALLOC => aloca um bloco de memória não inicializado.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *p = (int*) malloc(5 *sizeof(int)); //Aloca espaço para 5 inteiros
    
    // é necessário colocar um condição do p ser nulo.
    // ERRO: se malloc falhar, p será NULL e usar p vai causar crash.
    if(p == NULL){
        printf("Erro ao alocar memória\n");
        return 1;
    }

    for(int i =0; i < 5; i++){
        p[i]= i;
        printf("%d ", p[i] * 2);
    }

    free(p); //Libera memória, mão usar gera --> memory leak (memória perdida).
    p = NULL; // Zerar o ponteiro depois de free

    return 0;
}

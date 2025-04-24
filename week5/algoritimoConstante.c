/*
    Complexidade de Algoritimos!
    Vamos dar uma olhada nos algoritimos e apronfundar nos tempos de execução deles.

*/

#include <stdio.h>

void functionWhile(int x) {
    
    printf("Função While: ");
    
    int i = 0;      // 1
    while(i < x)    // n + 1 
    {     
        printf("%d - ", i); // n
        i ++;               // n
    }
    // O Tempo do While é de T(n) = 3n + 2 = O(n)
}

void functionFor(int x) {
    
    printf("\nFuncao For: ");
    
    for (int i = 0; i < x; i++)
           // 1   //n + 1  //n
    {
        printf("%d - ", i); //n
    }
    //O tempo do For vai ser de T(n) = 3n + 2 = O(n)
}

void functionIf(int x) {
    
    printf("\nFuncao If: ");
    
    if (x < 10) {       // 1
        printf("Valor = %d, menor que 10", x); // 1
    } 
    else {
        
        for (int i = 0; i < x; i++) { //n + 1
            printf("%d - ", i);       //n
        }
        
    }
    // Para n < 10, temos uma complexidade de T(n) = 2 => O(1)
    // Para n >= 10, temos o pior caso com T(n) 2n + 2 => O(n)
    // O if pode mudar a complexidade do algoritimo 
}

int main()
{
    
    functionWhile(10);
    functionFor(10);
    functionIf(9);

    return 0;
}
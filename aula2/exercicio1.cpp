/*
1 - Escreva um algoritmo para ler o salário mensal atual de um funcionário e o percentual de reajuste.
Calcular e escrever o valor do novo salário bruto, calcule o INSS (11%), FGTS (6%) e deduza esses valores do valor bruto.
Apresente o valor liquido.
*/

#include <stdio.h>

int main()
{

    float salario,inss, fgts, salarioLiquido, salarioBruto;

    printf("Digite o seu salario: ");
    scanf("%f", &salario);

    inss = salario * 0.06;
    fgts = salario * 0.11;

    salarioLiquido = ((salario - inss) - fgts);
    salarioBruto = salario;
    
    printf("\nSeu Salario Bruto: %.2f", salarioBruto);
    printf("\nSeu Salario Liquido: %.2f", salarioLiquido);

    return 0;
}

/*
    Write an algorithm to read an employee's current monthly salary and the adjustment percentage.
    Calculate and display the new gross salary, then calculate INSS (11%) and FGTS (6%) deductions and subtract them from the gross amount.
    Finally, show the net salary.
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

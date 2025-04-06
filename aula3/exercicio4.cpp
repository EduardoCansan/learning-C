/*
4) Faca um programa que alimente um array de 5 elementos utlizando structs, e imprima os dados em tela da seguinte forma:
   Declaração da struct: char nome[120], char email[75], idade idade e float salario;	 
   
   - Se for maior que 18 anos, imprima mensagem de que está habilitado a tirar carteira de motorista.
   - Se o salário for maior de 8.000,00 mensais, imprimir mensagem informando que está apto a financiar um veículo e poderá
     comprometer até 35% da sua renda informando o valor máximo da parcela que poderá assumir. 
	 
     Em seguida compor o valor máximo do financiamento possível que consiste no valor máximo da parcela multiplicado
     por 48 parcelas e imprimir o resultado final em tela.	 
	 
*/

// bibliotecas 
#include <stdio.h>
#include <conio.h>
#include <cstdio>

// Declarando a Estrutura da Pessoa
typedef struct
{

    char nome[120];
    char email[75];
    int idade;
    float salario;

} Pessoa;

/*
Função que imprime o nome da Pessoa
Recebe como parametro com tipo Pessoa e variavel pessoa
*/
void imprimirDadosPessoa(Pessoa pessoa) {
    printf("Nome: %s \n", pessoa.nome);
    printf("Email: %s \n", pessoa.email);
    printf("Idade: %d \n", pessoa.idade);
    printf("Salario: %.2f \n\n", pessoa.salario);

    // Verifica se é maior de idade
    if (pessoa.idade >= 18) {
        printf("Voce esta habilitado a tirar carteira de motorista\n");
    }
    else {
        printf("Voce nao esta habilitado a tirar carteira de motorista\n");

    }

    // Verifica se pode financiar um carro e financiamento máximo
    float valorFinancia = pessoa.salario * 0.35; 
    float financiamentoMaximo = valorFinancia * 48;

    if (pessoa.salario >= 8000) {
        printf("Esta apto a financiar um veiculo, o custo para o isso e: %.2f", valorFinancia);
        printf("\nO financiamento maximo possivel e: %.2f \n", financiamentoMaximo);
    }
    else {
        printf("Voce nao pode financiar um veiculo\n");
    }

}

int main() {

    // Declarando variaveis
    int i;
    int tamanho = 5;

    Pessoa pessoa[tamanho];

    // Preencher os dados das pessoas
    for (i = 0; i < tamanho; i++)
    {
        printf("Digite o nome da Pessoa %d: ", (i + 1));
        fflush(stdin);
        scanf("%s", &pessoa[i].nome);

        printf("Digite a idade da Pessoa %d: ", (i + 1));
        fflush(stdin);
        scanf("%d", &pessoa[i].idade);

        printf("Digite o email da Pessoa %d: ", (i + 1));
        fflush(stdin);
        scanf("%s", &pessoa[i].email);

        printf("Digite o salario da Pessoa %d: ", (i + 1));
        fflush(stdin);
        scanf("%f", &pessoa[i].salario);

        printf("\n");
    }

    // Looping para printar as informações
    for (i = 0; i < tamanho; i++)
    {
        imprimirDadosPessoa(pessoa[i]);
    }

    // Encerra o programa
    printf("\nDigite qualquer caracter para encerrar o programa: ");
    getch();
    return(0);

}
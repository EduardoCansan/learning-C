# <center>Conceitos Básicos da Linguagem ©️<center>

Este documento apresenta alguns conceitos fundamentais da linguagem C, voltados especialmente para iniciantes que estão começando a entender o funcionamento da linguagem, ponteiros, strings, estruturas de dados e organização de código...

---

## Como clonar o repositório e rodar um código C
Vou usar o terminal do bash como exemplo para rodarmos:<br>

- 1° Você irá copiar essa url do link do repositório: https://github.com/EduardoCansan/learning-C-and-Cpp.git

- 2° Depois disso vá para a Área de Trabalho e de o seguinte comando para clonar o repositório no seu computador:

```bash
git clone https://github.com/EduardoCansan/learning-C-and-Cpp.git
```
- 3° Logo após criar a pasta dentro da sua Área de Trabalho, abra o código entrando no seu bash e digitando:

```bash
code .
```
- 4° Agora dentro do github vamos acessar uma pasta especifica:
```bash
cd week0
```
- 5° Estamos na reata final, agora só falta compilar o arquivo e rodar, para isso:
```bash
gcc evenOrOdd.c - o evenOrOdd.exe
```
- 6° O que fizemos foi criar uma executável atráves do nosso arquivo C, por fim rodamos o executavel:
```bash
./evenOrOdd.exe
```
---

## Valores Booleanos em C

Na linguagem C:

- `0` é considerado **FALSO** (`false`)
- Qualquer valor diferente de `0` é considerado **VERDADEIRO** (`true`)

---

## Tabela ASCII

A **Tabela ASCII** é um sistema de representação de caracteres onde **números inteiros são associados a símbolos**. Por exemplo:

| Símbolo | Código ASCII |
|---------|---------------|
| A       | 65            |
| a       | 97            |
| 0       | 48            |
| Espaço  | 32            |

---

## Strings em C

Para criar uma string em C, utiliza-se um array de caracteres:

```c
char nome[50] ;
```

Aqui determinados os numeros de caracteres, aqui temos 49.<br>
Por que 49? Um dos valores fica reservado para `/0` -> conta como 1

8 bits - 1 byte<br>
16 bits - 2 bytes<br>
24 bits - 3 bytes<br>
. . . 

---

## Função Main()

O int main() é uma função. o `return 0` retorna um inteiro que significa verdadeiro no boolean, como podemos observar, se tiver qualquer outro retorno dara um erro e o programa não conseguirá rodar.

```c
int main() {

    return 0;
}
```

---

## Protótipo da Função

Uma coisa que eu cuido muito nos meus códigos é deixar ele fácil para a leitura, uma técnica boa de ter usada no C é o próprio `protótipo da função`. Onde, primeiros declaramos as funções em cima do `int main()` vamos usar, e logo abaixo nós colocamos a lógica dela. Aqui temos um exemplo:

```c
void saudacao(); // Protótipo

int main() {
    saudacao();
    return 0;
}

void saudacao() { // Lógica
    printf("Olá!\n");
}
```

---

## Criando bibliotecas próprias

Bibliotecas personalizadas são compostas por duas coisas:
- arquivo de cabeçalho(`.h`) - contém protótipos de funções, definições de tipos e constantes.
- Um arquivo de código-fonte (`.c`) – contém a implementação das funções declaradas no `.h`.

<br>Arquivo de Cabeçalho (`ajuda.h`)

```c
void mensagem();
```
Arquivo de Código-Fonte(`ajuda.c`)

```c
void mensagem() {
    prinft("Bem vindo...\n");
};
```

Arquivo main(`main.c`)
```c
#include <ajuda.h>

int main() {
    menasgem();
    return 0;
}
```
---

## Sobre Ponteiros e Endereçamento de Memória

Ao utilizar scanf, passamos o endereço da variável usando o operador `&`. Isso armazena o valor lido diretamente no local de memória da variável. Esse valor pode ser resgatado e utilizado posteriormente com um loop, por exemplo.

```c
int idade;
scanf("%d", &idade);
```

Ponteiros são variáveis que armazenam endereços de memória. Exemplo:

```c
int x = 10;
int *p = &x;

printf("Endereço de x: %p\n", &x);
printf("Valor de p (endereço que p aponta): %p\n", p);
printf("Endereço de p: %p\n", &p);

```

| Conceito | O que representa |
|----------|------------------|
| Endereço de memória        | 	Onde uma variável comum está armazenada                   |
| Endereço de ponteiro	     | Onde a variável ponteiro (que guarda endereços) está armazenada            





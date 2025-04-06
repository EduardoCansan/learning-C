// LISTA DUPLAMENTE ENCADEADA

/*

Classes:
    - Elemento: representa um elemento da lista, ele armazena um
    valor inteiro e dois ponteiros, um apontando o proximo elemento e 
    o outro o anterior.
    
    -Lista Duplamente Encadeada: representa a lista em si, 
    possui em si os contrutores, enscapsulamento para que as variaveis
    fiquem escondidas, e os metodos que fazem as acoes na classe 
    principal a main.

    - Main: roda o programa principal, criamos dentro dele um Objeto 
    da lista para que possamos manuzear e utilizar dos metodos
    implementados na classe Lista Duplamente Encadeada.

Curiosidade:
    - Agora, a função 'alocarMemoria(int valor)' não foi removida, mas 
    incorporada ao construtor da classe Elemento. Agora, sempre que
    criamos um novo nó (new Elemento(valor)), ele já vem configurado 
    corretamente. Isso facilita o modo de escrever o código e visualizar
    de uma forma mais limpa também.

*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>


// Declaração da classe Elemento
class Elemento {
    
    // Propriedades privadas
    private:    
        int valor;
        Elemento *proximo;
        Elemento *anterior;
    
    // Metodos publicos
    public:
        Elemento(int valor) 
        {
            this -> valor = valor;
            this -> proximo = NULL;
            this -> anterior = NULL;
        }
        
        Elemento *obterProx() { return proximo; }
        Elemento *obterAnt() {return anterior; }
        int obterValor() { return valor; }
        void setProx(Elemento *elemento) { proximo = elemento; }
        void setAnt(Elemento *elemento) { anterior = elemento; }
    
};

// Declarando a classe da Lista Duplamente Encadeada
class ListaDuplamenteEncadeada {
    
    // Propriedades privadas
    private:
        Elemento *inicio;
        Elemento *fim;
        int tamanho;
        
    // Funções e Metodos publicos    
    public:
        // Construtor
        ListaDuplamenteEncadeada()
        {
            inicio = NULL;
            fim = NULL;
            tamanho = 0;
        }
        
        // Se passar elemento, entao cria novo elemento
        ListaDuplamenteEncadeada(int valor)
        {
            inicio = new Elemento(valor);
            fim = inicio;
            tamanho++;
        }

        // Destrutor (utilizamos ~ para denominar esse tipo)
        virtual ~ListaDuplamenteEncadeada()
        {

            Elemento *atual = inicio;
            while (atual)
            {
                Elemento *temp = atual;
                atual = atual->obterProx();
                delete temp;
            }
        }
        
        void removerInicio()
        {
            Elemento *atual = inicio;
        
            inicio = atual->obterProx();
            if (inicio != NULL)
                inicio->setAnt(NULL);
                tamanho--;
        }
        
        void removerFim()
        {
            Elemento *atual = fim;
        
            fim = atual->obterAnt();
            if (fim != NULL)
                fim->setProx(NULL);
                tamanho--;
        }
        
        // Inserir no inicio da lista:
        void inserirInicio(int valor)
        {
            Elemento *novo = new Elemento(valor); // criar novo elemento alocando memoria
        
            // verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo tambem, pois se os dois sao nulos o inico e fim recebe o novo.
            if (inicio == NULL)
            {
                inicio = novo;
                fim = novo;
            }
            else
            {
                Elemento *atual; // criar novo elemento caso tenha dado no inicio da lista.
    
                atual = inicio;
                novo->setProx(atual);
                atual->setAnt(novo);
                inicio = novo;
            }
        
            tamanho++;
        }
        
        // Inserir no fim da lista:
        void inserirFim(int valor)
        {
            Elemento *novo = new Elemento(valor); // criar novo elemento alocando memoria
        
            // verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo tambem, pois se os dois sao nulos o inico e fim recebe o novo.
            if (inicio == NULL)
            {
                inicio = novo;
                fim = novo;
            }
            else
            {
                Elemento *atual;
        
                atual = fim;
                novo->setAnt(inicio);
                atual->setProx(novo);       
                fim = novo;
            }
        
            tamanho++;
        }
        
        // Inserir no inicio da lista:
        void inserirPosicao(int valor, int posicao)
        {
            posicao = posicao - 1;
            Elemento *novo = new Elemento(valor); // criar novo elemento alocando memoria
        
            // verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo tambem, pois se os dois sao nulos o inico e fim recebe o novo.
            if (inicio == NULL)
            {
                inicio = novo;
                fim = novo;
        
            }
            else
            {
                Elemento *atual; // criar novo elemento caso tenha dado no inicio da lista.
                Elemento *tmp;
                int i;
        
                // Decidindo o ponto de incio
                if (posicao < (tamanho / 2))
                {
                    atual = inicio;
                    i = 0;
                }
                else
                {
                    atual = fim;
                    i = tamanho;
                }
        
                // Percorrer para encontrar a posisao
                while ((i != posicao) && (i >= 0) && (i <= tamanho))
                {
                    if (i < posicao)
                    {
                        i++;
                        atual = atual->obterProx();
                    }
                    else if (i > posicao)
                    {
                        i--;
                        atual = atual->obterAnt();
                    }
        
                    if (posicao == i)
                    {
                        printf("Valor antecessor ao que desejo inserir %d\n", atual->obterAnt()->obterValor());
                        printf("Valor proximo ao que desejo inserir %d\n", atual->obterProx()->obterValor());
                    }
                }
            }
        
        }
        
        // Funcao para imprimir a lista:
        void imprimirLista()
        {
            Elemento *atual;
            atual = inicio;
        
            while (atual)
            {
                printf("%d\n", atual->obterValor());
                atual = atual->obterProx();
            }
        }
        
        // Funcao para imprimir a lista:
        void imprimirListaInversa()
        {
            Elemento *atual;
            atual = fim;
        
            while (atual)
            {
                printf("%d\n", atual->obterValor());
                atual = atual->obterAnt();
            }
        }

};

int main()
{
    // Criando objeto lista da Classe Lista Duplamente Encadeada
    ListaDuplamenteEncadeada lista; 

    for (int i = 0; i < 10; i++)
        lista.inserirInicio(rand() % 100);

    //Inserir na posisao especifica 
    lista.inserirPosicao(1000, 2);

    printf("Imprimir lista atual ...\n");
    lista.imprimirLista();

    printf("\nImprimir lista inversa ...\n");
    lista.imprimirListaInversa();

    return 0;

}
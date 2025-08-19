/*
    1. Criando um Grafo

    REFERENCIAS:
    - https://medium.com/@paulomartins_10299/grafos-representa%C3%A7%C3%A3o-e-implementa%C3%A7%C3%A3o-f260dd98823d
    - https://medium.com/@paulomartins_10299/grafos-c%C3%B3digo-das-opera%C3%A7%C3%B5es-b%C3%A1sicas-e91d9a79e828

    */

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia {
    int vertice; // vertice de destino
    TIPOPESO peso; // peso associado a aresta que leva ao vertice de destino
    struct adjacencia *prox; // o próximo elemento da lista de adjecencias
} ADJACENCIA;

typedef struct vertice {
    // Dados armazenados vão aqui
    ADJACENCIA *cab; // possui apenas a cabeça da lista de adjacencia
} VERTICE;

typedef struct grafo { // lembrando que cada grafo possui:
    int vertices; // numero de vertice total de grafo
    int arestas; // numero de arestas totais do grafo
    VERTICE *adj; // arranjo de vertices de estrutura
} GRAFO;

// função para criar um grafo
GRAFO *criarGrafo (int v) {
    int i;

    GRAFO *g = (GRAFO *) malloc (sizeof(GRAFO)); // aloca espaço para estrutura grafo
    g->vertices = v; // atualiza o numero de vertice
    g->arestas = 0; 
    g->adj = (VERTICE *) malloc (v*sizeof(VERTICE));
    /* Dentro da estrutura tem só o arranjo para o ponteiro de vertice, não o arranjo em si
       então aloca o arranjo com (v) o numero de vertice desejado0 */ 

    for (i = 0; i < v; i++){
        g->adj[i].cab=NULL; //coloca NULL  em todas as arestas
    }
    return(g);
}

// função para adicionar arestas no grafo
ADJACENCIA *criaAdj(int v, int peso) {
    ADJACENCIA *temp = (ADJACENCIA *) malloc (sizeof(ADJACENCIA)); // aloca espaço para um nó
    temp->vertice = v; // vertice alvo da adjacencia
    temp->peso = peso; // peso da aresta
    temp->prox = NULL;
    return(temp); // retorno endereço da adjacencia
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p) { // vai de vi a vf
    if(!gr) return (false); // validações se o grafo existe
    if ((vf < 0) || (vf >= gr->vertices)) return false; //validações se os valores são negativos
    if ((vi < 0) || (vi >= gr->vertices)) return false; //ou maiores que o numero de vértices do grafo

    ADJACENCIA *novo = criaAdj(vf, p); // cria adjacencia com o vértice final e o peso
    // coloca a adjacencia na lista do vértice inicial
    novo->prox = gr->adj[vi].cab; // o campo prox da adjacencia vai receber a cabeça da lista
    gr->adj[vi].cab=novo; // e a cabeça da lista passa a ser o novo elemento
    gr->arestas++; // atualiza o numero de aresta no grafo
    return(true);
}

// função para imprimir o grafo
void imprime(GRAFO *gr) {
    // validações se o grafo existe

    printf("Vertices: %d. Arestas: %d. \n", gr->vertices, gr->arestas); // print numero de vertices e arestas
    int i;

    for (i = 0; i < gr->vertices; i++){
        printf("v%d: ", i); // imprime em qual aresta está
        ADJACENCIA *ad = gr->adj[i].cab; //chamo a cabeça da lista de adjacencia desta aresta
            while(ad) { // enquanto as adjacencias não forem nulas
                printf("v%d(%d) ", ad->vertice, ad->peso); // imprime a adjacencia e seu peso
                ad=ad->prox; // passo para a proxima adjacencia
            }
        printf("\n");
    }
}

// função main para rodar o programa
int main() {

    GRAFO * gr = criarGrafo(5);
    criaAresta(gr, 0, 1, 2);
    criaAresta(gr, 1, 2, 4);
    criaAresta(gr, 2, 0, 12);
    criaAresta(gr, 2, 4, 40);
    criaAresta(gr, 3, 1, 3);
    criaAresta(gr, 4, 3, 8);

    imprime(gr);
}
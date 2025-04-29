#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista de adjacência
typedef struct No {
    int vertice;
    struct No* prox;
} No;

// Estrutura para o Grafo
typedef struct {
    int V;          // Número de vértices
    No** adj;       // Array de ponteiros para listas de adjacência
} Grafo;

// Função para criar um grafo com V vértices
Grafo* criarGrafo(int V) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->V = V;

    // Aloca memória para as listas de adjacência
    grafo->adj = (No**)malloc(V * sizeof(No*));
    for (int i = 0; i < V; i++)
        grafo->adj[i] = NULL;

    return grafo;
}

// Função para adicionar aresta de v1 para v2
void adicionarAresta(Grafo* grafo, int v1, int v2) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->vertice = v2;
    novoNo->prox = grafo->adj[v1];
    grafo->adj[v1] = novoNo;
}

// Função para obter o grau de saída de um vértice
int obterGrauDeSaida(Grafo* grafo, int v) {
    int grau = 0;
    No* atual = grafo->adj[v];
    while (atual != NULL) {
        grau++;
        atual = atual->prox;
    }
    return grau;
}

// Função para verificar se v2 é vizinho de v1
int existeVizinho(Grafo* grafo, int v1, int v2) {
    No* atual = grafo->adj[v1];
    while (atual != NULL) {
        if (atual->vertice == v2)
            return 1;
        atual = atual->prox;
    }
    return 0;
}

// Função para liberar memória do grafo
void liberarGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->V; i++) {
        No* atual = grafo->adj[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(grafo->adj);
    free(grafo);
}

int main() {
    // criando um grafo de 4 vértices
    Grafo* grafo = criarGrafo(4);

    // adicionando as arestas
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 3);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 3, 1);
    adicionarAresta(grafo, 3, 2);

    // mostrando os graus de saída
    printf("Grau de saida do vertice 1: %d\n", obterGrauDeSaida(grafo, 1));
    printf("Grau de saida do vertice 3: %d\n", obterGrauDeSaida(grafo, 3));

    // verifica se existe vizinhos
    if (existeVizinho(grafo, 0, 1))
        printf("\n1 eh vizinho de 0\n");
    else
        printf("\n1 NAO eh vizinho de 0\n");

    if (existeVizinho(grafo, 0, 2))
        printf("2 eh vizinho de 0\n");
    else
        printf("2 NAO eh vizinho de 0\n");

    liberarGrafo(grafo);
    return 0;
}

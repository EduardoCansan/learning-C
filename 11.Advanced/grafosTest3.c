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
    grafo->adj = (No**)malloc(V * sizeof(No*));
    for (int i = 0; i < V; i++)
        grafo->adj[i] = NULL;
    return grafo;
}

// Adiciona uma aresta direcionada de v1 para v2
void adicionarAresta(Grafo* grafo, int v1, int v2) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->vertice = v2;
    novoNo->prox = grafo->adj[v1];
    grafo->adj[v1] = novoNo;
}

// Retorna o grau de saída do vértice v
int obterGrauDeSaida(Grafo* grafo, int v) {
    int grau = 0;
    No* atual = grafo->adj[v];
    while (atual != NULL) {
        grau++;
        atual = atual->prox;
    }
    return grau;
}

// Verifica se v2 é vizinho de v1
int existeVizinho(Grafo* grafo, int v1, int v2) {
    No* atual = grafo->adj[v1];
    while (atual != NULL) {
        if (atual->vertice == v2)
            return 1;
        atual = atual->prox;
    }
    return 0;
}

// Libera a memória usada pelo grafo
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
    int V, E;
    printf("Digite o numero de vertices: ");
    scanf("%d", &V);

    Grafo* grafo = criarGrafo(V);

    printf("Digite o numero de arestas: ");
    scanf("%d", &E);

    printf("Digite as arestas (formato: origem destino):\n");
    for (int i = 0; i < E; i++) {
        int origem, destino;
        scanf("%d %d", &origem, &destino);
        if (origem >= 0 && origem < V && destino >= 0 && destino < V)
            adicionarAresta(grafo, origem, destino);
        else
            printf("Aresta invalida! Ignorada.\n");
    }

    // Exemplo: mostrar grau de saída de todos os vértices
    printf("\nGrau de saida de cada vertice:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertice %d: %d\n", i, obterGrauDeSaida(grafo, i));
    }

    // Verificar vizinhança
    int v1, v2;
    printf("\nVerificar vizinhanca\nDigite v1 e v2: ");
    scanf("%d %d", &v1, &v2);
    if (existeVizinho(grafo, v1, v2))
        printf("%d eh vizinho de %d\n", v2, v1);
    else
        printf("%d NAO eh vizinho de %d\n", v2, v1);

    liberarGrafo(grafo);
    return 0;
}

/*
    Write a program in C to create a Graph
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for the Graph
typedef struct {
    int V;          // Number of vertices
    Node** adj;     // Array of pointers to adjacency lists
} Graph;

// Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    // Allocate memory for adjacency lists
    graph->adj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Function to add an edge from v1 to v2
void addEdge(Graph* graph, int v1, int v2) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v2;
    newNode->next = graph->adj[v1];
    graph->adj[v1] = newNode;
}

// Function to get the out-degree of a vertex
int getOutDegree(Graph* graph, int v) {
    int degree = 0;
    Node* current = graph->adj[v];
    while (current != NULL) {
        degree++;
        current = current->next;
    }
    return degree;
}

// Function to check if v2 is a neighbor of v1
int isNeighbor(Graph* graph, int v1, int v2) {
    Node* current = graph->adj[v1];
    while (current != NULL) {
        if (current->vertex == v2)
            return 1;
        current = current->next;
    }
    return 0;
}

// Function to free memory of the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        Node* current = graph->adj[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adj);
    free(graph);
}

int main() {
    // creating a graph with 4 vertices
    Graph* graph = createGraph(4);

    // adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 2);

    // showing the out-degrees
    printf("Out-degree of vertex 1: %d\n", getOutDegree(graph, 1));
    printf("Out-degree of vertex 3: %d\n", getOutDegree(graph, 3));

    // check if neighbors
    if (isNeighbor(graph, 0, 1))
        printf("\n1 is a neighbor of 0\n");
    else
        printf("\n1 is NOT a neighbor of 0\n");

    if (isNeighbor(graph, 0, 2))
        printf("2 is a neighbor of 0\n");
    else
        printf("2 is NOT a neighbor of 0\n");

    freeGraph(graph);
    return 0;
}

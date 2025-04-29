/*
    - Inserção de elementos
    - Remoção do menor elemento (raiz)
    - Heapify (ajuste automático para manter a propriedade de heap)
    - Impressão do heap (opcional para debug)

    - Segurança: Verifica se o heap está cheio ou vazio antes de inserir ou remover.
    - Modularização: Cada função tem uma responsabilidade clara.
    - Eficiência: Operações com tempo 𝑂(log 𝑛)

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

// Funções auxiliares para navegação
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

// Troca dois elementos do heap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sobe um elemento para manter a propriedade de min-heap
void heapifyUp(MinHeap *heap, int index) {
    while (index > 0 && heap->data[index] < heap->data[parent(index)]) {
        swap(&heap->data[index], &heap->data[parent(index)]);
        index = parent(index);
    }
}

// Desce um elemento para manter a propriedade de min-heap
void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;

    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Inicializa o heap
void initHeap(MinHeap *heap) {
    heap->size = 0;
}

// Insere um elemento no heap
void insert(MinHeap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap cheio!\n");
        return;
    }
    heap->data[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Remove e retorna o menor elemento do heap
int extractMin(MinHeap *heap) {
    if (heap->size == 0) {
        printf("Heap vazio!\n");
        return -1;
    }
    int min = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}

// Mostra o conteúdo do heap (debug)
void printHeap(MinHeap *heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->data[i]);
    printf("\n");
}

// Exemplo de uso
int main() {
    MinHeap heap;
    initHeap(&heap);

    insert(&heap, 10);
    insert(&heap, 4);
    insert(&heap, 15);
    insert(&heap, 1);
    insert(&heap, 20);

    printHeap(&heap);

    printf("Extraido: %d\n", extractMin(&heap));
    printHeap(&heap);

    return 0;
}

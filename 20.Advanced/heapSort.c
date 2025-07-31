/*
    - Constrói um Max-Heap com os elementos do array.
    - Repetidamente extrai o maior elemento (raiz do heap) e o coloca no final do array.
    - Tempo de execução: O(n log n).
    - Estável? Não (ordem relativa de elementos iguais pode mudar).
    - Ordenação in-place? Sim (não usa memória extra significativa).

    - Primeiro, o array é reorganizado para formar um Max-Heap.
    - O maior elemento (raiz) é trocado com o último.
    - O tamanho do heap é reduzido, e o processo se repete até tudo estar ordenado.
*/

#include <stdio.h>

// Troca dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Mantém a propriedade de max-heap a partir do índice i
void heapify(int arr[], int n, int i) {
    int largest = i;            // Inicializa maior como raiz
    int left = 2 * i + 1;       // Filho esquerdo
    int right = 2 * i + 2;      // Filho direito

    // Se filho esquerdo é maior que raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se filho direito é maior que o maior até agora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se maior não é a raiz
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);  // Recursivamente heapify a subárvore
    }
}

// Função principal do Heap Sort
void heapSort(int arr[], int n) {
    // Constrói o max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai um por um os elementos do heap
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);  // Move a raiz para o fim
        heapify(arr, i, 0);      // Chama heapify na heap reduzida
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Exemplo de uso
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Array ordenado com Heap Sort:\n");
    printArray(arr, n);

    return 0;
}
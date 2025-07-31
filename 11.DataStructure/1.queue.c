/*
    Write a program in C to create a queue, creating the functions: display, enqueue, dequeue and clear
*/

#include <stdio.h>
#define SIZE 10

int queue[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0;
int tail = 0;
int i;

void displayQueue();
void enqueue();
void dequeue();
void clear();

int main() {
    
    int option = 0;

    do {
        printf("\n\nSelect an option: ");
        printf("\n1. Display: ");
        printf("\n2. Enqueue: ");
        printf("\n3. Dequeue: ");
        printf("\n4. Clear: ");
        printf("\n0. Exit: ");
        printf("\n\nOption: ");
        scanf("%d", &option);

        switch(option) {
        case 1:
            displayQueue();
            break;
        
        case 2:
            enqueue();
            break;
        
        case 3:
            dequeue();
            break;

        case 4:
            clear();
            break;    

        case 0:
            break;

        default:
            printf("***Invalid Option***");
        }
    }
    while (option != 0);
    
    printf("\nProgram Finished!");
    return 0;
}

void displayQueue() {
    for (i = 0; i < SIZE; i++){
        printf("[%d] ", queue[i]);
    }
}

void enqueue() {
    if(tail < SIZE) {
        printf("Enter a value to the Queue: ");
        scanf("%d", &queue[tail]);
        tail += 1;
    
    } else {
        printf("Queue is full...");
    }
}

void dequeue() {
    if(head < tail) {
        queue[head] = 0;
        head += 1;
    
    } else {
        printf("The Queue is empty...");
    }
}

void clear() {
    for (i = 0; i < SIZE; i++){
        queue[i] = 0;
    }
    head = 0;
    tail = 0;    
}
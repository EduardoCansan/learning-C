/*
    Write a program in C to create a stack, creating the functions: display, push, pop and clear
*/

#include <stdio.h>
#define SIZE 10

int stack[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0;
int i;

void displayStack();
void push();
void pop();
void clear();

int main() {

    int option = 0;

    do {
        printf("\n\nSelect an option: ");
        printf("\n1. Display: ");
        printf("\n2. Push: ");
        printf("\n3. Pop: ");
        printf("\n4. Clear: ");
        printf("\n0. Exit: ");
        printf("\n\nOption: ");
        scanf("%d", &option);

        switch(option) {
        case 1:
            displayStack();
            break;
        
        case 2:
            push();
            break;
        
        case 3:
            pop();
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

void displayStack() {
    for (i = 0; i < SIZE; i++){
        printf("[%d] ", stack[i]);
    }
}

void push() {
    if(head < SIZE) {
        printf("Enter a value to put on the Stack: ");
        scanf("%d", &stack[head]);
        head += 1;
    
    } else {
        printf("The Stack is full...");
    }
}

void pop() {
    if(head >= 0) {
        stack[head-1] = 0;
        head -= 1;
    
    } else {
        printf("The Stack is empty...");
    }
}

void clear() {
    for (i = 0; i < SIZE; i++){
        stack[i] = 0;
    }
    head = 0;   
}

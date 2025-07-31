#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

int empty(Node *linkedList);
void start(Node *linkedList);
void release(Node *linkedList);
void display(Node *linkedList);
void insertAtStart(Node *linkedList);
void insertAtEnd(Node *linkedList);
void handleOption(Node *linkedList, int option);
int menu();

int main() {

    Node *linkedList = (Node *)malloc(sizeof(Node));
    
    if (!linkedList) {
        printf("***No memory available***\n");
        return 1;
    }

    start(linkedList);

    int option;
    do {
        option = menu();
        handleOption(linkedList, option);
    } while (option != 0);

    free(linkedList);
    return 0;
}

int empty(Node *linkedList) {
    return (linkedList->next == NULL);
}

void start(Node *linkedList) {
    linkedList->next = NULL; 
}

void release(Node *linkedList) {
    if (!empty(linkedList)) {
        Node *atual = linkedList->next;
        Node *nextNode;
        while (atual != NULL) {
            nextNode = atual->next;
            free(atual);
            atual = nextNode;
        }
        linkedList->next = NULL; 
    }
}

void display(Node *linkedList) {
    if (empty(linkedList)) {
        printf("Linked list is empty...\n");
        return;
    }

    Node *temp = linkedList->next;
    printf("\n");
    while (temp != NULL) {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtStart(Node *linkedList) {
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) {
        printf("***No memory available***\n");
        exit(1);
    }

    printf("Enter the value: ");
    scanf("%d", &new->data);

    new->next = linkedList->next;
    linkedList->next = new;
}

void insertAtEnd(Node *linkedList) {
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) {
        printf("***No memory available***\n");
        exit(1);
    }

    printf("Enter the value: ");
    scanf("%d", &new->data);
    new->next = NULL; 

    if (empty(linkedList)) {
        linkedList->next = new;
    } else {
        Node *temp = linkedList->next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void handleOption(Node *linkedList, int option) {
    switch (option) {
        case 0:
            release(linkedList);
            printf("Exiting...\n");
            break;
        case 1:
            display(linkedList);
            break;
        case 2:
            insertAtStart(linkedList);
            break;
        case 3:
            insertAtEnd(linkedList);
            break;
        case 4:
            start(linkedList);
            printf("List cleared...\n");
            break;
        default:
            printf("***Invalid command***\n");
    }
}

int menu() {
    int option;

    printf("\nSelect an option:\n");
    printf("0. Exit\n");
    printf("1. Display\n");
    printf("2. Add Node at the Start\n");
    printf("3. Add Node at the End\n");
    printf("4. Clean list\n");
    printf("Option: ");
    scanf("%d", &option); 

    return option;
}
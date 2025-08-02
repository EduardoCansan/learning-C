/*
    Write a program in C to create a Binary Tree, 
    creating the functions: createTree, treeIsEmpty, displayTree, insertTreeData, nodeInTree, cleanTree
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;  // Left Subtree
    struct node *right; // Right Subtree
} Node;

Node* createTree();
int treeIsEmpty(Node* root);
void displayTree(Node* root);
void insertTreeData(Node** root, int num);
int nodeInTree(Node* root, int num);
void cleanTree(Node* root);

int main() {
    Node* root = createTree();

    insertTreeData(&root, 12);
    insertTreeData(&root, 15);
    insertTreeData(&root, 10);
    insertTreeData(&root, 13);

    printf("Tree: ");
    displayTree(root);

    if (treeIsEmpty(root)) {
        printf("\nTree is empty...");
    
    } else {
        printf("\nTree is not empty!");
    }

    if (nodeInTree(root, 15)) {
        printf("\nThe element 15 is in the Tree!");
    
    } else {
        printf("\nThe element 15 is not in the Tree!");
    }

    if (nodeInTree(root, 3)) {
        printf("\nThe element 3 is in the Tree!");
    
    } else {
        printf("\nThe element 3 is not in the Tree!");
    }

    cleanTree(root);
    return 0;
}

Node* createTree() {
    return NULL;
}

int treeIsEmpty(Node* root) {
    return root == NULL;
}

void displayTree(Node* root) {
    printf("<");
    if (!treeIsEmpty(root)) {
        printf("%d", root->data);
        displayTree(root->left);
        displayTree(root->right);  
    }
    printf(">");
}

void insertTreeData(Node** root, int num) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = num;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (num < (*root)->data) {
            insertTreeData(&(*root)->left, num);
        } else if (num > (*root)->data) {
            insertTreeData(&(*root)->right, num);
        }
    }
}

int nodeInTree(Node* root, int num) {
    if (treeIsEmpty(root)) {
        return 0;
    }
    if (root->data == num) {
        return 1;
    }
    if (num < root->data) {
        return nodeInTree(root->left, num);
    } else {
        return nodeInTree(root->right, num);
    }
}

void cleanTree(Node* root) {
    if (!treeIsEmpty(root)) {
        cleanTree(root->left);
        cleanTree(root->right);
        free(root);
    }
}

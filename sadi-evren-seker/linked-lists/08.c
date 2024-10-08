#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int x;
    struct n* next;
} node;

void printLinkedList(node* rootNode) {
    while (rootNode != NULL) {
        printf("%d ", rootNode->x);
        rootNode = rootNode->next;
    }
    printf("\n");
}

node* insertElementInOrder(node* rootNode, int num) {
    if (rootNode == NULL) {
        rootNode = (node*) malloc(sizeof(node));
        rootNode->next = NULL;
        rootNode->x = num;
        return rootNode;
    }

    if (rootNode->x > num) {
        node* temp = (node*) malloc(sizeof(node));
        temp->x = num;
        temp->next = rootNode;
        return temp;
    }

    node* iter = rootNode;
    while (iter->next != NULL && iter->next->x < num) {
        iter = iter->next;
    }

    node* temp = (node*) malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x = num;

    return rootNode;
    
}

int main(void) {
    node* root = NULL;

    root = insertElementInOrder(root, 4);
    root = insertElementInOrder(root, 7);
    root = insertElementInOrder(root, 5);
    root = insertElementInOrder(root, 9);
    root = insertElementInOrder(root, 2);

    printLinkedList(root); // output: 2 4 5 7 9
}
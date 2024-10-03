#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct n {
    int x;
    struct n* next;
} node;

// Function to print the linked list
void printLinkedList(node* r) {
    while (r != NULL) {
        printf("%d ", r->x);
        r = r->next;
    }
    printf("\n");
}

// Function to add an element at the end of the linked list
void addElementAtTheEndOfTheLinkedList(node** root, int num) {
    if (*root == NULL) {
        *root = (node*)malloc(sizeof(node));
        (*root)->x = num;
        (*root)->next = NULL;
        return;
    }

    node* iter = *root;
    while (iter->next != NULL) {
        iter = iter->next;
    }

    iter->next = (node*)malloc(sizeof(node));
    iter->next->x = num;
    iter->next->next = NULL;
}

// Function to insert an element into the linked list in sorted order
void insertElementSorted(node** root, int num) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->x = num;
    newNode->next = NULL;

    if (*root == NULL || (*root)->x >= num) {
        newNode->next = *root;
        *root = newNode;
        return;
    }

    node* iter = *root;
    while (iter->next != NULL && iter->next->x < num) {
        iter = iter->next;
    }

    newNode->next = iter->next;
    iter->next = newNode;
}

// Function to insert an element after a given position in the linked list
void insertElementAtPosition(node* root, int position, int num) {
    node* iter = root;
    for (int i = 0; i < position - 1 && iter != NULL; i++) {
        iter = iter->next;
    }

    if (iter == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    node* newNode = (node*)malloc(sizeof(node));
    newNode->x = num;
    newNode->next = iter->next;
    iter->next = newNode;
}

int main(void) {
    node* root = NULL;

    // Adding elements at the end
    addElementAtTheEndOfTheLinkedList(&root, 10);
    addElementAtTheEndOfTheLinkedList(&root, 20);
    addElementAtTheEndOfTheLinkedList(&root, 30);
    addElementAtTheEndOfTheLinkedList(&root, 50);

    printLinkedList(root);
    // Output: 10 20 30 50

    // Insert an element in sorted order
    insertElementSorted(&root, 40);

    printLinkedList(root);
    // Output: 10 20 30 40 50

    // Insert an element at a specific position (position 3 here)
    insertElementAtPosition(root, 3, 99);

    printLinkedList(root);
    // Output: 10 20 99 30 40 50

    return 0;
}

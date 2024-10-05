// Creating a doubly linked list and traversing it
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int x;
    struct n* prev;
    struct n* next;
} node;

// Function to create a doubly linked list with a single node
node* createDoublyLinkedList(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->x = data;
    newNode->prev = NULL; // First node has no previous node
    newNode->next = NULL; // First node has no previous node
    return newNode;
}

// Function to traverse the doubly linked list in forward direction
void printDoublyLinkedList(node* root) {
    while (root != NULL) {
        printf("%d ", root->x);
        root = root->next;
    }
    printf("\n");
}

int main(void) {
    // Create a doubly linked list with a single node
    node* root = createDoublyLinkedList(10);

    // Print it out
    printDoublyLinkedList(root); // output: 10
}
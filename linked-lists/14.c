// Inserting a node at the end of a doubly linked list
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
node* insertAtEnd(node* root, int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->x = data;
    newNode->next = NULL; // New node's next will be NULL (end of the list)

    if (root == NULL) {
        newNode->prev = NULL; // If the list is empty, new node is the first node
        return newNode;
    }

    node* temp = root;

    while (temp->next != NULL) { // Traverse to the last node
        temp = temp->next;
    } 

    temp->next = newNode;
    newNode->prev = temp; // Set the new node's prev to the last node

    return root;
}

// Function to traverse the doubly linked list forward
void printForward(node* root) {
    while (root != NULL) {
        printf("%d ", root->x);
        root = root->next;
    }
    printf("\n");
}

// Function to traverse the doubly linked list backward
void printBackward(node* tail) {
    while (tail != NULL) {
        printf("%d ", tail->x);
        tail = tail->prev;
    }
    printf("\n");
}

int main(void) {
    // Create a doubly linked list
    node* root = createDoublyLinkedList(10);

    // Insert new elements
    root = insertAtEnd(root, 20);
    root = insertAtEnd(root, 30);

    printf("Forward: ");
    printForward(root); // OUTPUT: Forward: 10 20 30

    // Traverse to the last node to print backward 
    node* tail = root;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    printf("Backward: ");
    printBackward(tail); // OUTPUT: Backward: 30 20 10
}
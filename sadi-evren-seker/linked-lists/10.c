// Inserting a node at the end of a circular linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int x;
    struct n* next;
} node;

// Function to create a circular linked list with a single node
node* createCircularLinkedList(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->x = data;
    newNode->next = newNode; // Points itself
    return newNode;
}

// Function to insert a node at the end of the circular linked list
node* insertAtEnd(node* root, int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->x = data;

    if (root == NULL) {
        newNode->next = newNode; // If list is empty, create a circular list
        return newNode;
    }

    node* temp = root;
    while (temp->next != root) { // Traverse to the last node
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = root;
    return root;
}

// Function to print the circular linked list
void printTheCircularLinkedList(node* root) {
    if (root == NULL) return;

    node* temp = root;
    do {
        printf("%d ", temp->x);
        temp = temp->next;
    } while (temp != root);
    printf("\n");
}

int main(void) {
    // Create a circular linked list
    node* root = createCircularLinkedList(10);

    // Insert new elements
    root = insertAtEnd(root, 20);
    root = insertAtEnd(root, 30);

    // Print the circular list
    printTheCircularLinkedList(root); // output: 10 20 30
}
// Creating a circular linked list only with one node and traversing it
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int x;
    struct n* next;
} node;

// Function to create a singular linked list with a single node
node* createCircularLinkedList(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->x = data;
    newNode->next = newNode; // Points to itself, making it circular
    return newNode;
}

// Function to traverse the circular linked list and print the data
void printCircularLinkedList(node* root) {
    if (root == NULL) return;

    node* temp = root;
    do {
        printf("%d ", temp->x);
        temp = temp->next;
    } while (temp != root); // Continue until the root is reached again
    printf("\n");
}

int main(void) {
    // Create a circular linked list with a single node
    node* root = createCircularLinkedList(10);

    // Print the circular linked list
    printCircularLinkedList(root);
}
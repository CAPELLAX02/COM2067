// Deleting a node from a circular linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int x;
    struct n* next;
} node;

// Function to create a circular linled list with a single node
node* createCircularLinkedList(int data) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode->x = data;
    newNode->next = newNode; // Points to itself
    return newNode;
}

// Function to insert a node at the end of the circular linked list
node* insertAtEnd(node* root, int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->x = data;

    // If list is empty, create a circular list
    if (root == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    node* temp = root;

    // Traverse to the last node
    while (temp->next != root) {    
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = root; // New node point back to root
    return root;
}

// Function to print the circular linked list
void printTheCircularList(node* root) {
    if (root == NULL) return;

    node* temp = root;
    do {
        printf("%d ", temp->x);
        temp = temp->next;
    } while (temp != root);
    printf("\n");
}

// Function to delete a node by value from the circular linked list
node* deleteNode(node* root, int data) {
    if (root == NULL) return NULL;

    node* temp = root;
    node* prev = NULL;

    // If the node to be deleted is the root and only one node exists
    if (temp->x == data && temp->next == root) {
        free(temp); // Free the only node
        return NULL;
    }

    // If the node to be deleted is the root with more than one node
    if (temp->x == data) {
        // Find the last node
        while (temp->next != root) {
            temp = temp->next;
        }
        temp->next = root->next;
        free(root); // Free the memory
        return temp->next;
    }

    // Traverse the list to find the node to be deleted
    while (temp->next != root && temp->x != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->x == data) {
        prev->next = temp->next; // Bypass the node to be deleted
        free(temp); // Free the memory
    }

    return root; // Return the updated root
}

int main(void) {
    // Create a circular linked list with some nodes
    node* root = createCircularLinkedList(10);
    root = insertAtEnd(root, 20);
    root = insertAtEnd(root, 30);
    root = insertAtEnd(root, 40);

    printf("Original List: ");
    printTheCircularList(root); 
    // OUTPUT: Original List: 10 20 30 40 

    // Delete a node
    root = deleteNode(root, 30);

    printf("After Deletion of 30: ");
    printTheCircularList(root);
    // OUTPUT: After Deletion of 30: 10 20 40 
}
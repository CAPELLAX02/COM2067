// Comprehensive Circular Linked List Example
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int x;
    struct n* prev;
    struct n* next;
} node;

// Function to create a new node
node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->x = data;
    newNode->next = newNode;    
    newNode->prev = newNode;
    return newNode;
}

// Function to insert a node at the beginning of the circular list
node* insertAtBeginning(node* root, int data) {
    node* newNode = (node*) malloc(sizeof(node));

    if (root == NULL) {
        return newNode; // If the list is empty, the new node is the root
    }

    // Adjust the links for the new node and existing nodes
    newNode->next = root;
    newNode->prev = root->prev;
    root->prev->next = newNode;
    root->prev = newNode;

    return newNode; // The new node is now the root
}

// Function to insert a node at the end of the circular list
node* insertAtEnd(node* root, int data) {
    node* newNode = createNode(data);

    if (root == NULL) {
        return newNode; // If the list is empty, the new node is the root
    }

    // Adjust the links for the new node and existing nodes
    node* last = root->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = root;
    root->prev = newNode;

    return root; // The root remains the same
}

// Function to insert a node in a sorted manner
node* insertInOrder(node* root, int data) {
    if (root == NULL || root->x >= data) {
        return insertAtBeginning(root, data);
    }

    node* temp = root;
    do {
        if (temp->next->x >= data || temp->next == root) {
            node* newNode = createNode(data);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    } while (temp != root);

    return root;
}

// Function to delete the first node in the circular linked list
node* deleteFromBeginning(node* root) {
    if (root == NULL) return NULL; // Empty list

    // If there is only one node
    if (root->next == root) {
        free(root);
        return NULL;
    }

    node* last = root->prev;
    node* newRoot = root->next;

    last->next = newRoot;
    newRoot->prev = last;
    free(root); // Free the old root

    return newRoot; // The new root is the next node
}

// Function to delete the last node in the circular list
node* deleteFromEnd(node* root) {
    if (root == NULL) return NULL;

    // If there is only one node
    if (root->next == root) {
        free(root);
        return NULL;
    }

    node* last = root->prev;
    last->prev->next = root;
    root->prev = last->prev;
    free(last);

    return root;
}

// Function to delete a node by value
node* deleteByValue(node* root, int value) {
    if (root == NULL) return NULL;

    node* temp = root;
    do {
        if (temp->x == value) {
            // If the node to be deleted is the root
            if (temp == root) {
                return deleteFromBeginning(root);
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return root;
        }
        temp = temp->next;
    } while (temp != root);

    return root; // Return the root if the value is not found
}

// Function to print the circular linked list forward
void printCircularLinkedListForward(node* root) {
    if (root == NULL) return;

    node* temp = root;
    
    do {
        printf("%d ", temp->x);
        temp = temp->next;
    } while (temp != root);

    printf("\n");
}

// Function to print the circular linked list backward
void printCircularLinkedListBackward(node* root) {
    if (root == NULL) return;

    node* last = root->prev;
    node* temp = last;
    
    do {
        printf("%d ", temp->x);
        temp = temp->prev;
    } while (temp != last);

    printf("\n");
}

int main(void) {
    node* root = NULL;

    // Insert elements into the list
    root = insertAtEnd(root, 10);
    root = insertAtEnd(root, 20);
    root = insertAtEnd(root, 40);

    printf("Before inserting 30 in order: ");
    printCircularLinkedListForward(root);
    // CURRENT LIST: 10 20 40 

    root = insertInOrder(root, 30); // Insert in sorted order
    printf("After inserting 30 in order: ");
    printCircularLinkedListForward(root);
    // CURRENT LIST: 10 20 30 40 

    printf("List Forward: ");
    printCircularLinkedListForward(root);
    // CURRENT LIST: 10 20 30 40 

    printf("List Backward: ");
    printCircularLinkedListBackward(root);
    // CURRENT LIST: 40 30 20 10 

    // Delete the first element
    root = deleteFromBeginning(root);
    printf("After deleting from the beginning (forward): ");
    printCircularLinkedListForward(root); 
    // CURRENT LIST: 20 30 40 

    // Delete the last element
    root = deleteFromBeginning(root);
    printf("After deleting from the end (forward): ");
    printCircularLinkedListForward(root);
    // CURRENT LIST: 30 40 

    // Delete a specific element by value
    root = deleteByValue(root, 30);
    printf("After deleting 30 (forward): ");
    printCircularLinkedListForward(root);
    // CURRENT LIST: 40
}
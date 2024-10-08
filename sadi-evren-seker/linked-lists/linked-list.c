// Following program demonstrates numerous operations on a linked list
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} node;

// Function prototypes
node* createNode(int data);
void insertAtBeginning(node** head, int data);
void insertAtEnd(node** head, int data);
void insertAfter(node* prevNode, int data);
void deleteNodeByValue(node** head, int key);
void deleteAtPosition(node** head, int position);
void displayList(node* head);
int search(node* head, int key);
void reverseList(node** head);
void deleteList(node** head);

// Main function to demonstrate the linked list operations
int main() {
    node* head = NULL;  // Initialize an empty list

    // Insert elements
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAfter(head->next, 15); // Insert 15 after the second node

    printf("Linked List after insertion:\n");
    displayList(head);

    // Delete by value
    deleteNodeByValue(&head, 15);
    printf("Linked List after deletion of 15:\n");
    displayList(head);

    // Delete at position
    deleteAtPosition(&head, 2);
    printf("Linked List after deletion at position 2:\n");
    displayList(head);

    // Reverse the list
    reverseList(&head);
    printf("Linked List after reversal:\n");
    displayList(head);

    // Search for an element
    int key = 10;
    if (search(head, key))
        printf("Element %d found in the list.\n", key);
    else
        printf("Element %d not found in the list.\n", key);

    // Delete the entire list
    deleteList(&head);
    printf("Linked List after deleting all nodes:\n");
    displayList(head); // Should display an empty list

    return 0;
}

// Create a new node
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the list
void insertAtBeginning(node** head, int data) {
    node* newNode = createNode(data);
    newNode->next = *head;  // Link the new node to point to the old head
    *head = newNode;        // Update head to point to the new node
}

// Insert a node at the end of the list
void insertAtEnd(node** head, int data) {
    node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;    // If list is empty, make the new node the head
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;  // Link the last node to the new node
}

// Insert a node after a given node
void insertAfter(node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Delete a node by its value
void deleteNodeByValue(node** head, int key) {
    node* temp = *head;
    node* prev = NULL;

    if (temp != NULL && temp->data == key) { // If head node contains the key
        *head = temp->next;  // Change head
        free(temp);          // Free old head
        return;
    }

    // Search for the key in the list
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the list
    if (temp == NULL) {
        printf("Element %d not found.\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free the memory
}

// Delete a node at a specific position (0-based index)
void deleteAtPosition(node** head, int position) {
    if (*head == NULL) return;

    node* temp = *head;

    // If head needs to be removed
    if (position == 0) {
        *head = temp->next;  // Change head
        free(temp);          // Free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is more than the number of nodes
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d does not exist.\n", position);
        return;
    }

    // Node temp->next is the node to be deleted
    node* next = temp->next->next;
    free(temp->next); // Free the memory
    temp->next = next; // Unlink the deleted node from the list
}

// Display all elements in the list
void displayList(node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

// Search for an element in the list
int search(node* head, int key) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return 1;  // Element found
        temp = temp->next;
    }
    return 0;  // Element not found
}

// Reverse the linked list
void reverseList(node** head) {
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    *head = prev;  // Update head to the new first node
}

// Delete the entire list
void deleteList(node** head) {
    node* current = *head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next node
        free(current);         // Free the current node
        current = next;
    }
    *head = NULL;  // Dereference head to indicate an empty list
}

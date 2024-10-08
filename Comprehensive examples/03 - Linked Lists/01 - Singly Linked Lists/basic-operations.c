// Basic Operations in a Singly Linked List (Insertion, Deletion, and Traversal)
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} node;

// Function prototypes
void displayMenu();
void displayList(node* node);
void insertAtHead(node** head_ref, int newData);
void insertAtTail(node** head_ref, int newData);
void deleteNode(node** head_ref, int key);
void reverseList(node** head_ref);

int main(void) {
    node* head = NULL;
    int choice, value;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at head: ");
                scanf("%d", &value);
                insertAtHead(&head, value);
                printf("Current list: ");
                displayList(head);
                break;
            case 2:
                printf("Enter value to insert at tail: ");
                scanf("%d", &value);
                insertAtTail(&head, value);
                printf("Current list: ");
                displayList(head);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                printf("Current list: ");
                displayList(head);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                reverseList(&head);
                printf("Current list: ");
                displayList(head);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Singly Linked List Menu ---\n"
       "1. Insert at Head\n"
       "2. Insert at Tail\n"
       "3. Delete by Value\n"
       "4. Display List\n"
       "5. Reverse List\n"
       "6. Exit\n"
       "Choose an option: ");
}

// Function to insert a node at the head
void insertAtHead(node** head, int newData) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at head.\n", newData);
}

// Function to insert a node at the tail
void insertAtTail(node** head, int newData) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) { 
        *head = newNode;
    }
    else {
        node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("%d inserted at tail.\n", newData);
}

// Function to delete a node by value
void deleteNode(node** head, int key) {
    node* temp = *head;
    node* prev = NULL;

    // If the head node contains the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return;
    }

    // Search for the key in the list
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    // Unlink the node and free the memory
    prev->next = temp->next;
    free(temp);

    printf("Node with value %d deleted.\n", key);
}

// Function to traverse and display the linked list
void displayList(node* head) {
    if (head == NULL) {
        puts("List is empty.");
        return;
    }

    node* temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    puts("NULL");
}

// Function to reverse the linked list
void reverseList(node** head) {
    node* prev = NULL;
    node* curr = *head;
    node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}
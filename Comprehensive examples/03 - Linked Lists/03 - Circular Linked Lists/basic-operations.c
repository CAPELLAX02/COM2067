// Basic operations on a circular linked list
#include <stdio.h>
#include <stdlib.h>

// Circular linked list node structure
typedef struct Node {
    int data;
    struct Node* next;
} node;

// Function prototypes
void displayMenu();
void insertAtHead(node** headRef, int newData);
void insertAtTail(node** headRef, int newData);
void deleteNode(node** headRef, int key);
void displayList(node* head);

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
                break;
            case 2:
                printf("Enter value to insert at tail: ");
                scanf("%d", &value);
                insertAtTail(&head, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

void displayMenu() {
    printf("\n--- Circular Linked List Menu ---\n");
    printf("1. Insert at Head\n");
    printf("2. Insert at Tail\n");
    printf("3. Delete by Value\n");
    printf("4. Display List\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void insertAtHead(node** headRef, int newData) {
    
}
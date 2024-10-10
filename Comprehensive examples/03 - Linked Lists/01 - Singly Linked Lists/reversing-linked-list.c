// Reversing a Singly Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

// Function prototypes
void displayMenu();
void insertAtHead(node** head, int newData);
void displayList(node* head);
void reverseList(node** head);

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
                printf("Reversing the list...\n");
                reverseList(&head);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Singly Linked List Menu ---\n");
    printf("1. Insert at Head\n");
    printf("2. Reverse List\n");
    printf("3. Display List\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void insertAtHead(node** head, int newData) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at head.\n", newData);
}

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

    printf("List reversed.\n");
}

void displayList(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
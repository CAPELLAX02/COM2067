// Demonstration of reversing a doubly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} node;

// Function prototypes
void displayMenu();
void insertAtHead(node** headRef, int newData);
void displayList(node* head);
void reverseList(node** headRef);

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
                printf("End of run.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void displayMenu() {
    printf("\n--- Doubly Linked List Menu ---\n");
    printf("1. Insert at Head\n");
    printf("2. Reverse List\n");
    printf("3. Display List\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void insertAtHead(node** headRef, int newData) {
    node* newNode = (node*) malloc(sizeof(node));

    newNode->data = newData;
    newNode->next = *headRef;
    newNode->prev = NULL;

    if (*headRef != NULL)
        (*headRef)->prev = newNode;

    *headRef = newNode;

    printf("%d inserted at head.\n", newData);
}

void displayList(node* head) {
    if (head == NULL) {
        puts("List is empty.");
        return;
    }

    printf("Linked List: ");

    node* temp = head;

    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    puts("NULL");
}

void reverseList(node** headRef) {
    node* temp = NULL;
    node* current = *headRef;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Fix the head pointer
    if (temp != NULL)
        *headRef = temp->prev;

    puts("List has been reversed.");
}
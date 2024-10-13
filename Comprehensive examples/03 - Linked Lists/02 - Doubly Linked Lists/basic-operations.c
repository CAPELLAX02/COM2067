// In this example, the user will be able to add to the doubly linked list from the beginning and end, delete a node by value, and move the list forward and backward.
#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} node;

// Function prototypes
void displayMenu(void);
void insertAtHead(node** headRef, int newData);
void insertAtTail(node** headRef, int newData);
void deleteNode(node** headRef, int key);
void displayListForward(node* head);
void displayListBackward(node* head);

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
                displayListForward(head);
                break;
            case 5:
                displayListBackward(head);
                break;
            case 6:
                printf("End of run.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

void displayMenu() {
    printf("\n--- Doubly Linked List Menu ---\n");
    printf("1. Insert at Head\n");
    printf("2. Insert at Tail\n");
    printf("3. Delete by Value\n");
    printf("4. Display List (Forward)\n");
    printf("5. Display List (Backward)\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void insertAtHead(node** headRef, int newData) {
    node *newNode = (node*) malloc(sizeof(node));

    newNode->data = newData;
    newNode->next = *headRef;
    newNode->prev = NULL;

    if (*headRef != NULL) { 
        (*headRef)->prev = newNode;
    }

    *headRef = newNode;

    printf("%d inserted at head.\n", newData);
}

void insertAtTail(node** headRef, int newData) {
    node* newNode = (node*) malloc(sizeof(node));
    
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        newNode->prev = NULL;
        *headRef = newNode;
    }
    else {
        node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    printf("%d inserted at tail.\n", newData);
}

void deleteNode(node** headRef, int key) {
    node* temp = *headRef;

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If node not found
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    // If the node is the head node
    if (*headRef == temp)
        *headRef = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Node with value %d deleted.\n", key);
}

void displayListForward(node* head) {
    if (head == NULL) {
        puts("List is empty.");
        return;
    }

    printf("List in forward direction: ");

    node* temp = head;

    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    puts("NULL");
}

void displayListBackward(node* head) {
    if (head == NULL) {
        puts("List is empty.");
        return;
    }

    node* temp = head;
    
    while (temp->next != NULL)
        temp = temp->next;
    
    printf("Lis in backward direction: ");
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->prev;
    }
    puts("NULL");
}

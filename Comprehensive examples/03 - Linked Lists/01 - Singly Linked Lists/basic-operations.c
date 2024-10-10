// Comprehensive operations in a singly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

// Function prototypes
void displayMenu();
void insertAtHead(node** head, int newData);
void insertAtTail(node** head, int newData);
void deleteNode(node** head, int key);
void displayList(node* head);
int lengthOfList(node* head);

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
                printf("Length of the list: %d\n", lengthOfList(head));
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

void insertAtHead(node** head, int newData) {   
    node* newNode = (node*) malloc(sizeof(node));

    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;

    printf("%d inserted at head.\n", newData);
}

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

    printf("%d inserted ad tail.\n", newData);
}

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

int lengthOfList(node* head) {
    int length = 0;
    node* temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    return length;
}

void displayMenu() {
    printf("\n--- Singly Linked List Menu ---\n");
    printf("1. Insert at Head\n");
    printf("2. Insert at Tail\n");
    printf("3. Delete by Value\n");
    printf("4. Display List\n");
    printf("5. Length of List\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

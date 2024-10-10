// Sorting a Singly Linked List using Merge Sort
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

// Function prototypes
void displayMenu();
void insertAtTail(node** headRef, int newData);
void displayList(node* head);
void mergeSort(node** headRef);
node* sortedMerge(node* a, node* b);
void splitList(node* source, node** frontRef, node** backRef);

int main(void) {
    node* head = NULL;
    int choice, value;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at tail: ");
                scanf("%d", &value);
                insertAtTail(&head, value);
                break;
            case 2:
                printf("Sorting the list...\n");
                mergeSort(&head);
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

// Function to display the menu
void displayMenu() {
    printf("\n--- Singly Linked List Menu ---\n");
    printf("1. Insert at Tail\n");
    printf("2. Sort List\n");
    printf("3. Display List\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Function to insert a node at the tail
void insertAtTail(node** headRef, int newData) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = newData;
    new_node->next = NULL;

    if (*headRef == NULL) {
        *headRef = new_node;
    } else {
        node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("%d inserted at tail.\n", newData);
}

// Function to perform merge sort on the linked list
void mergeSort(node** headRef) {
    node* head = *headRef;
    node* a;
    node* b;

    // Base case: length 0 or 1
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    // Split the list into two halves
    splitList(head, &a, &b);

    // Recursively sort the two halves
    mergeSort(&a);
    mergeSort(&b);

    // Merge the two sorted halves
    *headRef = sortedMerge(a, b);
}

// Function to merge two sorted lists
node* sortedMerge(node* a, node* b) {
    node* result = NULL;

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

// Function to split the list into two halves
void splitList(node* source, node** frontRef, node** backRef) {
    node* fast;
    node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Function to display the list
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

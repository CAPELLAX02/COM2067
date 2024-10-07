#include <stdio.h>
#include <stdlib.h>

// Define the queue node structure
typedef struct q {
    char data;
    struct q* next;
} queueNode;

// Function prototypes
void printQueue(queueNode* head);
int isEmpty(queueNode* head);
void enqueue(queueNode** head, queueNode** tail, char value);
char dequeue(queueNode** head, queueNode** tail);
void instructions(void);

int main(void) {
    // Initialize the head pointer
    queueNode* head = NULL;
    
    // Initialize the tail pointer
    queueNode* tail = NULL;

    // Char input by user
    char item = '\0';

    // User's menu choice
    int choice = 0;

    // Display the menu
    instructions();
    printf("? ");
    scanf("%d", &choice);

    // Loop while user does not enter 3
    while (choice != 3) {
        switch (choice) {
            case 1: // Enqueue value
                printf("Enter a character: ");
                scanf(" %c", &item);
                enqueue(&head, &tail, item);
                printQueue(head);
                break;

            case 2: // Dequeue value
                if (!isEmpty(head)) {
                    item = dequeue(&head, &tail);
                    printf("%c has been dequeued.\n", item);
                } else {
                    puts("Queue is empty, nothing to dequeue.");
                }
                printQueue(head);
                break;

            default:
                puts("Invalid choice.");
                instructions();
                break;
        }
        printf("? ");
        scanf("%d", &choice);
    }
    puts("End of run.");
}

// Display program instructions to user
void instructions(void) {
    puts("Enter your choice:\n"
         "1 to add an item to the queue\n"
         "2 to remove an item from the queue\n"
         "3 to end");
}

// Insert a node at the queue tail (enqueue)
void enqueue(queueNode** head, queueNode** tail, char value) {  
    queueNode* newNode = (queueNode*) malloc(sizeof(queueNode));

    if (newNode != NULL) { // If space is available
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty(*head)) { // If queue is empty, new node is the head
            *head = newNode;
        } else { // Otherwise, link new node at the end
            (*tail)->next = newNode;
        }
        *tail = newNode; // Update tail to point to the new node
    } else {
        printf("%c not inserted. No memory available.\n", value);  
    }
}

// Remove a node at the queue tail (dequeue)
char dequeue(queueNode** head, queueNode** tail) {
    // Check if the queue is empty
    if (isEmpty(*head)) return '\0';

    // Get the value from the head
    char value = (*head)->data;

    // Temporary pointer to hold the head node
    queueNode* temp = *head;

    // Move head to the next node
    *head = (*head)->next;

    // If the queue is empty after dequeue,
    if (*head == NULL) {
        *tail = NULL; // Set tail to NULL
    }

    free(temp); // Free the memory of the old head node

    return value;
}

// Return 1 if the queue is empty, 0 otherwise
int isEmpty(queueNode* head) {
    return head == NULL;
}

// Print the queue
void printQueue(queueNode* current) {   
    if (current == NULL) { // If queue is empty
        puts("Queue is empty.");
    } else {
        printf("The queue is:\n");
        while (current != NULL) { // Traverse the queue   
            printf("%c", current->data);
            if (current->next != NULL) {
                printf(" --> ");
            }
            current = current->next;
        }   
        puts(" --> NULL");
    }
}

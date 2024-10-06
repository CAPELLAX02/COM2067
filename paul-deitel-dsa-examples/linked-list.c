#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    char data;
    struct n *next;
} node;

// Function prototypes
void insert(node **sPtr, char value);
char delete(node **sPtr, char value);
int isEmpty(node *sPtr);
void printList(node *currentPtr);
void instructions(void);

int main(void) {
    node *startPtr = NULL;  // Initially, there are no nodes
    char item = '\0';       // Char entered by user
    int choice = 0;         // User's choice

    instructions();         // Display the menu
    printf("? ");
    scanf("%d", &choice);

    // Loop while user does not choose 3
    while (choice != 3) {
        switch (choice) {
            case 1:  // Insert an element
                printf("Enter a character: ");
                scanf(" %c", &item);
                insert(&startPtr, item);  // Insert item in list
                printList(startPtr);
                break;

            case 2:  // Delete an element
                if (!isEmpty(startPtr)) {  // If list is not empty
                    printf("Enter character to be deleted: ");
                    scanf(" %c", &item);
                    
                    // If character is found, remove it
                    if (delete(&startPtr, item)) {
                        printf("%c deleted.\n", item);
                        printList(startPtr);
                    } else {
                        printf("%c not found.\n", item);
                    }
                } else {
                    puts("List is empty.");
                }
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
         "1 to insert an element into the list.\n"
         "2 to delete an element from the list.\n"
         "3 to end.");
}

// Insert a new value in the list in sorted order
void insert(node **sPtr, char value) {
    node *newNode = (node *) malloc(sizeof(node));  // Create a new node
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;

        node *previous = NULL;
        node *current = *sPtr;

        // Find the correct location in the list
        while (current != NULL && value > current->data) {
            previous = current;
            current = current->next;
        }

        // Insert at the beginning of the list
        if (previous == NULL) {
            newNode->next = *sPtr;
            *sPtr = newNode;
        } 
        // Insert between previous and current
        else {
            previous->next = newNode;
            newNode->next = current;
        }
    } else {
        printf("No memory available.\n");
    }
}

// Delete a value from the list
char delete(node **sPtr, char value) {
    if (*sPtr == NULL) {
        return '\0';
    }

    node *previous = NULL;
    node *current = *sPtr;

    // Find the value to delete
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    // If value found, delete the node
    if (current != NULL) {
        if (previous == NULL) {
            *sPtr = (*sPtr)->next;  // Delete first node
        } else {
            previous->next = current->next;  // Bypass the node to delete
        }
        free(current);
        return value;
    }

    return '\0';  // Value not found
}

// Return 1 if the list is empty, 0 otherwise
int isEmpty(node *sPtr) {
    return sPtr == NULL;
}

// Print the list
void printList(node *currentPtr) {
    if (currentPtr == NULL) {
        puts("List is empty.");
    } else {
        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->next;
        }
        puts("NULL");
    }
}

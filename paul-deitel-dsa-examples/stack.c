// A simple stack program (LIFO - Last In First Out)
#include <stdio.h>
#include <stdlib.h>

// Define the stack node structure
typedef struct s {
    int data;
    struct s* next;
} stack;

// Function prototypes
void push(stack** topPtr, int value);
int pop(stack** topPtr);
int isEmpty(stack* topPtr);
void printStack(stack* currentPtr);
void instructions(void);

int main(void) {
    // Points to stack top
    stack* stackPtr = NULL;

    // Integer input by user
    int value = 0;

    // User's menu choice
    int choice = 0;

    // Display the menu
    instructions();
    printf("?: ");
    scanf("%d", &choice);

    // While user does not enter 3
    while (choice != 3) {
        switch (choice) {
            case 1: // Push value onto stack
                printf("Enter an integer: ");
                scanf("%d", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;
            
            case 2: // Pop value off stack
                if (!isEmpty(stackPtr)) { // If stack is not empty
                    printf("The topped value is %d.\n", pop(&stackPtr));
                } else {
                    puts("Stack is empty, nothing to pop.");
                }
                printStack(stackPtr);
                break;     

            default:
                puts("Invalid choice.");
                instructions();
                break;
        }
        printf("?: ");
        scanf("%d", &choice);
    }
    puts("End of run.");
}

// Display program instructions to user
void instructions(void) {
    puts("Enter choice:\n"
         "1 to push a value on the stack\n"
         "2 to pop a value off the stack\n"
         "3 to end program");
}

// Push a new value onto the stack
void push(stack** topPtr, int value) {
    stack* newPtr = malloc(sizeof(stack)); // Create a new node
    if (newPtr != NULL) {
        newPtr->data = value;
        newPtr->next = *topPtr; // Link new node to the current top
        *topPtr = newPtr; // Update the stack's top pointer
    } else {
        printf("%d not inserted. No memory available.\n", value);
    }
}


// Pop a value from the stack
int pop(stack** topPtr) {
    if (*topPtr == NULL) {
        puts("Stack is empty, nothing to pop.");
        return -1;
    }

    stack* temp = *topPtr; // Temporary pointer to top node
    int poppedValue = (*topPtr)->data; // Get the top value
    *topPtr = (*topPtr)->next; // Update top to the next node
    free(temp);
    return poppedValue;
}


// Print the stack
void printStack(stack* currentPtr) {
    if (currentPtr == NULL) { // If stack is empty
        puts("The stack is empty.");
    } else {
        puts("The stack is:");
        while (currentPtr != NULL) { // While not the end of the stack
            printf("%d ---> ", currentPtr->data);
            currentPtr = currentPtr->next;
        }
        puts("NULL");
    }
}

// Return 1 if the stack is empty, 0 otherwise
int isEmpty(stack* topPtr) {
    return topPtr == NULL;
}
// Dynamic (resizable) stack implementation example using array to store the data
#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicStack {
    int *data;
    int top;
    int capacity;
} dStack;

void initializeDynamicStack(dStack *stack, int capacity);
void incrementCapacity(dStack *stack);
int isEmpty(dStack *stack);
void push(dStack *stack, int value);
int pop(dStack *stack);
int peek(dStack *stack);
void displayDynamicStack(dStack *stack);

int main(void) {
    dStack stack;
    int initialCapacity = 2;
    initializeDynamicStack(&stack, initialCapacity);

    int choice, value;

    do {
        printf("\nDynamic Stack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("The value %d popped from the stack\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("The peek value of the stack is %d\n", value);
                }
                break;
            case 4:
                displayDynamicStack(&stack);
                break;
            case 5:
                puts("End of run.");
                break;
            default:
                puts("Invalid choice. Try again.");
                break;
        }

    } while (choice != 5);

    free(stack.data);

    return 0;
}

void initializeDynamicStack(dStack *stack, int capacity) {  
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*) malloc(stack->capacity * sizeof(int));
}

void incrementCapacity(dStack *stack) {
    stack->capacity *= 2;
    stack->data = (int*) realloc(stack->data, stack->capacity * sizeof(int));
    printf("Stack capacity doubled to %d (Stack overflow prevented.)\n", stack->capacity);
}

int isEmpty(dStack *stack) {
    return stack->top == -1;
}

void push(dStack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        incrementCapacity(stack);
    }
    stack->data[++stack->top] = value;
    printf("The value %d pushed onto the stack.\n", value);
}

int pop(dStack *stack) {
    if (isEmpty(stack)) {
        puts("Stack underflow!.");
        return -1;
    }
    return stack->data[stack->top--];
} 

int peek(dStack *stack) {
    if (isEmpty(stack)) {
        puts("The stack is empty.");
        return -1;
    }
    return stack->data[stack->top];
}

void displayDynamicStack(dStack *stack) {
    if (isEmpty(stack)) {
        puts("The stack is empty.");
    } else {
        printf("Current stack elements: ");
        // for (int i = 0; i <= stack->top; i++) {
        //     printf("%d ", stack->data[i]);
        // }
        // Below code is more realistic because it is a "stack" (FIFO).
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->data[i]);
        }
        puts("");
    }
}
// Array-based stack implementation example
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initialize(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void display(Stack *stack);

int main(void) {
    Stack stack;
    initialize(&stack);

    int choice, value;

    do {
        printf("\nStack Operations Menu:\n");
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
                    printf("The top value of the stack is %d\n", value);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                puts("End of run.");
                break;
            default:
                puts("Invalid choice. Try again.");
        }

    } while (choice != 5);

    return 0;
}

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        puts("Stack overflow!");
    } else {
        stack->data[++stack->top] = value;
        printf("The value %d pushed onto the stack.\n", value);
    }
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        puts("Stack underflow!");
        return -1;
    } else {
        return stack->data[stack->top--];
    }
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        puts("Stack is empty.");
        return -1;
    } else {
        return stack->data[stack->top];
    }
}

void display(Stack *stack) {    
    if (isEmpty(stack)) {
        puts("Stack is empty.");
    } else {
        printf("Current stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->data[i]);
        }
        puts("");
    }
}
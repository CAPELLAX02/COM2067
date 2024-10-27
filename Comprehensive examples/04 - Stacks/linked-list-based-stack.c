#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list based stack
typedef struct Node {
    int data;
    struct Node *next;
} node;

void push(node **top, int value);
int pop(node **top);
int peek(node *top);
void display(node *top);

int main(void) {
    node *top = NULL;
    int choice, value;

    do {
        printf("\nLinked-List Stack Operations Menu:\n");
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
                push(&top, value);
                break;
            case 2:
                value = pop(&top);
                if (value != -1) {
                    printf("Popped %d from the stack\n", value);
                }
                break;
            case 3:
                value = peek(top);
                if (value != -1) {
                    printf("Top of the stack is %d\n", value);
                }
                break;
            case 4:
                display(top);
                break;
            case 5:
                printf("End of run.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    // Free remaining nodes
    while (top != NULL) {
        node *temp = top;
        top = top->next;
        free(temp);
    }

    return 0;    
}

void push(node **top, int value) {
    node *newNode = (node*) malloc(sizeof(node));

    newNode->data = value;
    newNode->next = *top;
    *top = newNode;

    printf("The value %d pushed onto the stack\n", value); 
}

int pop(node **top) {
    if (*top == NULL) {
        puts("Stack underflow!");
        return -1;
    }
    node *temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

int peek(node *top) {
    if (top == NULL) {
        puts("The stack is empty.");
        return -1;
    }
    return top->data;
}

void display(node *top) {
    if (top == NULL) {
        puts("The stack is empty.");
    } else {
        printf("Current stack elements: ");
        while (top != NULL) {
            printf("%d ", top->data);
            top = top->next;
        }
        puts("");
    }
}
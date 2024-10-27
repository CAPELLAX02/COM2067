#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *collection;
    int capacity;
    int size;
} Stack;

Stack *createStack(int capacity);
void destroyStack(Stack *stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item);

int main(void) {
    Stack *stack = createStack(5);

    if (stack == NULL) {
        printf("Error creating stack.\n");
        return 1;
    }

    if (isEmpty(stack)) printf("Stack is empty.\n");

    push(stack, 2);
    
    printf("Stack size: %d\n", stack->size);

    push(stack, 9);
    push(stack, 4);
    push(stack, 7);

    if (isFull(stack)) printf("Stack is full.\n");

    push(stack, 8);

    printf("Stack size: %d\n", stack->size);

    if (isFull(stack)) printf("Stack is full.\n");

    bool tryPush = push(stack, 5);

    if (tryPush == false) printf("Push failed.\n");

    int peekVal = 0;
    peek(stack, &peekVal);
    printf("Peek value: %d\n", peekVal);

    int popVal = 0;
    for (int i = 0; i < 5; i++) {
        pop(stack, &popVal);
        printf("Popped value: %d\n", popVal);
    }

    bool tryPop = pop(stack, &popVal);
    if (tryPop == false) printf("Pop failed.\n");

    destroyStack(stack);
    return 0;
}

Stack *createStack(int capacity) {
    if (capacity <= 0) return NULL;

    Stack *stack = malloc(sizeof(Stack));

    if (stack == NULL) return NULL;

    stack->collection = malloc(sizeof(int) * capacity);

    if (stack->collection == NULL) {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void destroyStack(Stack *stack) {
    free(stack->collection);
    free(stack);
}

bool isFull(Stack *stack) {
    return stack->capacity == stack->size;
}

bool isEmpty(Stack *stack) {
    return stack->size == 0;
}

bool push(Stack *stack, int item) {
    if (isFull(stack)) return false;

    stack->collection[stack->size] = item;
    stack->size++;

    return true;
}

bool peek(Stack *stack, int *item) {
    if (isEmpty(stack)) return false;

    *item = stack->collection[stack->size - 1];

    return true;
}

bool pop(Stack *stack, int *item) {
    if (isEmpty(stack)) return false;

    stack->size--;
    *item = stack->collection[stack->size];

    return true;
}
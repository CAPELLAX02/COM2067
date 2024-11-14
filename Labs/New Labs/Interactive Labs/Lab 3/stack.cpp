#include <stdio.h>

#define MAX_SIZE 5 // Maximum size of the stack

int stack[MAX_SIZE]; // Array to implement the stack
int top = -1; // Variable to keep track of the top of the stack, initialized as -1 indicating an empty stack

// Function to push an element onto the stack
void push(int data) {
    if (top == MAX_SIZE - 1) { // Check for stack overflow
        printf("You cannot push! Overflow stack!\n");
        return;
    }
    top++; // Move the top pointer to the next position
    stack[top] = data; // Add the data to the stack at the current top position
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) { // Check if the stack is empty
        printf("Cannot pop! Stack is empty!\n");
        return -1;
    }
    int data = stack[top]; // Get the data at the top of the stack
    top--; // Move the top pointer down to the previous position
    return data; // Return the popped data
}

int isEmpty(int top) {
    return (top == -1);
}

int isFull(int top) {
    return (top == MAX_SIZE - 1);
}

// Function to peek the top element of the stack
int peek() {
    if (top == -1) { // Check if the stack is empty
        printf("Cannot peek! Stack is empty!\n");
        return -1;
    }
    return stack[top]; // Return the top element without removing it
}

int main() {
	
	 if(peek()!=-1){
    	printf("Peek elements is %d. \n", peek());
	}
	

    if(isEmpty){
    	printf("Stack is empty..\n");
	}
	pop();
    push(1);
    push(2);
    push(4);
    push(5);
    push(3); 
    
    if(isFull){
    	printf("Stack is full..\n");
	}
	push(11);
	printf("Peek elements is %d. \n", peek());

    printf("Elements in the stack are: ");

    while (top != -1) {
        printf("\n %d ", pop()); // Display the popped element
    }
    printf("\n");
    return 0;
}


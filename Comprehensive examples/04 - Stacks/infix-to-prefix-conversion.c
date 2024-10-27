/**
 * The Shunting-yard algorithm works by creating an operator stack in which the operators are added based on their 
 * Order of Operations precedence (PEMDAS), and an output queue which creates the postfix notation that can easily 
 * be calculated. You will evaluate each item in the expression from left to right.
 */

// EXAMPLE INPUT 1:         A+B*C
// CORRESPONDING OUTPUT 1:  ABC*+

// EXAMPLE INPUT 2:         (A+B)*C
// CORRESPONDING OUTPUT 2:  AB+C*

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} charStack;

void initializeStack(charStack *stack) {
    stack->top = -1;
}

int isEmpty(charStack *stack) {
    return stack->top == -1;
}

void push(charStack *stack, char value) {
    stack->data[++stack->top] = value;
}

char pop(charStack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

char peek(charStack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char *expression) {
    charStack stack;
    initializeStack(&stack);
    
    char postfix[MAX];
    int j = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } 
        else if (ch == '(') {
            push(&stack, ch);
        } 
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from stack
        }
        else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    // Pop remaining operators from stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main(void) {
    char expression[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", expression);

    infixToPostfix(expression);

    return 0;
}

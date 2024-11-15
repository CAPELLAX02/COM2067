#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

// Function prototypes
void merge(struct node **mergedListPtr, struct node *x1, struct node *x2);
struct node *createNode(int value);
void appendNode(struct node **head, int value);
void printList(struct node *head);

int main(void) {
    struct node *x1 = NULL;
    struct node *x2 = NULL;
    struct node *mergedList = NULL;

    appendNode(&x1, 1);
    appendNode(&x1, 3);
    appendNode(&x1, 5);
    appendNode(&x1, 7);
    appendNode(&x1, 9);

    appendNode(&x2, 2);
    appendNode(&x2, 4);
    appendNode(&x2, 6);
    appendNode(&x2, 8);
    appendNode(&x2, 10);

    merge(&mergedList, x1, x2);

    printf("x1 list:     ");
    printList(x1);

    printf("x2 list:     ");
    printList(x2);

    printf("merged list: ");
    printList(mergedList);
}

void merge(struct node **mergedListPtr, struct node *x1, struct node *x2) {
    *mergedListPtr = (struct node*) malloc(sizeof(struct node));;
    struct node **current = mergedListPtr;

    while (x1 != NULL && x2 != NULL) {
        *current = (struct node *)malloc(sizeof(struct node));
        (*current)->value = x1->value + x2->value;
        (*current)->next = NULL;
        current = &((*current)->next);

        x1 = x1->next;
        x2 = x2->next;
    }
}

struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct node** head, int value) {
    struct node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

void printList(struct node *head) {
    if (head == NULL) {
        puts("List is empty.");
        return;
    }

    struct node *temp = head;

    do {
        printf("%d\n", temp->value);
        temp = temp->next;
    } while (temp != head);
}

struct node *insertEnd(struct node *head, int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->value = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return head;
    }

    struct node *temp = head->prev;

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;

    return head;
}

struct node *insertBeg(struct node *head, int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->value = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return head;
    }

    struct node *temp = head->prev;

    newNode->next = head;
    newNode->prev = temp;
    temp->next = newNode;
    head->prev = newNode;

    head = newNode;

    return head;
}

int main(void) {
    struct node *root = NULL;

    root = insertEnd(root, 10);
    root = insertEnd(root, 20);
    root = insertEnd(root, 30);
    root = insertEnd(root, 40);
    root = insertEnd(root, 50);

    root = insertBeg(root, 9);
    root = insertBeg(root, 8);
    root = insertBeg(root, 7);
    root = insertBeg(root, 6);
    root = insertBeg(root, 5);

    printList(root);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *head;
};

void addNode(struct node **root, int newData) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (*root == NULL) {
        newNode->data = newData;
        newNode->head = NULL;
        newNode->next = NULL;
    }

    struct node *temp = *root;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    newNode->data = newData;
    newNode->head = *root;
    newNode->next = NULL;
    
    temp->next = newNode;
}

void printList(struct node *root) {
    if (root == NULL) puts("List is empty.");
    while (root != NULL) {
        printf("(data: %d --- head:%d) \n", root->data, root->head->data);
        root = root->next;
    }
}

int main(void) {
    struct node *root = (struct node *)malloc(sizeof(struct node));

    root->head = root;

    printList(root);

    printf("Enter the size: ");
    int size;
    scanf("%d", &size);

    for (int i = 1; i <= size; i++) {
        addNode(&root, i * 10);
    }

    printList(root);
}

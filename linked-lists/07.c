#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int x;
    struct n* next;
} node;

int main(void) {
    node* root = (node*) malloc(sizeof(node));

    root->x = 10;
    root->next = NULL;

    node* second = (node*) malloc(sizeof(node));
    node* third = (node*) malloc(sizeof(node));
    node* last = (node*) malloc(sizeof(node));

    root->next = second;

    second->x = 20;
    second->next = third;

    third->x = 30;
    third->next = last;

    last->x = 50;
    last->next = NULL;

    node* iter = root;
    while (iter != NULL) {
        printf("%d ", iter->x); // output: 10 20 30 50
        iter = iter->next;
    }
    printf("\n");


    iter = root; // reset iter to root again
    for (int i = 0; i < 2; i++) {
        iter = iter->next;   
    }
    node* temp = (node*) malloc(sizeof(node));
    temp->x = 40;
    temp->next = iter->next;
    iter->next = temp;

    iter = root; // reset iter to root again
    while (root != NULL) {
        printf("%d ", root->x); // new output: 10 20 30 40 50
        root = root->next;
    }

}
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

// The following function appends the linked list pointed to by "b" to the end of the linked list pointed to by "a"

// Purpose: Concatenate list "b" to the end of list "a" and clear list "b".

void function1(struct node** a, struct node** b) {
    struct node* cur;
    if (*a == NULL) {
        *a = *b;
    } else {
        cur = *a;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = *b;
    }
    *b = NULL;
}

// If the list "a" is empty (*a == NULL), it simply sets "*a" to point to "*b".

// If "a" is not empty, it finds the last node in list a and links it to the beginning of list "b".

// Finally, it sets "*b" to NULL, effectively moving all nodes from list "b" to the end of list "a".

#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

// The following function reverses the linked list pointed by "head".

// Purpose: Reverse the order of nodes in the linked list.

static void function2(struct node** head) {
    struct node *r = NULL;
    struct node *cur = *head;
    struct node *n;

    while (cur != NULL) {
        n = cur->next;
        cur->next = r;
        r = cur;
        cur = n;
    }
    *head = r;
}

// It iterates through the list and reverses the "next" pointers of each node so that they point to the previous node.

// The "r" pointer keeps track of the new head of the reversed list, which is eventually assigned back to "*head".

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// The following function removes consecutive duplicate nodes in a sorted linked list.

// Purpose: Remove duplicate nodes from a sorted linked list, ensuring each element appears only once.

void function3(struct node* head) {
    struct node *cur = head;

    if (cur == NULL) return;

    while (cur->next != NULL) {
        if (cur->data == cur->next->data) {
            struct node *nextNext = cur->next->next;
            free(cur->next);
            cur->next = nextNext;
        } 
        else {
            cur = cur->next;
        }
    }
}

// It traverses the list, checking if the data of the current node is equal to the data of the next node.

// If they are equal, it removes the next node by adjusting the next pointer and freeing the duplicate node.

//If they are not equal, it moves to the next node.

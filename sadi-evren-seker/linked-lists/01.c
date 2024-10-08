/**
 * Introduction to linked lists
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int number;
  struct Node* next;
} node;

int main(void) {
  node* head = (node*) malloc(sizeof(node));
  node* second = (node*) malloc(sizeof(node));
  node* third = (node*) malloc(sizeof(node));

  head->number = 10;
  head->next = second;

  second->number = 20;
  second->next = third;

  third->number = 30;
  third->next = NULL;

  node* iter = head;

  for (int i = 1; iter != NULL; iter = iter->next, i++) {
    printf("%d. node contains: %d\n", i, iter->number);
  }

  free(head);
  free(second);
  free(third);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
  int x;
  struct n* next;
} node;

void printLinkedList(node* r) {
  while (r != NULL) {
    printf("%d ", r->x);
    r = r->next;
  }
}

int main(void) {
  // Allocate and initialize the root node
  node* root = (node*) malloc(sizeof(node));
  root->x = 10;
  root->next = NULL;

  // Use iter to build the rest of the list
  node* iter = root;
  for (int i = 2; i <= 5; i++) {
    iter->next = (node*) malloc(sizeof(node));
    iter = iter->next;
    iter->x = i * 10;
    iter->next = NULL;
  }

  // Print the linked list
  printLinkedList(root);
  // output: 10 20 30 40 50

  // Free all allocated memory
  iter = root;
  node* temp;
  while (iter != NULL) {
    temp = iter;
    iter = iter->next;
    free(temp);
  }
}

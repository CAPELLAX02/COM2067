// Modularize the adding functionality using external 'addElementAtTheEndOfTheLinkedList' function

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

void addElementAtTheEndOfTheLinkedList(node* r, int num) {
  // Traverse to the end of the list
  while (r->next != NULL) {
    r = r->next;
  }

  // Allocate a new node at the end
  r->next = (node*) malloc(sizeof(node));
  r->next->x = num;
  r->next->next = NULL;
}

int main(void) {
  // Allocate and initialize the root node
  node* root = (node*) malloc(sizeof(node));
  root->x = 10;
  root->next = NULL;

  // Add elements to the list using the external function
  for (int i = 2; i <= 5; i++) {
    addElementAtTheEndOfTheLinkedList(root, i * 10);
  }

  // Print the linked list
  printLinkedList(root);
  // output: 10 20 30 40 50

}

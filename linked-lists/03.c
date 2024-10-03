// In this example, we attempt to add the 4th node to our linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int number;
  struct Node* next;
} node;

int main(void) {
  
  // Define the nodes
  node* head = (node*) malloc(sizeof(node));
  node* second = (node*) malloc(sizeof(node));
  node* third = (node*) malloc(sizeof(node));

  // Fill in their number fields, and set the next fields to point to the next node
  head->number = 10;
  head->next = second;

  second->number = 20;
  second->next = third;

  third->number = 30;
  third->next = NULL;

  // Iterate over the linked list to print numbers
  node* iter = head;

  while (iter != NULL) {  
    printf("%d ", iter->number);
    iter = iter->next;
  }
  printf("\n"); // output: 10 20 30

  // Now, define the 4th node
  node* fourth = (node*) malloc(sizeof(node));
  fourth->number = 40;
  fourth->next = NULL;

  // Reset iter to head to traverse again and find the last node
  iter = head;

  // Traverse the list to find the last node (currently 'third')
  while (iter->next != NULL) {
    iter = iter->next;
  }

  // Let the last node's (third's) next point to the 4th node
  iter->next = fourth;

  // Iterate over the linked list again and see the new number this time
  iter = head;
  while (iter != NULL) {
    printf("%d ", iter->number);
    iter = iter->next;
  }
  printf("\n"); // output: 10 20 30 40

  // Free all allocated memory
  free(head);
  free(second);
  free(third);
  free(fourth);

  return 0;
}

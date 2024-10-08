#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int number;
  struct Node* next;
} node;

/**
 * Quick Note:
 * - Arrays can be accessed "ramdomly", whereas
 * - linked lists can be accessed "sequentially"
 */

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

  /**
   * 
   * Our linked lists actually look like this:
   *  
   *  first        second       third 
   *  node         node         node
   * --------     --------     --------
   * -  10  -     -  20  -     -  30  -
   * --------     --------     --------
   * - next -     - next -     - next - ----> NULL
   * --------     --------     --------
   * 
   * "The first 'next' field point out the second node, and smilarly, the second 'next' field points out the third node; yet the last (3rd) 'next' field is pointing out 'NULL' because this is the end of our linked list thus far."
   * 
   */

  node* iter = head;

  while (iter != NULL) {  
    printf("%d ", iter->number);
    iter = iter->next;
  } // output: 10 20 30

  free(head);
  free(second);
  free(third);
}
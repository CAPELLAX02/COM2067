// exact same code with the first-tree.c

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} node;

node* createNode(int newData) {
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode) {
        puts("Memory allocation failed.");
        exit(1);
    }
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderTraversal(node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main(void) {
    node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    puts("In-order Traversal of the Tree:");
    inOrderTraversal(root);
    // OUTPUT:

    puts(""); 

    puts("Pre-order Traversal of the Tree:");
    preOrderTraversal(root);
    // OUTPUT: 

    puts("");

    puts("Post-order Traversal of the Tree:");
    postOrderTraversal(root);
    // OUTPUT:

    puts("");
}

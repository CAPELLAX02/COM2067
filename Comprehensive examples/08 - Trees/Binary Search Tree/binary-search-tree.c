// binary search tree is basically a binary tree
// but it holds the following properties:
// 1. left node's value > root node's value for every subtree
// 2. right node's value > root node's value for every subtree

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

node *insertNode(node *root, int newData) {
    if (root == NULL)
        return createNode(newData);
    if (newData < root->data)
        root->left = insertNode(root->left, newData);
    else if (newData > root->data)
        root->right = insertNode(root->right, newData);
    return root;
}

int searchValue(node *root, int target) {
    if (root == NULL) 
        return 0;
    if (target == root->data)
        return 1;
    else if (target < root->data)
        return searchValue(root->left, target);
    else
        return searchValue(root->right, target);
}

node *findMin(node *root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

node *findMax(node *root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

node *deleteNode(node *root, int target) {
    if (root == NULL) {
        return root;
    }
    if (target < root->data) {
        root->left = deleteNode(root->left, target);
    }
    else if (target > root->data) {
        root->right = deleteNode(root->right, target);
    }
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else {
            // node with two children: get the in-order successor
            node *temp = findMin(root->right);
            // copy the successor's data
            root->data = temp->data;
            // delete the successor
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// (LNR)
void inOrderTraversal(node *root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// (NLR)
void preOrderTraversal(node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// (LRN)
void postOrderTraversal(node *root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}


int main(void) {
    node *root = NULL;

    // Insert values into the binary search tree
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 10);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 14);
    root = insertNode(root, 13);

    // Demonstrate traversals
    printf("In-order Traversal:\n");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal:\n");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal:\n");
    postOrderTraversal(root);
    printf("\n");

    // Demonstrate search
    int target = 6;
    if (searchValue(root, target)) {
        printf("Target %d found in the BST.\n", target);
    } else {
        printf("Target %d not found in the BST.\n", target);
    }

    // Demonstrate deletion
    printf("Deleting node with key 10...\n");
    root = deleteNode(root, 10);

    printf("In-order Traversal after Deletion:\n");
    inOrderTraversal(root);
    printf("\n");
}

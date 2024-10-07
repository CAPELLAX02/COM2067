// Creating and traversing a binary tree preorder, inorder, and postorder
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the binary tree node structure
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} treeNode;

// Function prototypes
void insert(treeNode** tree, int value);
void inOrder(treeNode* tree);
void preOrder(treeNode* tree);
void postOrder(treeNode* tree);

int main(void) {
    // Initialize the root pointer as NULL
    treeNode* root = NULL;

    // Seed the random number generator
    srand(time(NULL));

    puts("The numbers being placed in the tree are:");

    for (int i = 0; i < 10; i++) {
        int value = rand() % 15;
        printf("Trying to insert: %d\n", value);
        insert(&root, value);
    }

    // Pre-order traversal
    printf("\nThe pre-order traversal is:\n");
    preOrder(root);

    // In-order traversal
    printf("\nThe in-order traversal is:\n");
    inOrder(root);

    // Post-order traversal
    printf("\nThe post-order traversal is:\n");
    postOrder(root);

    printf("\n");
}

// Insert node into tree
void insert(treeNode** tree, int value) {   
    if (*tree == NULL) { // if tree is empty
        *tree = (treeNode*) malloc(sizeof(treeNode));

        // if memory was allocated, then assign data
        if (*tree != NULL) {     
            (*tree)->data = value;
            (*tree)->left = NULL;
            (*tree)->right = NULL;
            printf("Inserted: %d\n", value);  // Show when value is inserted
            puts("------------------------------------");
        }
        else {
            printf("%d not inserted. No memory available.\n", value);
            puts("------------------------------------");
        }
    }
    else {
        if (value < (*tree)->data) { // value goes in left subtree
            printf("%d is less than %d, going left.\n", value, (*tree)->data);
            insert(&((*tree)->left), value);
        }
        else if (value > (*tree)->data) { // value goes in right subtree
            printf("%d is greater than %d, going right.\n", value, (*tree)->data);
            insert(&((*tree)->right), value);
        }
        else { // duplicate data value ignored
            printf("Duplicate value %d ignored.\n", value);
            puts("------------------------------------");
        }
    }
}

// In-order traversal of the tree
void inOrder(treeNode* tree) {
    // if tree is not empty, then traverse
    if (tree != NULL) {
        inOrder(tree->left);
        printf("%d ", tree->data);
        inOrder(tree->right);
    }
}

// Pre-order traversal of the tree
void preOrder(treeNode* tree) {
    // if tree is not empty, then traverse
    if (tree != NULL) {
        printf("%d ", tree->data);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

// Post-order traversal of the tree
void postOrder(treeNode* tree) {
    // if tree is not empty, then traverse
    if (tree != NULL) {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ", tree->data);
    }
}

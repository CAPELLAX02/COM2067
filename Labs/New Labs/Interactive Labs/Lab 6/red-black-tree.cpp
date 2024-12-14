#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int data;
    Color color;
    struct Node* left, * right, * parent;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->color = RED; // Yeni dügüm her zaman kirmizi olarak baslar
    node->left = node->right = node->parent = NULL;
    return node;
}

Node* rotateLeft(Node* root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
    return root;
}

Node* rotateRight(Node* root, Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
    return root;
}

Node* fixViolation(Node* root, Node* z) {
    while (z != root && z->parent->color == RED) {
        Node* grandParent = z->parent->parent;
        if (z->parent == grandParent->left) {
            Node* uncle = grandParent->right;
            if (uncle != NULL && uncle->color == RED) {
                grandParent->color = RED;
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z = grandParent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    root = rotateLeft(root, z);
                }
                z->parent->color = BLACK;
                grandParent->color = RED;
                root = rotateRight(root, grandParent);
            }
        } else {
            Node* uncle = grandParent->left;
            if (uncle != NULL && uncle->color == RED) {
                grandParent->color = RED;
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z = grandParent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    root = rotateRight(root, z);
                }
                z->parent->color = BLACK;
                grandParent->color = RED;
                root = rotateLeft(root, grandParent);
            }
        }
    }
    root->color = BLACK;
    return root;
}

Node* insertNode(Node* root, Node* node) {
    if (root == NULL) return node;

    if (node->data < root->data) {
        root->left = insertNode(root->left, node);
        root->left->parent = root;
    } else if (node->data > root->data) {
        root->right = insertNode(root->right, node);
        root->right->parent = root;
    }

    return root;
}

Node* insert(Node* root, int data) {
    Node* node = createNode(data);
    root = insertNode(root, node);
    return fixViolation(root, node);
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d(%s) ", root->data, root->color == RED ? "RED" : "BLACK");
    inorderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 25);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef enum {
     RED, 
     BLACK 
} Color;

typedef struct RBNode {
    int key;
    Color color;
    struct RBNode *left;
    struct RBNode *right;
    struct RBNode *parent;
} node;

static node *NIL;
static node *root;

// Function prototypes
void rbInsert(int key);
void rbInsertFixup(node *z);
void leftRotate(node *x);
void rightRotate(node *y);
void IOTraversal(node *root);
void levelOrderPrint(node *root);
void enqueue(node **queue, int *rear, node *n);
node *dequeue(node **queue, int *front, int rear);

int main(void) {
    NIL = (node*) malloc(sizeof(node));
    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = NULL;

    root = NIL;
    
    int val;
    for (;;) {
        if (scanf("%d", &val) != 1) break;
        if (val == -1) break;
        rbInsert(val);
    }

    IOTraversal(root);
    puts("");
    levelOrderPrint(root);

    return 0;
}

void IOTraversal(node *root) {
    if (root == NIL) return;
    IOTraversal(root->left);
    printf("%d\n", root->key);
    IOTraversal(root->right);
}

node* createNode(int x) {
    node *n = (node*) malloc(sizeof(node));
    n->key = x;
    n->color = RED;
    n->left = NIL;
    n->right = NIL;
    n->parent = NIL;
    return n;
}

void rbInsert(int key) {
    node *z = createNode(key);
    node *y = NIL;
    node *x = root;

    while (x != NIL) {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }

    z->parent = y;

    if (y == NIL) root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;

    z->left = NIL;
    z->right = NIL;
    z->color = RED;

    rbInsertFixup(z);
}


void rbInsertFixup(node *z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            node *y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } 
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } 
        else {
            node *y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } 
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

void leftRotate(node *x) {
    node *y = x->right;
    x->right = y->left;

    if (y->left != NIL) y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(node *y) {
    node *x = y->left;
    y->left = x->right;

    if (x->right != NIL) x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NIL) root = x;
    else if (y == y->parent->right) y->parent->right = x;
    else y->parent->left = x;

    x->right = y;
    y->parent = x;
}

void levelOrderPrint(node *root) {
    if (root == NIL) return;

    node **queue = (node**) malloc(sizeof(node*) * 1000);

    int front = 0;
    int rear = 0;

    enqueue(queue, &rear, root);

    while (front < rear) {
        int levelCount = rear - front;
        if (levelCount == 0) break;

        int i;
        int printedSomething = 0;
        for (i = 0; i < levelCount; i++) {
            node *n = dequeue(queue, &front, rear);

            printf("%d %c", n->key, (n->color == RED ? 'R' : 'B'));
            if (n->parent != NIL) {
                printf(" (%d ", n->parent->key);
                if (n == n->parent->left)
                    printf("L)");
                else
                    printf("R)");
            }

            if (n->left != NIL) enqueue(queue, &rear, n->left);
            if (n->right != NIL) enqueue(queue, &rear, n->right);
            if (i < levelCount - 1) printf(" ");

            printedSomething = 1;
        }

        if (printedSomething)
            printf("\n");
    }

    free(queue);
}

void enqueue(node **queue, int *rear, node *n) {
    queue[(*rear)++] = n;
}

node *dequeue(node **queue, int *front, int rear) {
    if (*front == rear) return NULL;
    node *n = queue[(*front)++];
    return n;
}

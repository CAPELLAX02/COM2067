#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int data;
    int balance;
    struct Tree* left;
    struct Tree* right;
} tree;

// Function prototypes
tree* initTree(int newData);
tree *buildTreeFromArray(int arr[], int i, int n);
int calcHeight(tree* root);
void calcBalance(tree* root);
tree *findParent(tree* root, tree *target);
void printTree(tree* root);

int main(void) {
    int cap = 100;
    int* arr = (int*) malloc(sizeof(int) * cap);
    
    arr[0] = -1;

    int data;
    int i = 1;

    for (;;) {
        if (scanf("%d", &data) != 1) break;
        if (data == -2) break;
        if (i >= cap) {
            cap *= 2;
            arr = (int*) realloc(arr, sizeof(int) * cap);
        }
        arr[i++] = data;
    }

    tree* root = buildTreeFromArray(arr, 1, i - 1);

    calcBalance(root);
    printTree(root);

    free(arr);

    return 0;
}

tree* initTree(int newData) {
    tree* new = (tree*) malloc(sizeof(tree));

    new->data = newData;
    new->left = NULL;
    new->right = NULL;
    new->balance = 0;
    
    return new;
}

tree* buildTreeFromArray(int arr[], int i, int n) {
    if (i > n || arr[i] == -1) return NULL;

    tree* root = initTree(arr[i]);

    root->left = buildTreeFromArray(arr, 2*i, n);
    root->right = buildTreeFromArray(arr, 2*i+1, n);

    return root;
}

int calcHeight(tree* root) {
    if (root == NULL) return 0;

    int lH = calcHeight(root->left);
    int rH = calcHeight(root->right);

    return 1 + (lH > rH ? lH : rH);
}

void calcBalance(tree* root) {
    if (root == NULL) return;

    int lH = calcHeight(root->left);
    int rH = calcHeight(root->right);

    root->balance = lH - rH;

    calcBalance(root->left);
    calcBalance(root->right);
}

tree* findParent(tree* root, tree* target) {
    if (root == NULL || target == root) return NULL;

    tree** queue = (tree**) malloc(sizeof(tree*) * 1000);
    
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    tree* parent = NULL;
    
    while (front < rear) {
        tree* curr = queue[front++];
        if (curr->left == target || curr->right == target) {
            parent = curr;
            break;
        }
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }

    free(queue);
    return parent;
}

void printTree(tree* root) {
    if (root == NULL) return;

    tree** queue = (tree**) malloc(sizeof(tree*) * 1000);

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int currCount = 1;
    int nextCount = 0;

    while (front < rear) {
        tree* curr = queue[front++];
        currCount--;

        printf("%d", curr->data);
        if (curr != root) {
            tree* parent = findParent(root, curr);
            if (parent) {
                char dir = (parent->left == curr) ? 'L' : 'R';
                printf(" (%d %c)", parent->data, dir);
            }
        }
        printf(" (%d B)", curr->balance);

        if (currCount > 0) {
            printf(" ");
        }

        if (curr->left) {
            queue[rear++] = curr->left;
            nextCount++;
        }

        if (curr->right) {
            queue[rear++] = curr->right;
            nextCount++;
        }

        if (currCount == 0) {
            printf("\n");
            currCount = nextCount;
            nextCount = 0;
        }
    }

    free(queue);
}

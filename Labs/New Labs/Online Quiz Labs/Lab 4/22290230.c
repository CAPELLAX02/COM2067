#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @typedef tree
 * @property {char[50]} name - Name of the person.
 * @property {char[15]} phone - Phone number of the person.
 * @property {struct Tree*} left - Pointer to the left subtree.
 * @property {struct Tree*} right - Pointer to the right subtree.
 */
typedef struct Tree {
    char name[50];
    char phone[15];
    struct Tree *left;
    struct Tree *right;
} tree;

/**
 * Creates a new tree node with the given name and phone number.
 * @param char* name - The name to store in the new node.
 * @param char* phone - The phone number to store in the new node.
 * @returns tree* - A pointer to the newly created tree node.
 */
tree* createNode(char *name, char *phone) {
    tree* newR = (tree*)malloc(sizeof(tree));
    strcpy(newR->name, name);
    strcpy(newR->phone, phone);
    newR->left = newR->right = NULL;
    return newR;
}

/**
 * Inserts a new node with the specified name and phone into the binary search tree.
 * @param tree* r - The root of the binary search tree.
 * @param char* name - The name to insert into the tree.
 * @param char* phone - The phone number to associate with the name.
 * @returns tree* - The root of the tree after the insertion.
 */
tree* insert(tree* r, char *name, char *phone) {
    if (r == NULL) return createNode(name, phone);
    if (strcmp(name, r->name) < 0) r->left = insert(r->left, name, phone);
    else if (strcmp(name, r->name) > 0) r->right = insert(r->right, name, phone);
    return r;
}

/**
 * Searches the tree for all names that start with the specified prefix and prints them.
 * @param tree* r - The root of the binary search tree.
 * @param char* prefix - The prefix to search for in the tree.
 * @returns int - The count of names that match the prefix.
 */
int searchAndPrint(tree* r, char *prefix) {
    if (r == NULL) return 0;
    int count = 0;
    count += searchAndPrint(r->left, prefix);
    if (strncmp(r->name, prefix, strlen(prefix)) == 0) {
        printf("%s\n", r->name);
        count++;
    }
    count += searchAndPrint(r->right, prefix);
    return count;
}

int main(void) {
    tree* root = NULL;
    char name[50], phone[15];
    while (1) {
        scanf("%s", name);
        if (strcmp(name, "-1") == 0) break;
        scanf("%s", phone);
        root = insert(root, name, phone);
    }
    char prefix[50];
    while (1) {
        scanf("%s", prefix);
        if (strcmp(prefix, "-1") == 0) break;
        int count = searchAndPrint(root, prefix);
        if (count == 0) {
            printf("nobody\n");
            break;
        } 
        else if (count == 1) break;
    }
}

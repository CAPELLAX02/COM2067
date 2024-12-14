#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 2  // Her dügümdeki maksimum anahtar sayisi (2*t - 1, burada t = 2)
#define MIN_KEYS 1  // Minimum anahtar sayisi
#define MAX_CHILDREN (MAX_KEYS + 1)  // Çocuk sayisi

typedef struct BTreeNode {
    int keys[MAX_KEYS];       // Dügümdeki anahtarlar
    struct BTreeNode* children[MAX_CHILDREN]; // Çocuk dügümler
    int numKeys;              // Anahtar sayisi
    int isLeaf;               // Yaprak dügüm olup olmadigi (1: yaprak, 0: yaprak degil)
} BTreeNode;

// Yeni dügüm olustur
BTreeNode* createNode(int isLeaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->isLeaf = isLeaf;
    node->numKeys = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Dügümü bölme
void splitChild(BTreeNode* parent, int i, BTreeNode* child) {
    int mid = MAX_KEYS / 2;

    BTreeNode* newChild = createNode(child->isLeaf);
    newChild->numKeys = MAX_KEYS - mid - 1;

    // Yeni dügüme anahtarlarin ikinci yarisini aktar
    for (int j = 0; j < newChild->numKeys; j++) {
        newChild->keys[j] = child->keys[mid + 1 + j];
    }

    // Eger çocuk dügüm yaprak degilse, çocuklarini da aktar
    if (!child->isLeaf) {
        for (int j = 0; j <= newChild->numKeys; j++) {
            newChild->children[j] = child->children[mid + 1 + j];
        }
    }

    child->numKeys = mid;

    // Yeni dügümü ebeveynin çocuk listesine ekle
    for (int j = parent->numKeys; j >= i + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    parent->children[i + 1] = newChild;

    // Orta anahtari ebeveyn dügüme ekle
    for (int j = parent->numKeys - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = child->keys[mid];
    parent->numKeys++;
}

// Anahtar ekleme (yer açilmasi gerekirse)
void insertNonFull(BTreeNode* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        // Anahtari yaprak dügüme ekle
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // Uygun çocuga git
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        // Çocuk doluysa, böl
        if (node->children[i]->numKeys == MAX_KEYS) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// Anahtar ekleme (genel islem)
BTreeNode* insert(BTreeNode* root, int key) {
    if (root == NULL) {
        // Yeni agaç olustur
        root = createNode(1);
        root->keys[0] = key;
        root->numKeys = 1;
        return root;
    }

    if (root->numKeys == MAX_KEYS) {
        // Yeni kök olustur ve eski kökü böl
        BTreeNode* newRoot = createNode(0);
        newRoot->children[0] = root;
        splitChild(newRoot, 0, root);

        // Anahtari uygun yere ekle
        int i = (key > newRoot->keys[0]) ? 1 : 0;
        insertNonFull(newRoot->children[i], key);
        return newRoot;
    }

    insertNonFull(root, key);
    return root;
}

// Agaci yazdir (Inorder Traversal)
void traverse(BTreeNode* root) {
    if (root != NULL) {
        for (int i = 0; i < root->numKeys; i++) {
            traverse(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        traverse(root->children[root->numKeys]);
    }
}

int main() {
    BTreeNode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 30);
    root = insert(root, 7);
    root = insert(root, 17);

    printf("B-Tree Traversal: ");
    traverse(root);
    printf("\n");

    return 0;
}

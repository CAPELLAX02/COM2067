#include <stdio.h>
#include <stdlib.h>

// AVL Agaci için dügüm yapisi
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height; // Dügümün yüksekligi
} Node;

// Yeni dügüm olusturma
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; // Yeni dügümün baslangiç yüksekligi 1
    return node;
}

// Dügümün yüksekligini döndürme
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Maksimum degeri döndüren yardimci fonksiyon
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Dügümün denge faktörünü hesaplama
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->right) - getHeight(node->left);
}

// Saga döndürme islemi
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* B = x->right;

    // Döndürme islemi
    x->right = y;
    y->left = B;

    // Yükseklikleri güncelle
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // Yeni kök
}

// Sola döndürme islemi
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* B = y->left;

    // Döndürme islemi
    y->left = x;
    x->right = B;

    // Yükseklikleri güncelle
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // Yeni kök
}

// AVL agacina anahtar ekleme
Node* insert(Node* node, int key) {
    // 1. Standart BST ekleme
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Ayni anahtar eklenmez

    // 2. Dügüm yüksekligini güncelle
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Denge faktörünü kontrol et ve dengeyi sagla
    int balance = getBalance(node);

    // Sol-Sol Durumu
    if (balance < -1 && key < node->left->key)
        return rotateRight(node);

    // Sag-Sag Durumu
    if (balance > 1 && key > node->right->key)
        return rotateLeft(node);

    // Sol-Sag Durumu
    if (balance < -1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Sag-Sol Durumu
    if (balance > 1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; // Dügüme geri dön
}

// Inorder traversal ile AVL agacini yazdir
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    // AVL agacina anahtar ekleme
    root = insert(root, 14);
    root = insert(root, 12);
    root = insert(root, 20);
    root = insert(root, 18);
    root = insert(root, 23);
    root = insert(root, 44);

    // Inorder traversal ile agaci yazdir
    printf("Inorder traversal of the AVL tree is: ");
    inorder(root);
    printf("\n");

    return 0;
}

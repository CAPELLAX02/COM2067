#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;

void insert(int data) {
    Node* current = root;
    Node* parent = NULL;

    
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    
    if (root == NULL) {
        root = newNode;
        return;
    }

    // Dügümün yerini bulmak için gezin
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            // Deger zaten agaçta, eklenmez
            free(newNode);
            return;
        }
    }

    // Yeni dügümü dogru pozisyona yerlestir
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

//***************Inorder Traversal**************//
void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

//***************Preorder Traversal**************//
void preorderTraversal(Node* node) {
    if (node != NULL) {
        printf("%d ", node->data); // Dügümü ziyaret et
        preorderTraversal(node->left);  // Sol alt agaç
        preorderTraversal(node->right); // Sag alt agaç
    }
}

//***************Postorder Traversal**************//
void postorderTraversal(Node* node) {
    if (node != NULL) {
        postorderTraversal(node->left);  // Sol alt agaç
        postorderTraversal(node->right); // Sag alt agaç
        printf("%d ", node->data); // Dügümü ziyaret et
    }
}

//***************Search Function**************//
void search(int key) {
    Node* current = root;
    while (current != NULL) {
        if (key == current->data) {
            printf("%d found.\n", key);
            return;
        }
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    printf("%d not found.\n", key);
}

int sumOfNodes(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int myData = node->data;
    int leftSum = sumOfNodes(node->left);
    int rightSum = sumOfNodes(node->right);
    
    return myData + leftSum + rightSum;
    //return node->data + sumOfNodes(node->left) + sumOfNodes(node->right);
}


int lengthOfTree(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int myData = 1;
    int leftLength = lengthOfTree(node->left);
    int rightLength = lengthOfTree(node->right);
    
    return myData + leftLength + rightLength;
    //return 1 + lengthOfTree(node->left) + lengthOfTree(node->right);
}


int heightOfTree(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = heightOfTree(node->left);
    int rightHeight = heightOfTree(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


int main() {
    
    insert(50);
    insert(30);
    insert(20);
    insert(40);
    insert(70);
    insert(60);
    insert(80);

    
    printf("Inorder Traversal: \n");
    inorderTraversal(root);
    printf("\n");
    
    printf("Preorder Traversal: \n");
	preorderTraversal(root);
	printf("\n");
	
	printf("Postorder Traversal: \n");
	postorderTraversal(root);
	printf("\n");

   
    search(40);
    search(90);
    
    printf("Sum of all nodes: %d\n", sumOfNodes(root));
	printf("Length of the tree (total nodes): %d\n", lengthOfTree(root));
	printf("Height of the tree: %d\n", heightOfTree(root));


    return 0;
}



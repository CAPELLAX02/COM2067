// finitooo
// ubuntuda test et yolla

#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    int grade;
    int parentData;
    int level;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* createNode(int id,int grade){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->id = id;
    temp->grade = grade;
    temp->parentData = 0;
    temp->level = 0;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
void insert(struct node **root, int id, int grade){
    struct node* newNode = createNode(id,grade);

    if(*root == NULL){
        newNode->level = 0;
        *root = newNode;
    }else{
        int level = 0;
        struct node* current = *root;
        struct node* parent;

        while (current != NULL)
        {
            parent = current;

            if(grade < current->grade){
                current = current->left;
                level++;
            }else if(grade > current->grade){
                current = current->right;
                level++;
            }
        }

        newNode->level = level;
        newNode->parentData = parent->grade;

        if(grade < parent->grade){
            parent->left = newNode;
        }else if(grade > parent->grade){
            parent->right = newNode;
        }
        
    }
}

void printInOrder(struct node* root){
    if(root != NULL){
        printInOrder(root->left);
        printf("%d %d\n", root->id, root->grade);
        printInOrder(root->right);
    }
}

int findHeight(struct node* root) {
    if (root == NULL) {
        return -1; 
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printCertainLevel(struct node* root, int level) {
    if (root == NULL)
        return;

    struct node** queue = (struct node**)malloc(sizeof(struct Node*) * 20);
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
       
        struct node* current = queue[front++];
        if(current->level == level && current->level == 0){
            printf("%d %d", current->id,current->grade);
        }else if(current->level == level && current->grade < current->parentData){
            printf("%d %d (%d L) ", current->id,current->grade, current->parentData);
        }else if(current->level == level && current->grade > current->parentData){
            printf("%d %d (%d R) ", current->id,current->grade, current->parentData);
        }

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    free(queue);
}

void printLevelOrder(struct node* root){
    int height = findHeight(root);
    for(int i = 0; i<=height; i++){
        printCertainLevel(root,i);
        printf("\n");
    }
}

int main(){
    int id;
    int grade;
    scanf("%d",&id);
   
    while(id != -1){
        scanf("%d", &grade);
        insert(&root,id,grade);
        scanf("%d", &id);
    }

    printInOrder(root);
    printf("\n");
    printLevelOrder(root);
    
    
    return 0;
}
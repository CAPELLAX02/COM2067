#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char data[15];
    struct node* next;
};

struct node* top = NULL;

void push(struct node **head, char *str){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        return;
    }
    strcpy(newNode->data, str);
    newNode->next = *head;
    *head = newNode;
}

char* getTopTag(struct node* head){
    if(head == NULL){
        return NULL;
    }else{
        return head->data;
    }
}

void pop(struct node** head) {
    if (*head == NULL) {
        return;
    } else {
        struct node* temp = *head;
        *head = (*head)->next;
        char* poppedData = temp->data;
        free(temp); 
    }
}

int isEmpty(struct node *head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}


int main(){
    char input[400];

    fgets(input,400,stdin);
    size_t len = strlen(input);
    
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    for(int i=0; i<len; i++){
        char tagName[15];
        memset(tagName, 0, sizeof(tagName));

        if(input[i] == '<' && input[i+1] == '/'){
            //Check the top of the stack, (top function)
            int tempIndex = i+2;
            
            int j = 0;
            while(input[tempIndex] != '>'){
                 tagName[j] = input[tempIndex];
                 tempIndex++;
                 j++;
            }
            tagName[sizeof(tagName)-1] = '\0'; 
            
            char* poppedTagName = getTopTag(top);
            if(poppedTagName == NULL){
                push(&top,tagName);
                break;
            }else if(strcmp(poppedTagName, tagName) == 0){
                pop(&top);
            }else{
                push(&top, poppedTagName);
                break;
            }
        

        }else if(input[i] == '<' && input[i+1] != '/'){
            int tempIndex = i+1;

            int j = 0;
            while(input[tempIndex] != '>'){
                 tagName[j] = input[tempIndex];
                 tempIndex++;
                 j++;
            }
            push(&top,tagName);
        }
    }

    int flag = isEmpty(top);
    if(flag == 1){
        printf("correct\n");
    }else{
        printf("error <%s>\n",getTopTag(top));
    }
    return 0;
}

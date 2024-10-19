#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct CallerInfo{
    char* callerName;
    int priority;
};

struct node{
    struct CallerInfo* data;
    struct node* next;
};

struct node* head = NULL;

void insert(struct node **head, struct CallerInfo* caller){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = caller;
    temp->next = NULL;

    if(*head == NULL || caller->priority < (*head)->data->priority || 
    (caller->priority == (*head)->data->priority && strcmp(caller->callerName, (*head)->data->callerName) < 0)){
        temp->next = *head;
        *head = temp;
    }else{
        struct node* current = *head;
       while (current->next != NULL && (current->next->data->priority < caller->priority ||
   (caller->priority == current->next->data->priority && strcmp(caller->callerName, current->next->data->callerName) > 0)))

        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    
    }
}

//tested
struct CallerInfo* definePriority(char* callerName){
    struct CallerInfo* caller = (struct CallerInfo*)malloc(sizeof(struct CallerInfo));
    
    caller->callerName = (char*)malloc(strlen(callerName) + 1);

    strcpy(caller->callerName, callerName);
    
    caller->priority = 0;
    
    if(strcmp(callerName, "Annem") == 0 || strcmp(callerName, "Babam") == 0 || strcmp(callerName, "Kardesim") == 0){
        caller->priority = 1;
    }else if(strcmp(callerName, "Amcam") == 0 || strcmp(callerName, "Teyzem") == 0 || strcmp(callerName, "Halam") == 0 || strcmp(callerName, "Dayim") == 0 ){
        caller->priority = 2;
    }else if(strcmp(callerName, "Isyeri") == 0 || strcmp(callerName, "Okul") == 0){
        caller->priority = 3;
    }else if(strcmp(callerName, "Arkadasim1") == 0 || strcmp(callerName, "Arkadasim2") == 0 || strcmp(callerName, "Arkadasim3") == 0 || strcmp(callerName, "Arkadasim4") == 0 || strcmp(callerName, "Arkadasim5") == 0){
        caller->priority = 4;
    }else if(strcmp(callerName, "Banka") == 0 || strcmp(callerName, "Kargo") == 0){
        caller->priority = 5;
    }else if(strcmp(callerName, "Reklam") == 0){
        caller->priority = 6;
    }

    return caller;
}

void testDefinePriority(struct CallerInfo* caller){
    printf("%s %d\n", caller->callerName, caller->priority);
}

void printVal(struct node* head){
    struct node* current = head;

    while (current != NULL)
    {
        printf("%s\n",current->data->callerName);
        current = current->next;
    }
}

int main(){
    char input[50];
    int count = 0;
    while (1) {
        fgets(input, 50, stdin);
        
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        if (strcmp(input, "-1") == 0) {
            break; 
        }

        struct CallerInfo* caller = definePriority(input);
        insert(&head,caller);
        
        count++;
    }

    printVal(head);
    
    return 0;
}
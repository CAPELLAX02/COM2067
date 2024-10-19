#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char songName[50];
    int songNumber;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

void insert(struct node **head, char *song, int songNumber){
    char* newSongName = song;
    struct node* current = (*head); 
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->songName,newSongName);
    temp->songNumber = songNumber;
    temp->next = NULL;
    temp->prev = NULL;

    if((*head) == NULL){
        *head = temp;
    }else{
        struct node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        temp->prev = current;
        current->next = temp;
    }
}

void printVal(struct node *head, char dir, int skip){
    struct node* current = head;

    if(dir == 'B'){
        while(current != NULL){
            printf("%s\n", current->songName);
            for(int i = 0; i<skip+1; i++){
                if(current == NULL){
                    break;
                }
                current = current->next;
            }
        }
    }else if(dir == 'S'){
        while(current->next != NULL){
            current = current->next;
        }
        while(current != NULL){
            printf("%s\n", current->songName);

            for(int i = 0; i<skip+1; i++){
                if(current == NULL){
                    break;
                }
                current = current->prev;
            }  
        }
    }
}

int main() {
    char input[50];
    int count = 1;
    while (1) {
        fgets(input, 50, stdin);
        
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        if (strcmp(input, "-1") == 0) {
            break; 
        }
        insert(&head,input,count);
        count++;
    }

    char dir;
    int skip;
    scanf("%c %d",&dir,&skip);
    printVal(head,dir,skip);


    return 0;
}

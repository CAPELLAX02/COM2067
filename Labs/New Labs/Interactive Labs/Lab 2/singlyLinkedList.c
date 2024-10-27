#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int num;
    Node *next;
} Node;

        
Node *head=NULL , *temp=NULL , *last=NULL , *info=NULL;

void addList(int addNum){ 
    if(head==NULL){                                 
	    head=(Node*) malloc(sizeof(Node));  //malloc           
	    head->num=addNum;
	    head->next=NULL;
	    last=head;  
    }
    else{ 
     	info=(Node*) malloc(sizeof(Node)); 
        info->num=addNum;                      
        info->next=NULL;
		if( head->num >= info->num ){                                  
              info->next=head;
              head=info;
        }
        else{
            for(temp=head ; temp->next!=NULL && (temp->next->num) < (info->num) ; temp=temp->next);
            if(temp->next!=NULL){
                info->next=temp->next;
                temp->next=info;  
            }
        	else{
                temp->next=info;
                last=info;
            }
         }
     }
    
}

bool searchElement(int key)
{
   	int count=0;
   	temp=head;
   	while(temp!=NULL){
   	    if(temp->num == key){
	   	 	printf("The number was found at %d.\n",count+1);
	   	 	return true;
	    }
   	    else{
	   	 	temp=temp->next;
	   	 	count++;
		}
    }
    return false;
}

void printList() {
 
    temp = head;
    if (temp == NULL) {
        printf("There are no items in your list!\n");
    }else{
        while (temp != NULL) {
            printf("%d  ", temp->num);
            temp = temp->next;
        }
    }
    printf("\n");
}

void deleteNode(int key)
{
    Node *temp,*before;
    temp=head;
    while(temp)
    {
        if(temp->num == key)
            break;
        before=temp;
        temp=temp->next;
    }
    if(temp!=NULL){
        if(temp==head){
            if(temp==last){
                head=NULL;
                last=NULL;
            }else{
                head=head->next;
            }
        }else{
            before->next=temp->next;
            if(temp==last)
               last=before;
        }
        printf("%d deleted.\n",temp->num);
        free(temp);
    }
} 
 

int main()
{
    addList(10);
    addList(30);
    addList(20);
    addList(40);

    printf("Link list: ");
    printList();

    int key = 20;
    if(searchElement(key)) {
        printf("%d found.\n", key);
    }else{
        printf("%d not found.\n", key);
    }

    printf("%d node deleting.\n", key);
    deleteNode(key);

    printf("Updated list: ");
    printList();


    return 0;
}
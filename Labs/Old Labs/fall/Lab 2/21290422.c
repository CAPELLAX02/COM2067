#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

struct intersectedNode {
    int data;
    int index1;
    int index2;
    struct intersectedNode* next;
};

struct node* list1 = NULL;
struct node* list2 = NULL;
struct intersectedNode* final = NULL;

void insert(struct node** head, int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void addFinalList(struct intersectedNode** head, int data, int index1, int index2) {
    struct intersectedNode* temp = (struct intersectedNode*)malloc(sizeof(struct intersectedNode));
    temp->data = data;
    temp->index1 = index1;
    temp->index2 = index2;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        struct intersectedNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

struct intersectedNode* intersected_nodes(struct node* list1, struct node* list2) {
    struct node* temp1 = list1;
    struct intersectedNode* willBeReturned = NULL;
    int count1 = 0;

    while (temp1 != NULL) {
        struct node* temp2 = list2;
        int count2 = 0;

        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                addFinalList(&willBeReturned, temp1->data, count1, count2);
            }
            temp2 = temp2->next;
            count2++;
        }
        temp1 = temp1->next;
        count1++;
    }
    return willBeReturned;
}

void printFinal(struct intersectedNode* head) {
    struct intersectedNode* temp = head;

    while (temp != NULL) {
        printf("%d %d %d\n", temp->data, temp->index1, temp->index2);
        temp = temp->next;
    }
}

int main() {
    int data;

    scanf("%d", &data);
    while (data != -1) {
        insert(&list1, data);
        scanf("%d", &data);
    }

    scanf("%d", &data);
    while (data != -1) {
        insert(&list2, data);
        scanf("%d", &data);
    }

    final = intersected_nodes(list1, list2);
    printFinal(final);
    return 0;
}

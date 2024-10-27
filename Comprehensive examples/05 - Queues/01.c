#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue *createQueue();
int size(Queue *queue);
bool isEmpty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroyQueue(Queue *queue);

int main(void) {
    Queue *queue = createQueue();

    if (isEmpty(queue)) puts("Queue is empty.");

    enqueue(queue, 4);

    if (!isEmpty(queue)) puts("Queue is not empty.");

    enqueue(queue, 5);
    enqueue(queue, 6);

    printf("Queue size: %d\n", size(queue));

    bool status = false;
    int value = 0;

    value = peek(queue, &status);
    if (status) printf("Peek successfull. Peek value: %d\n", value);

    value = dequeue(queue, &status);
    if (status) printf("Dequeue successfull. Dequeued value: %d\n", value);

    value = peek(queue, &status);
    if (status) printf("Peek successfull. Peek value: %d\n", value);

    value = dequeue(queue, &status);
    if (status) printf("Dequeue successfull. Dequeued value: %d\n", value);

    value = peek(queue, &status);
    if (status) printf("Peek successfull. Peek value: %d\n", value);

    value = dequeue(queue, &status);
    if (status) printf("Dequeue successfull. Dequeued value: %d\n", value);

    value = peek(queue, &status);
    if (status) printf("Peek successfull. Peek value: %d\n", value);

    value = dequeue(queue, &status);
    if (status) printf("Dequeue successfull. Dequeued value: %d\n", value);

    value = peek(queue, &status);
    if (!status) puts("Peek failed. The queue is empty.");

    value = dequeue(queue, &status);
    if (!status) puts("Dequeue failed. The queue is empty."); 
    
    destroyQueue(queue);

    return 0;
}

Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

int size(Queue *queue) {
    return queue->size;
}

bool isEmpty(Queue *queue) {
    return queue->size == 0;
}

int peek(Queue *queue, bool *status) {
    if (isEmpty(queue)) {
        *status = false;
        return -1;
    }
    *status = true;
    return queue->head->value;
}

void enqueue(Queue *queue, int value) {
    Node *newNode = malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL; // indicates this is the tail node

    if (isEmpty(queue)) {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;
}

int dequeue(Queue *queue, bool *status) {
    if (isEmpty(queue)) {
        *status = false;
        return -1;
    }
    *status = true;

    int value = queue->head->value;

    Node *oldHead = queue->head;

    if (queue->size == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = queue->head->next;
    }

    free(oldHead);
    queue->size--;

    return value;
}

void destroyQueue(Queue *queue) {
    Node *currentNode = queue->head;

    while (currentNode != NULL) {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }

    free(queue);
}
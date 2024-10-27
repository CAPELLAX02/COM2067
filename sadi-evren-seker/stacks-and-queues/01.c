#include <stdio.h>
#include <stdlib.h>

int *arr;
int size = 3;

int head = 0;

int pop() {
    if (head <= size / 4) {
        int* arr2 = (int*) malloc(sizeof(int) * size/2);
        for (int i = 0; i < size; i++) {
            arr2[i] = arr[i];
        }
        free(arr);
        arr = arr2;
        size /= 2;
    }
    return arr[--head];
}

int push(int a) {
    if (arr == NULL) {
        arr = (int*) malloc(sizeof(int) * size * 2);
    }
    if (head >= size) {
        int *arr2 = (int*) malloc(sizeof(int) * size * 2);
        for (int i = 0; i < size; i++) {
            arr2[i] = arr[i];
        }
        free(arr);
        arr = arr2;
        size *= 2;
    }
    arr[head++] = a;
}

int printArr() {
    printf("Current array: ");
    printf("[ ");
    for (int i = 0; i < head; i++) {
        printf("%d ", arr[i]);
    }
    printf("] (size: %d)\n", size);
}

int main(void) {
    arr =  (int*) malloc(2 * sizeof(int));

    push(10);
    push(20);
    push(20);
    push(20);
    push(20);
    push(20);

    printArr();

    printf("Popped value: %d\n", pop());
    printf("Popped value: %d\n", pop());

    printArr();

    printf("Popped value: %d\n", pop());
    printf("Popped value: %d\n", pop());

    printArr();

    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(70);
    push(70);

    printArr();

    push(70);
    push(70);
    push(70);
    push(70);

    printArr();

    printf("Popped value: %d\n", pop());
    printf("Popped value: %d\n", pop());
    printf("Popped value: %d\n", pop());

    printArr();
}
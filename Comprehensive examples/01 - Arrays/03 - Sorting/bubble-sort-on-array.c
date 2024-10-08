#include <stdio.h>

#define MAX 100

// Function prototypes
void showMenu(void);
void displayArray(int arr[], int size);
void bubbleSort(int arr[], int size);

int main(void) {
    int arr[MAX] = {64, 34, 25, 12, 22, 11, 90}; // Sample unsorted array
    int size = 7; // Size of the array
    int choice; // User's menu choice

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                bubbleSort(arr, size);
                displayArray(arr, size);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

}

// Menu for binary search
void showMenu() {
    printf("\n---- Bubble Sort ----\n");
    printf("1. Display Array\n");
    printf("2. Sort Array (Bubble Sort)\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Function to display elements of the array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the unsorted pairs
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    puts("Array has been sorted using bubble sort.");
}
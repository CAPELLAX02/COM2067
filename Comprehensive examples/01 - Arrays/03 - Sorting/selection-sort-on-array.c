#include <stdio.h>

#define MAX 100

// Function prototypes
void showMenu(void);
void displayArray(int arr[], int size);
void selectionSort(int arr[], int size);

int main(void) {
    int arr[MAX] = {64, 25, 12, 22, 11}; // Sample unsorted array
    int size = 5; // Size of the array
    int choice; // User's menu choice

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                selectionSort(arr, size);
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

// Menu for sorting
void showMenu() {
    printf("\n---- Selection Sort ----\n");
    printf("1. Display Array\n");
    printf("2. Sort Array (Selection Sort)\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Function to display elements of the array
void displayArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the current element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    puts("Array has been sorted using selection sort.");
} 
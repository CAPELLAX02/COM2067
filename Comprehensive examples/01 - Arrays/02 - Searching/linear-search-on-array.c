#include <stdio.h>

#define MAX 100

// Function prototypes
void displayArray(int arr[], int size);
void linearSearch(int arr[], int size);
void showMenu(void);

int main(void) {
    int arr[MAX] = { 5, 12, 23, 34, 45, 56, 67, 78 };
    // NOTE: To perform linear search on an array, array must be sorted.

    int size = 8; // Size of the array
    int choice; // User's menu choice

    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                linearSearch(arr, size);
                break;
            case 3:
                puts("Enf of run.");
                break;
            default:
                puts("Invalid choice. Try again.");
        }
    } while (choice != 3);
}

// Function to display elements of the array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
}

// Function to perform linear search on an array
void linearSearch(int arr[], int size) {    
    int key; // Element to be found
    int found = 0; // Flag usage

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (int index = 0; index < size; index++) {    
        if (arr[index] == key) {
            printf("Element %d found at index %d\n", key, index);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }
}

// Menu for the searching program
void showMenu() {
    printf("\n---- Searching ----\n");
    printf("1. Display Array\n");
    printf("2. Linear Search\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}
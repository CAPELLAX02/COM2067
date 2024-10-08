#include <stdio.h>

#define MAX 100

// Function prototypes
void displayArray(int arr[], int size);
int binarySearchRecursive(int arr[], int key, int low, int high);
void binarySearch(int arr[], int size);
void showMenu(void);

int main(void) {
    int arr[MAX] = { 5, 12, 23, 34, 45, 56, 67, 78 };
    // NOTE: To perform binary search on an array, array must be sorted.
    int size = 8; // Size of the array
    int choice;   // User's menu choice

    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                binarySearch(arr, size);
                break;
            case 3:
                puts("End of run.");
                break;
            default:
                puts("Invalid choice. Try again.");
        }
    } while (choice != 3);
}

// Menu for binary search
void showMenu() {
    printf("\n---- Binary Search ----\n");
    printf("1. Display Array\n");
    printf("2. Binary Search\n");
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

// Recursive function for binary search
int binarySearchRecursive(int arr[], int key, int low, int high) {
    if (low > high) {
        return -1; // Base case: Element not found
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key) {
        // Element found
        return mid; 
    } else if (arr[mid] < key) {
        // Search recursively in right half
        return binarySearchRecursive(arr, key, mid + 1, high);
    } else {
        // Search recursively in left half
        return binarySearchRecursive(arr, key, low, mid - 1);
    }
}

// Wrapper function for binary search
void binarySearch(int arr[], int size) {    
    int key, result;

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearchRecursive(arr, key, 0, size - 1);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
}

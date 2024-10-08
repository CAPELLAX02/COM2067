#include <stdio.h>

#define MAX 100

// Function prototypes
void displayArray(int arr[], int size);
void insert(int arr[], int *size);
void delete(int arr[], int *size);
void showMenu(void);

int main(void) {
    int arr[MAX]; // Define array
    int size = 0; // Initial size of the array
    int choice; // User's choice 

    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                insert(arr, &size);
                break;
            case 3:
                delete(arr, &size);
                break;
            case 4:
                printf("End of run.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

// Function to display the array
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element into the array
void insert(int arr[], int *size) {
    if (*size == MAX) {
        printf("Array is full. Cannot insert elements.\n");
        return;
    }

    int position;
    printf("Enter the position (0 to %d) to insert: ", *size);
    scanf("%d", &position);

    int value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }

    // Shift array elements to left by one int unit
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;

    // Update the size of the array
    (*size)++;

    printf("Inserted %d at position %d\n", value, position);
}

// Function to delete an element from the array
void delete(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }

    int position;
    printf("Enter the position (0 to %d) of the element to delete: ", *size - 1);
    scanf("%d", &position);

    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }

    printf("Deleted %d from the position %d\n", arr[position], position);

    // Shift the array after deletion
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Update the size of the array
    (*size)--;
}

// Function to display the manu to the user
void showMenu() {
    printf("\n---- Array Operations ----\n");
    printf("1. Display Array\n");
    printf("2. Insert Element\n");
    printf("3. Delete Element\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}
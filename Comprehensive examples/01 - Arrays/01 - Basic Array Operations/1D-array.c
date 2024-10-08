#include <stdio.h>

#define SIZE 10  // Array size

// Function prototypes
void displayArray(int arr[], int n);
void insert(int arr[], int *n, int pos, int value);
void delete(int arr[], int *n, int pos);

int main(void) {
    // Initialize the array with 5 elements
    int arr[SIZE] = { 1, 2, 3, 4, 5 };
    int n = 5; // Current size of the array

    // Current size of the array
    displayArray(arr, n); 
    // OUTPUT: Array elements: 1 2 3 4 5

    // Insert element at position 2
    insert(arr, &n, 2, 99);
    displayArray(arr, n);
    // OUTPUT: Inserted 99 at position 2 
    //         Array elements: 1 2 99 3 4 5  

    // Delete element at position 4
    delete(arr, &n, 4);
    displayArray(arr, n); 
    // OUTPUT: Deleted element 4 from position 4 
    //         Array elements: 1 2 99 3 5 
}

// Function to display elements of an array
void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a given position
void insert(int arr[], int *n, int pos, int value) {
    if (*n >= SIZE) {
        printf("Array is full, cannot insert element.\n");
        return;
    }

    // Shift elements to the right to make space
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert new element
    arr[pos] = value;

    // Incremenet array size
    (*n)++;

    printf("Inserted %d at position %d\n", value, pos);
}

// Function to delete an element from a given position
void delete(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }

    printf("Deleted element %d from position %d\n", arr[pos], pos);

    // Shift element to the left to fill the gap
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decremenet array size
    (*n)--; 
}
// Basic linear searching implementation on an array
#include <stdio.h>

#define SIZE 5

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            // Return the index of the element if found
            return i;
        }
    }
    // Return -1 if element is not found
    return -1;
}

int main(void) {
    // Initialize the array
    int arr[SIZE] = { 10, 12, 8, 24, 17 };

    // Element to search for
    int key = 8;

    // Perform linear search
    int result  = linearSearch(arr, SIZE, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    // OUTPUT: Element 8 found at index 2
}
// Simple bubble sorting operation on an array
#include <stdio.h>

#define SIZE 5

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j ++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are in wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display elements of an array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // Initialize array
    int arr[SIZE] = {64, 34, 25, 12, 22};
    
    // Display original array
    printf("Original array: ");
    displayArray(arr, SIZE);
    // OUTPUT: Original array: 64 34 25 12 22 
    
    // Sort the array
    bubbleSort(arr, SIZE);
    
    // Display sorted array
    printf("Sorted array: ");
    displayArray(arr, SIZE);
    // OUTPUT: Sorted array: 12 22 25 34 64 
}
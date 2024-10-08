#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to display a 2D array
void display2D(int arr[ROWS][COLS], int rows, int cols) {
    printf("2D array elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    // Initialize a 2D array with some values
    int arr[ROWS][COLS] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    // Disply the array
    display2D(arr, ROWS, COLS);

    // OUTPUT:  2D array elements:
    //          1 2 3 
    //          4 5 6 
    //          7 8 9 
}

#include <stdio.h>

#define MAX 10 // Define the maximum size of matrices

// Function to input matrix elements
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("Error: Matrix multiplication not possible (columns of first matrix must equal rows of second matrix).\n");
        return;
    }

    // Initialize the result matrix to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    // Input for the first matrix
    printf("Enter the number of rows and columns for the first matrix (max %d): ", MAX);
    scanf("%d%d", &r1, &c1);
    printf("Enter the elements of the first matrix:\n");
    inputMatrix(mat1, r1, c1);

    // Input for the second matrix
    printf("Enter the number of rows and columns for the second matrix (max %d): ", MAX);
    scanf("%d%d", &r2, &c2);
    printf("Enter the elements of the second matrix:\n");
    inputMatrix(mat2, r2, c2);

    // Display matrices
    printf("\nFirst matrix:\n");
    displayMatrix(mat1, r1, c1);
    
    printf("\nSecond matrix:\n");
    displayMatrix(mat2, r2, c2);

    // Multiply the matrices
    multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2);

    // Display the result matrix
    if (c1 == r2) {
        printf("\nResultant matrix after multiplication:\n");
        displayMatrix(result, r1, c2);
    }

    return 0;
}

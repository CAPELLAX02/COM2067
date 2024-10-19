#include <stdio.h>

void printMatrix(int matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}

int main(void) {
    int rowSum[5] = { 0 };
    int colSum[5] = { 0 };

    int matrix[5][5];

    // Get matrix elements from user and fill the matrix
    for (int i = 0; i < 5; i++) {   
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    //
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            rowSum[i] += matrix[i][j];    
        }

        for (int j = 0; j < 5; j++) {
            matrix[j][i] += rowSum[i];
        }

        for (int j = 0; j < 5; j++) {
            colSum[i] += matrix[j][i];
        }

        for (int j = 0; j < 5; j++) {
            matrix[i][j] += colSum[i];
        }
    }

    printMatrix(matrix);
}
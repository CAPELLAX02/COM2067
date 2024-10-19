#include <stdio.h>
#include <stdlib.h>

void multiplyMatrix(int **A, int **B, int **C, int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(void) {
    // Not: A 2x3, B 3x2 ve C (çarpım matrisi) 2x2 matrislerdir
    int n = 2;
    int m = 3;
    int p = 2;

    int **A;
    int **B;
    int **C;

    // Matris A (nxm = 2x3) için bellek ayırma
    A = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int*) malloc(m * sizeof(int));
    }

    // Matris B (mxp = 3x2) için bellek ayırma
    B = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        B[i] = (int*) malloc(p * sizeof(int));
    }

    // C çarpım matrisi (nxp = 2x2) için bellek ayırma
    C = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        C[i] = (int*) malloc(p * sizeof(int));
    }

    // A matrisini doldur
    puts("Enter the elements of Matrix A (2x3):");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    puts("");

    // B matrisini doldur
    puts("Enter the elements of Matrix B (3x2):");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    puts("");

    // Matrisleri çarp ve sonucu yazdır
    multiplyMatrix(A, B, C, n, m, p);

    puts("C (2x2) multiplication matris is:")
    for (int i = 0; i < n; i++ ) {
        for (int j = 0; j < p; j++) {
            printf("%d ", C[i][j]);
        }
        puts("");
    }

    // Belleği temizle
    for (int i = 0; i < n; i++) free(A[i]);
    for (int i = 0; i < n; i++) free(B[i]);
    for (int i = 0; i < n; i++) free(C[i]);

    free(A);
    free(B);
    free(C);
}
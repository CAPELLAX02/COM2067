#include <stdio.h>

void merge(int arr1[], int m, int arr2[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            k--;
            i--;
        } 
        else {
            arr1[k] = arr2[j];
            k--;
            j--;
        }
    }

    while (j >= 0) {
        arr1[k] = arr2[j];
        k--;
        j--;
    }
}

int main(void) {
    int arr1[6] = { 1, 2, 3, 0, 0, 0 };
    int arr2[3] = { 2, 5, 6 };

    int m = 3;
    int n = 3;

    merge(arr1, m, arr2, n);

    for (int i = 0; i < m + n; i++) {
        printf("%d ", arr1[i]);
    }
    puts("");

    // OUTPUT: 1 2 2 3 5 6
}
/*
The Longest Common Subsequence (LCS) problem is a well-known problem in dynamic programming. Given two strings, it finds the longest subsequence common to both strings.
 */
#include <stdio.h>
#include <string.h>

#define MAX 100 // Maximum string size

// Prototypes
int LCS(char str1[], char str2[]);
void menu(void);

int main(void) {
    char str1[MAX];
    char str2[MAX];
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        getchar();  // Handle newline

        switch (choice) {
            case 1:
                printf("Enter the first string: ");
                fgets(str1, MAX, stdin);
                printf("Enter the second string: ");
                fgets(str2, MAX, stdin);

                // Remove newlines
                str1[strcspn(str1, "\n")] = 0;
                str2[strcspn(str2, "\n")] = 0;

                int lcsLength = LCS(str1, str2);
                printf("The length of the longest common subsequence is: %d\n", lcsLength);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 2);
}

// Menu for LCS
void menu() {
    printf("\n---- Longest Common Subsequence ----\n");
    printf("1. Find LCS of two strings\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Function to find the longest common subsequence
int LCS(char str1[], char str2[]) {
    int m = strlen(str1);
    int n = strlen(str2);
    int L[m + 1][n + 1];  // DP table

    // Build the DP table bottom-up
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // The length of the LCS is in L[m][n]
    return L[m][n];
}
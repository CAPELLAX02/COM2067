/*
The Knuth-Morris-Pratt (KMP) algorithm is an efficient pattern-matching algorithm that searches for a substring (pattern) in a string (text) by preprocessing the pattern to avoid unnecessary comparisons, leading to O(n) complexity.
*/
#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum string size

// Function declarations
void KMPSearch(char pattern[], char text[]);
void computeLPSArray(char pattern[], int M, int lps[]);

// Menu for KMP algorithm
void menu() {
    printf("\n---- KMP Pattern Matching Algorithm ----\n");
    printf("1. Search for a Pattern\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char text[MAX], pattern[MAX];
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        getchar();  // Handle newline

        switch (choice) {
            case 1:
                printf("Enter the main text: ");
                fgets(text, MAX, stdin);
                printf("Enter the pattern to search for: ");
                fgets(pattern, MAX, stdin);

                // Remove newlines
                text[strcspn(text, "\n")] = 0;
                pattern[strcspn(pattern, "\n")] = 0;

                KMPSearch(pattern, text);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 2);

    return 0;
}

// KMP search algorithm
void KMPSearch(char pattern[], char text[]) {
    int M = strlen(pattern);
    int N = strlen(text);

    int lps[M];  // Longest prefix suffix array

    // Preprocess the pattern to calculate lps array
    computeLPSArray(pattern, M, lps);

    int i = 0;  // Index for text[]
    int j = 0;  // Index for pattern[]
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            // Mismatch after j matches
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Preprocess pattern to create lps array
void computeLPSArray(char pattern[], int M, int lps[]) {
    int length = 0;
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

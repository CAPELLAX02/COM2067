#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum string size

// Function declarations
void ZAlgorithm(char text[], char pattern[]);

// Menu for Z Algorithm
void menu() {
    printf("\n---- Z Algorithm for Pattern Matching ----\n");
    printf("1. Search Pattern\n");
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
                printf("Enter the text: ");
                fgets(text, MAX, stdin);
                printf("Enter the pattern to search: ");
                fgets(pattern, MAX, stdin);

                // Remove newlines
                text[strcspn(text, "\n")] = 0;
                pattern[strcspn(pattern, "\n")] = 0;

                ZAlgorithm(text, pattern);
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

// Function to implement the Z Algorithm
void ZAlgorithm(char text[], char pattern[]) {
    char concat[MAX];
    sprintf(concat, "%s$%s", pattern, text);  // Combine pattern and text with a separator

    int n = strlen(concat);
    int Z[n];
    Z[0] = 0;

    // Compute the Z-array
    int left = 0, right = 0;
    for (int i = 1; i < n; i++) {
        if (i > right) {
            left = right = i;
            while (right < n && concat[right] == concat[right - left]) {
                right++;
            }
            Z[i] = right - left;
            right--;
        } else {
            int k = i - left;
            if (Z[k] < right - i + 1)
                Z[i] = Z[k];
            else {
                left = i;
                while (right < n && concat[right] == concat[right - left]) {
                    right++;
                }
                Z[i] = right - left;
                right--;
            }
        }
    }

    // Check where the pattern matches
    int patternLength = strlen(pattern);
    for (int i = 0; i < n; i++) {
        if (Z[i] == patternLength) {
            printf("Pattern found at index %d\n", i - patternLength - 1);
        }
    }
}

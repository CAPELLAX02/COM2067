#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Function declarations
int areAnagrams(char str1[], char str2[]);

// Menu for anagram detection
void menu() {
    printf("\n---- Anagram Detection ----\n");
    printf("1. Check if Strings are Anagrams\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char str1[MAX], str2[MAX];
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
                if (areAnagrams(str1, str2)) {
                    printf("The strings are anagrams.\n");
                } else {
                    printf("The strings are not anagrams.\n");
                }
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

// Function to check if two strings are anagrams
int areAnagrams(char str1[], char str2[]) {
    int count[256] = {0};  // Assuming ASCII characters

    // Count characters in the first string
    for (int i = 0; str1[i] != '\0'; i++) {
        if (isalpha(str1[i])) {
            count[tolower(str1[i])]++;
        }
    }

    // Subtract character counts using the second string
    for (int i = 0; str2[i] != '\0'; i++) {
        if (isalpha(str2[i])) {
            count[tolower(str2[i])]--;
        }
    }

    // Check if all counts are zero
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

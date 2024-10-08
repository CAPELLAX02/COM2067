#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum string size

// Function declarations
void searchSubstring(char str[], char substr[]);

// Menu for substring search
void menu() {
    printf("\n---- Substring Search ----\n");
    printf("1. Search for Substring\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char str[MAX], substr[MAX];
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        getchar();  // Handle newline

        switch (choice) {
            case 1:
                printf("Enter the main string: ");
                fgets(str, MAX, stdin);
                printf("Enter the substring to search for: ");
                fgets(substr, MAX, stdin);
                searchSubstring(str, substr);
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

// Function to search for a substring in a string
void searchSubstring(char str[], char substr[]) {
    // Remove newlines from both strings
    str[strcspn(str, "\n")] = 0;
    substr[strcspn(substr, "\n")] = 0;

    char *pos = strstr(str, substr);  // Search for substring using strstr()

    if (pos != NULL) {
        printf("Substring '%s' found at position %ld\n", substr, pos - str);
    } else {
        printf("Substring '%s' not found.\n", substr);
    }
}

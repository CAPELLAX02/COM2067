#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100  // Maximum string size

// Function to check if a string is a palindrome
int isPalindrome(char str[]);

// Menu for palindrome check
void menu() {
    printf("\n---- Palindrome Check ----\n");
    printf("1. Check if String is Palindrome\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char str[MAX];
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        getchar();  // Handle newline

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str, MAX, stdin);
                if (isPalindrome(str)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
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

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int left = 0, right = strlen(str) - 2;  // Ignore the newline character

    while (left < right) {
        // Ignore non-alphabetic characters and make it case-insensitive
        if (!isalpha(str[left])) {
            left++;
        } else if (!isalpha(str[right])) {
            right--;
        } else if (tolower(str[left]) != tolower(str[right])) {
            return 0;  // Not a palindrome
        } else {
            left++;
            right--;
        }
    }

    return 1;  // Is a palindrome
}

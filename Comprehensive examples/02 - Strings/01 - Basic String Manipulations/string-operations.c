// Following program performs the most common and simple manipulations on strings.
#include <stdio.h>
#include <string.h>

#define MAX 100

// Function prototypes
void getStringLength(char str[]);
void concatenateStrings(char str1[], char str2[]);
void copyString(char dest[], char src[]);
void menu(void);

int main(void) {
    char str1[MAX];
    char str2[MAX];
    char dest[MAX];

    int choice;

     do {
        menu();
        scanf("%d", &choice);
        getchar(); // To handle the newline character after choice

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, MAX, stdin);
                getStringLength(str1);
                break;
            case 2:
                printf("Enter the first string: ");
                fgets(str1, MAX, stdin);
                printf("Enter the second string: ");
                fgets(str2, MAX, stdin);
                concatenateStrings(str1, str2);
                break;
            case 3:
                printf("Enter the source string: ");
                fgets(str1, MAX, stdin);
                copyString(dest, str1);
                printf("Copied string: %s\n", dest);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
}

void menu() {
    printf("\n---- String Operations ----\n");
    printf("1. Get String Length\n");
    printf("2. Concatenate Strings\n");
    printf("3. Copy String\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Function to get the length of the string
void getStringLength(char str[]) {
    int length = strlen(str) - 1;  // Remove the newline character
    printf("The length of the string is: %d\n", length);
}

// Function to concatenate two strings
void concatenateStrings(char str1[], char str2[]) {
    str1[strcspn(str1, "\n")] = 0;  // Remove newline from fgets
    str2[strcspn(str2, "\n")] = 0;
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
}

// Function to copy one string to another
void copyString(char dest[], char src[]) {
    strcpy(dest, src);
}
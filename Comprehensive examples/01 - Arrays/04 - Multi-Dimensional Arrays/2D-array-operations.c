#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function prototypes
void showMenu(void);
void display2DArray(int arr[ROWS][COLS]);
void update2DArray(int arr[ROWS][COLS]);

int main(void) {
    int arr[ROWS][COLS] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display2DArray(arr);
                break;
            case 2:
                update2DArray(arr);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
}

void showMenu() {
    printf("\n---- 2D Array Operations ----\n");
    printf("1. Display 2D Array\n");
    printf("2. Update 2D Array Element\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void display2DArray(int arr[ROWS][COLS]) {
    puts("2D Array:");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}

void update2DArray(int arr[ROWS][COLS]) {
    int row;
    int col;
    int newValue;

    printf("Enter the row number to update: ");
    scanf("%d", &row);

    printf("Enter the column number to update: ");
    scanf("%d", &col);

    if (ROWS <= row < 0 || COLS <= col < 0) {
        printf("Invalid indices.\n");
        return;
    }

    printf("Enter the new value: ");
    scanf("%d", &newValue);

    arr[row][col] = newValue;

    printf("Updated value at (%d, %d).\n", row, col);
}
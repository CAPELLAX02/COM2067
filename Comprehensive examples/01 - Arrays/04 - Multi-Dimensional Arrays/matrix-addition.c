#include <stdio.h>

#define ROWS 2
#define COLS 2

// Function prototypes
void showMenu(void);
void display2DArray(int arr[ROWS][COLS]);
void addMatrices(int arr1[ROWS][COLS], int arr2[ROWS][COLS]);

int main(void) {
    int arr1[ROWS][COLS] = {
        {1, 2},
        {3, 4}
    };

    int arr2[ROWS][COLS] = {
        {5, 6},
        {7, 8}
    };

    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Matrix 1:\n");
                display2DArray(arr1);
                printf("Matrix 2:\n");
                display2DArray(arr2);
                break;
            case 2:
                addMatrices(arr1, arr2);
                break;
            case 3:
                printf("End of run.\n");
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
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}

void addMatrices(int arr1[ROWS][COLS], int arr2[ROWS][COLS]) {
    int resultArr[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultArr[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    puts("Resultant matrix after addition:");

    display2DArray(resultArr);
}
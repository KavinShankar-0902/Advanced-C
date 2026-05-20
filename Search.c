#include <stdio.h>

#define SIZE 4

void searchMatrix(int matrix[SIZE][SIZE], int key) {

    int row = 0;
    int col = SIZE - 1;

    while(row < SIZE && col >= 0) {

        if(matrix[row][col] == key) {

            printf("Element found at position:\n");
            printf("Row = %d, Column = %d\n", row, col);

            return;
        }

        else if(key < matrix[row][col]) {
            col--;
        }

        else {
            row++;
        }
    }

    printf("Element not found\n");
}

int main() {

    int matrix[SIZE][SIZE] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    searchMatrix(matrix, key);

    return 0;
}
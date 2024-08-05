#include <stdio.h>

#define MAX 100

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX], transpose[MAX][MAX];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    inputMatrix(matrix, rows, cols);

    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);

    transposeMatrix(matrix, transpose, rows, cols);

    printf("Transpose Matrix:\n");
    printMatrix(transpose, cols, rows);

    return 0;
}

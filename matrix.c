#include <stdio.h>

#define SIZE 3   // Fixed size for 3x3 matrices

// Function to input a 3x3 matrix
void inputMatrix(int mat[SIZE][SIZE]) {
    printf("Enter elements of a 3x3 matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to print a 3x3 matrix
void printMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Matrix addition
void addMatrix(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE]) {
    int result[SIZE][SIZE];
    printf("\nMatrix Addition Result:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Matrix multiplication
void multiplyMatrix(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE]) {
    int result[SIZE][SIZE];
    printf("\nMatrix Multiplication Result:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Matrix transpose
void transposeMatrix(int mat[SIZE][SIZE]) {
    printf("\nTranspose Result:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[SIZE][SIZE], mat2[SIZE][SIZE];

    // Input matrices
    printf("Matrix 1:\n");
    inputMatrix(mat1);
    printf("Matrix 2:\n");
    inputMatrix(mat2);

    // Display matrices
    printf("\nMatrix 1:\n");
    printMatrix(mat1);
    printf("\nMatrix 2:\n");
    printMatrix(mat2);

    // Operations
    addMatrix(mat1, mat2);
    multiplyMatrix(mat1, mat2);

    printf("\nTranspose of Matrix 1:\n");
    transposeMatrix(mat1);

    printf("\nTranspose of Matrix 2:\n");
    transposeMatrix(mat2);

    return 0;
}

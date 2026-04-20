#include <stdio.h>  // Fixed size for 3x3 matrices
// Function to input a 3x3 matrix
void inputMatrix(int mat[3][3]) {
    printf("Enter elements of a 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to print a 3x3 matrix
void printMatrix(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Matrix addition
void addMatrix(int mat1[3][3], int mat2[3][3]) {
    int result[3][3];
    printf("\nMatrix Addition Result:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Matrix multiplication
void multiplyMatrix(int mat1[3][3], int mat2[3][3]) {
    int result[3][3];
    printf("\nMatrix Multiplication Result:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Matrix transpose
void transposeMatrix(int mat[3][3]) {
    printf("\nTranspose Result:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[3][3], mat2[3][3];

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

#include <stdio.h>

#define MAX_SIZE 10

void matrixMultiplication(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int res[][MAX_SIZE], int m, int n, int q) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            res[i][j] = 0;
            for (k = 0; k < n; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix1(int mat1[][MAX_SIZE], int m, int n) {
    int i, j;
   
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }
}
void displayMatrix2(int mat2[][MAX_SIZE], int p, int q) {
    int i, j;
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
}
void displayMatrixMultiplication(int mat[][MAX_SIZE], int m, int q) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], res[MAX_SIZE][MAX_SIZE];
    int m, n, p, q;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements of matrix 1:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    printf("Enter the elements of matrix 2:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    printf(" Matrix1:\n");
    displayMatrix1( mat1,  m,  n);
     printf(" Matrix2:\n");
    displayMatrix1( mat2,  p,  q);
    matrixMultiplication(mat1, mat2, res, m, n, q);

    printf("Resultant matrix after multiplication:\n");
    displayMatrixMultiplication(res, m, q);

    return 0;
}
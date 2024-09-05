#include <stdio.h>

#define MAX 10

void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    int i, j, k;
    for (i = 0; i < rowFirst; i++) {
        for (j = 0; j < columnSecond; j++) {
            result[i][j] = 0;
            for (k = 0; k < columnFirst; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int row, int column) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int first[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}};
    int second[MAX][MAX] = {{7, 8}, {9, 10}, {11, 12}};
    int result[MAX][MAX];
    int rowFirst = 2, columnFirst = 3, rowSecond = 3, columnSecond = 2;

    multiplyMatrices(first, second, result, rowFirst, columnFirst, rowSecond, columnSecond);
    printf("Product of matrices:\n");
    printMatrix(result, rowFirst, columnSecond);
    return 0;
}


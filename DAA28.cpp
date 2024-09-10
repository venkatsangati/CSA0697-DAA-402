#include <stdio.h>

void pascal_triangle(int rows) {
    int i, j, a = 1;

    for (i = 0; i < rows; i++) {
        for (int spaces = 1; spaces <= rows - i; spaces++) {
            printf("  "); // Print spaces for alignment
        }

        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                a = 1;
            } else {
                a = a * (i - j + 1) / j;
            }

            printf("%4d", a);
        }

        printf("\n");
    }
}

int main() {
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    pascal_triangle(rows);

    return 0;
}

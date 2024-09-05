#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        return -1;
    } else if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int num_terms;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &num_terms);

    if (num_terms <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    printf("Fibonacci Series:\n");
    for (int i = 1; i <= num_terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}


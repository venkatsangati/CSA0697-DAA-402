#include <stdio.h>

void factors(int n) {
    printf("Factors of %d are: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            printf("%d ", i);
    }
}

int main() {
    int n = 28;
    factors(n);
    return 0;
}


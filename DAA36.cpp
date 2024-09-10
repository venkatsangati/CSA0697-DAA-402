#include <stdio.h>

void container_loader(int weights[], int n, int capacity) {
    int total_weight = 0;
    printf("Items selected: ");
    for (int i = 0; i < n; i++) {
        if (total_weight + weights[i] <= capacity) {
            printf("%d ", weights[i]);
            total_weight += weights[i];
        }
    }
    printf("\nTotal weight: %d\n", total_weight);
}

int main() {
    int weights[] = {10, 20, 30, 40, 50};
    int n = 5;
    int capacity = 100;

    container_loader(weights, n, capacity);

    return 0;
}


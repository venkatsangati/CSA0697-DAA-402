#include <stdio.h>

struct Item {
    int value, weight;
};

void knapsack(struct Item items[], int n, int capacity) {
    float total_value = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            total_value += items[i].value;
            capacity -= items[i].weight;
        } else {
            total_value += items[i].value * ((float) capacity / items[i].weight);
            break;
        }
    }

    printf("Maximum value in knapsack: %.2f\n", total_value);
}

int main() {
    struct Item items[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    knapsack(items, n, capacity);
    return 0;
}


#include <stdio.h>

int isSolution(int s, int k, int arr[], int total, int sum) {
    return ((s + total >= sum) && (s == sum || s + arr[k] <= sum));
}

void sum_of_subsets(int s, int k, int r, int arr[], int x[], int n, int sum) {
    x[k] = 1;
    if (s + arr[k] == sum) {
        printf("\nSubset: ");
        for (int i = 0; i <= k; i++) {
            if (x[i] == 1)
                printf("%d ", arr[i]);
        }
        printf("\n");
    } else if (isSolution(s, k, arr, r, sum)) {
        sum_of_subsets(s + arr[k], k + 1, r - arr[k], arr, x, n, sum);
    }

    if (isSolution(s, k, arr, r, sum)) {
        x[k] = 0;
        sum_of_subsets(s, k + 1, r - arr[k], arr, x, n, sum);
    }
}

int main() {
    int arr[] = {3, 1, 2, 5};
    int n = 4, sum = 6;
    int x[4] = {0}, total = 0;

    for (int i = 0; i < n; i++)
        total += arr[i];

    printf("Subsets with sum %d:", sum);
    sum_of_subsets(0, 0, total, arr, x, n, sum);

    return 0;
}


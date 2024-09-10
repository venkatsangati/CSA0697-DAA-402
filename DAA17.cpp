#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair minmax, mml, mmr;
    
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }
    
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }
    
    int mid = (low + high) / 2;
    mml = findMinMax(arr, low, mid);
    mmr = findMinMax(arr, mid + 1, high);
    
    minmax.min = (mml.min < mmr.min) ? mml.min : mmr.min;
    minmax.max = (mml.max > mmr.max) ? mml.max : mmr.max;
    
    return minmax;
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 1, 23, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Pair minmax = findMinMax(arr, 0, n - 1);
    
    printf("Minimum element: %d\n", minmax.min);
    printf("Maximum element: %d\n", minmax.max);
    return 0;
}


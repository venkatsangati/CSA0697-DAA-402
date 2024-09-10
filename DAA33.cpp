#include <stdio.h>

void insert_number(int arr[], int n, int num, int pos) {
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = num;
}

int main() {
    int arr[100] = {1, 2, 3, 5};
    int n = 4; 
    int num = 4, pos = 4;

    insert_number(arr, n, num, pos);
    n++;  

    printf("Updated list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}


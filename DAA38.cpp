#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void solve(int cost[4][4], int n, int assigned[], int row, int current_cost, int *min_cost) {
    if (row == n) {
        *min_cost = min(*min_cost, current_cost);
        return;
    }

    for (int col = 0; col < n; col++) {
        int assigned_before = 0;
        for (int r = 0; r < row; r++) {
            if (assigned[r] == col) {
                assigned_before = 1;
                break;
            }
        }

        if (!assigned_before) {
            assigned[row] = col;
            solve(cost, n, assigned, row + 1, current_cost + cost[row][col], min_cost);
            assigned[row] = -1;  
        }
    }
}

int solveAssignmentProblem(int cost[4][4], int n) {
    int min_cost = INT_MAX;
    int assigned[4] = {-1, -1, -1, -1};

    solve(cost, n, assigned, 0, 0, &min_cost);
    return min_cost;
}

int main() {
    int cost[4][4] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    int n = 4;
    printf("Minimum cost: %d\n", solveAssignmentProblem(cost, n));
    return 0;
}


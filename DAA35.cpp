#include <stdio.h>
#include <stdbool.h>

bool isSafe(int v, int graph[4][4], int color[], int c) {
    for (int i = 0; i < 4; i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColoringUtil(int graph[4][4], int m, int color[], int v) {
    if (v == 4)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

void graphColoring(int graph[4][4], int m) {
    int color[4] = {0};
    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists with coloring: ");
        for (int i = 0; i < 4; i++)
            printf("%d ", color[i]);
    } else {
        printf("No solution exists");
    }
}

int main() {
    int graph[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; 
    graphColoring(graph, m);
    return 0;
}


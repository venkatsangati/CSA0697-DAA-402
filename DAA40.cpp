#include <stdio.h>
#include <stdbool.h>

bool isSafe(int v, int graph[5][5], int path[], int pos) {
    if (graph[path[pos-1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}

bool hamiltonianCycleUtil(int graph[5][5], int path[], int pos) {
    if (pos == 5) {
        return graph[path[pos-1]][path[0]] == 1;
    }

    for (int v = 1; v < 5; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos+1))
                return true;

            // Backtracking
            path[pos] = -1;
        }
    }

    return false;
}

void hamiltonianCycle(int graph[5][5]) {
    int path[5] = {0, -1, -1, -1, -1}; 

    if (hamiltonianCycleUtil(graph, path, 1)) {
        printf("Hamiltonian Cycle exists: ");
        for (int i = 0; i < 5; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]);  
    } else {
        printf("No Hamiltonian Cycle exists\n");
    }
}

int main() {
    int graph[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);
    return 0;
}


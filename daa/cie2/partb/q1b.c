#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6
#define INF INT_MAX

// Prim's algorithm for MST
void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, u;
        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], u = v;

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    int totalCost = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i] + 1, i + 1, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Minimum Cost Achieved: %d\n", totalCost);
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 2, 0, 8, 0, 0},
        {2, 0, 3, 1, 0, 0},
        {0, 3, 0, 0, 7, 8},
        {8, 1, 0, 0, 4, 0},
        {0, 0, 7, 4, 0, 3},
        {0, 0, 8, 0, 3, 0}
    };

    printf("Algorithm: Prim's (Greedy Solution for Car Driver)\n");
    primMST(graph);
    printf("Design Strategy: Greedy Method\n");
    printf("Time Complexity: O(V^2)\n");

    return 0;
}

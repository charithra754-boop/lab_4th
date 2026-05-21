#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6
#define INF INT_MAX

// This function finds the next vertex to add to the MST.
// It scans all vertices and returns the unused vertex with the smallest key.
int minKey(int key[V], bool used[V]) {
    int min = INF, minIndex = -1;
    for (int i = 0; i < V; i++)
        if (!used[i] && key[i] < min)
            min = key[i], minIndex = i;
    return minIndex;
}

// Prim's algorithm builds an MST by always choosing the cheapest edge
// that connects a new vertex to the already-built tree.
void prim(int graph[V][V]) {
    int parent[V], key[V];
    bool used[V] = {false};

    parent[0] = -1;  // root of MST has no parent
    key[0] = 0;      // start from vertex 0
    for (int i = 1; i < V; i++)
        key[i] = INF;  // other vertices are not connected yet

    // repeat until MST has V-1 edges
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, used);  // choose the next cheapest vertex
        used[u] = true;             // include it in the MST
        // update neighbors of u: if the edge u-v is cheaper than current best, replace it
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !used[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    int total = 0;
    printf("Edge  Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d    %d\n", parent[i] + 1, i + 1, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Minimum Cost Achieved: %d\n", total);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 8, 0, 0},
        {2, 0, 3, 1, 0, 0},
        {0, 3, 0, 0, 7, 8},
        {8, 1, 0, 0, 4, 0},
        {0, 0, 7, 4, 0, 3},
        {0, 0, 8, 0, 3, 0}
    };

    prim(graph);
    return 0;
}

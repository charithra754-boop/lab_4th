#include <stdio.h>
#include <limits.h>

#define V 5
#define INF INT_MAX

void printPath(int parent[], int j) {
    if (parent[j] == -1) return;
    printPath(parent, parent[j]);
    printf(" -> %d", j + 1);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V] = {0}, parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, u;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], u = v;

        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }

    printf("Source Location: %d\n", src + 1);
    printf("Destination\tDistance\tPath\n");
    for (int i = 0; i < V; i++) {
        if (i == src) continue;
        printf("%d \t\t %d \t\t %d", i + 1, dist[i], src + 1);
        printPath(parent, i);
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {0, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 0);

    printf("\nDesign Strategy: Greedy Method\n");
    printf("Time Complexity: O(V^2)\n");

    return 0;
}
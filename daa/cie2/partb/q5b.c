#include <stdio.h>
#include <limits.h>

#define V 6
#define E 9
#define INF INT_MAX

struct Edge { int src, dest, weight; };

int main() {
    struct Edge edges[E] = {
        {0, 3, 1}, {0, 5, -3}, {1, 0, -4},
        {1, 3, -1}, {2, 1, 8}, {2, 4, -3},
        {3, 5, 4}, {4, 3, -2}, {4, 5, 2}
    };
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;  // start with unknown distance for every vertex

    dist[2] = 0; // source = c, distance from source to itself is 0

    // Relax every edge V-1 times so shortest paths can propagate.
    // Each iteration improves distances using one more edge.
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w; // update if we found a shorter path
        }
    }

    char nodes[] = {'a', 'b', 'c', 'd', 'e', 't'};
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%c \t\t %d\n", nodes[i], dist[i]);

    return 0;
}

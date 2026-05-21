#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int v, e;
    struct Edge* edge;
};

struct Graph* createGraph(int v, int e) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->e = e;
    graph->edge = (struct Edge*)malloc(graph->e * sizeof(struct Edge));
    return graph;
}

void BellmanFord(struct Graph* graph, int src) {
    int v = graph->v;
    int e = graph->e;
    int dist[v];

    for (int i = 0; i < v; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = graph->edge[j].src;
            int v_idx = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v_idx])
                dist[v_idx] = dist[u] + weight;
        }
    }

    printf("Vertex   Distance from Source\n");
    char nodes[] = {'a', 'b', 'c', 'd', 'e', 't'};
    for (int i = 0; i < v; ++i)
        printf("%c \t\t %d\n", nodes[i], dist[i]);
}

int main() {
    int v = 6; // a:0, b:1, c:2, d:3, e:4, t:5
    int e = 9;
    struct Graph* graph = createGraph(v, e);

    // a -> d: 1, a -> t: -3, b -> a: -4, b -> d: -1, c -> b: 8, c -> e: -3, d -> t: 4, e -> d: -2, e -> t: 2
    graph->edge[0] = (struct Edge){0, 3, 1};
    graph->edge[1] = (struct Edge){0, 5, -3};
    graph->edge[2] = (struct Edge){1, 0, -4};
    graph->edge[3] = (struct Edge){1, 3, -1};
    graph->edge[4] = (struct Edge){2, 1, 8};
    graph->edge[5] = (struct Edge){2, 4, -3};
    graph->edge[6] = (struct Edge){3, 5, 4};
    graph->edge[7] = (struct Edge){4, 3, -2};
    graph->edge[8] = (struct Edge){4, 5, 2};

    printf("Algorithm: Bellman-Ford Shortest Path\n");
    BellmanFord(graph, 2); // Using 'c' (index 2) as source
    printf("Design Strategy: Dynamic Programming\n");
    printf("Time Complexity: O(V * E)\n");

    return 0;
}

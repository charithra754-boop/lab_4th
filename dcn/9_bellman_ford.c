#include <stdio.h>
#define INF 99999

int main() {
    int V, E, u[20], v[20], w[20], dist[20];
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    
    printf("Enter source, destination, and weight for each edge:\n");
    for (int i = 0; i < E; i++) scanf("%d %d %d", &u[i], &v[i], &w[i]);
    
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[0] = 0; // Source is 0
    
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }
    
    printf("Vertex\tDistance from Source (0)\n");
    for (int i = 0; i < V; i++) printf("%d\t%d\n", i, dist[i]);
    return 0;
}

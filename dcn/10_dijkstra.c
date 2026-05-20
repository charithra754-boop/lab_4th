#include <stdio.h>
#define INF 9999

int main() {
    int n, cost[10][10], dist[10], visited[10] = {0}, min, u;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = INF;
        }

    for (int i = 0; i < n; i++) dist[i] = cost[0][i];
    visited[0] = 1; dist[0] = 0;

    for (int count = 1; count < n; count++) {
        min = INF;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) { min = dist[i]; u = i; }
        
        visited[u] = 1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && min + cost[u][i] < dist[i])
                dist[i] = min + cost[u][i];
    }
    
    printf("Vertex\tDistance from Source (0)\n");
    for (int i = 0; i < n; i++) printf("%d\t%d\n", i, dist[i]);
    return 0;
}

#include <stdio.h>
#define N 10
int main() {
    int graph[N][N] = {0};
    int edges[][2] = {
        {1,2}, {1,3}, {2,3}, {2,4}, {2,5}, {3,6}, {3,7}, 
        {4,5}, {4,8}, {4,9}, {5,9}, {6,7}, {9,10}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);
    for(int i = 0; i < numEdges; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        graph[u][v] = graph[v][u] = 1;
    }//bfs logic for bipartite check
    int color[N]; // -1: unvisited, 0: Red, 1: Blue
    for(int i=0; i<N; i++) color[i] = -1;
    int queue[N], f = 0, r = 0;// Start at Node 1
    color[0] = 0; 
    queue[r++] = 0;
    int isBipartite = 1;
    while(f < r) {
        int u = queue[f++];
        for(int v = 0; v < N; v++) {
            if(graph[u][v]) {
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    queue[r++] = v;
                } else if(color[v] == color[u]) {
                    isBipartite = 0; // Found a conflict!
                }
            }
        }
    }
    printf("Algorithm: BFS Layer-based Coloring\n");
    printf("Result: %s\n", isBipartite ? "Bipartite" : "Non-Bipartite (due to odd cycles)");
    
    return 0;
}
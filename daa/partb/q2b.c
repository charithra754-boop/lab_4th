#include <stdio.h>

#define N 5 // Number of nodes

int main() {
    // 1. Setup the Graph (Adjacency Matrix)
    int graph[N][N] = {
        {0, 1, 0, 1, 0}, 
        {0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 1}, 
        {0, 0, 1, 0, 0}
    };
    // 2. State Initialization (Using -1 for unvisited to match color logic)
    int visited[N]; 
    for(int i = 0; i < N; i++) visited[i] = -1;
    // 3. Queue Setup
    int queue[N], f = 0, r = 0;
    // Start at Node 1 (Index 0)
    visited[0] = 1; 
    queue[r++] = 0;
    // 4. BFS Logic (Matches your Bipartite while loop exactly)
    while(f < r) {
        int u = queue[f++]; // Dequeue
        for(int v = 0; v < N; v++) {
            if(graph[u][v]) { // If there is an edge
                if(visited[v] == -1) { // If not visited
                    visited[v] = 1;    // Mark as visited
                    queue[r++] = v;   // Enqueue
                }
            }
        }
    }
    // 5. Output
    printf("Algorithm: BFS Reachability\n");
    printf("Nodes reachable from Node 1: ");
    for(int i = 0; i < N; i++) {
        if(visited[i] == 1) printf("%d ", i + 1);
    }
    printf("\n");

    return 0;
}
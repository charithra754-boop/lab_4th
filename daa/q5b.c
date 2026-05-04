#include <stdio.h>
#include <stdbool.h>

#define N 10

// Graph Adjacency Matrix for Nodes 1 to 10
// Edges: (1,2), (1,3), (2,4), (2,5), (3,6), (3,7), (4,8), (5,9), (9,10)
int graph[N][N] = {0};

void addEdge(int u, int v) {
    graph[u-1][v-1] = 1;
    graph[v-1][u-1] = 1;
}

void setupGraph() {
    addEdge(1, 2); addEdge(1, 3);
    addEdge(2, 4); addEdge(2, 5);
    addEdge(3, 6); addEdge(3, 7);
    addEdge(4, 8); addEdge(5, 9);
    addEdge(9, 10);
}

void bfsColoring(int startNode) {
    int color[N];
    for(int i=0; i<N; i++) color[i] = -1; // -1 means uncolored
    
    int queue[N];
    int front = 0, rear = 0;
    
    // 0 = Red (Odd layer), 1 = Blue (Even layer)
    color[startNode] = 0; 
    queue[rear++] = startNode;
    
    bool isBipartite = true;
    
    printf("BFS Node Coloring:\n");
    
    while (front < rear) {
        int u = queue[front++];
        
        printf("Node %d is colored %s\n", u + 1, color[u] == 0 ? "Red" : "Blue");
        
        for (int v = 0; v < N; v++) {
            if (graph[u][v] == 1) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    queue[rear++] = v;
                } else if (color[v] == color[u]) {
                    isBipartite = false;
                }
            }
        }
    }
    
    printf("\nAlgorithm Used: Breadth First Search (BFS) Bipartite Check\n");
    if (isBipartite) {
        printf("Graph Type: Bipartite Graph (can be colored with 2 colors without adjacent nodes having the same color).\n");
    } else {
        printf("Graph Type: Not a Bipartite Graph.\n");
    }
}

int main() {
    setupGraph();
    bfsColoring(0); // Start from Node 1 (index 0)
    return 0;
}

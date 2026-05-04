#include <stdio.h>
#include <stdbool.h>

#define N 5

// Graph Adjacency Matrix for Nodes 1 to 5
int graph[N][N] = {
    {0, 1, 0, 1, 0}, // 1 -> 2, 1 -> 4
    {0, 0, 1, 0, 0}, // 2 -> 3
    {0, 0, 0, 0, 0}, // 3 -> none
    {0, 1, 0, 0, 1}, // 4 -> 2, 4 -> 5
    {0, 0, 1, 0, 0}  // 5 -> 3
};

void bfs(int startNode) {
    bool visited[N] = {false};
    int queue[N];
    int front = 0, rear = 0;
    
    visited[startNode] = true;
    queue[rear++] = startNode;
    
    printf("Reachable nodes from source node %d: ", startNode + 1);
    
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr + 1);
        
        for (int i = 0; i < N; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int source = 0; // Node 1 (0-indexed)
    printf("Graph Reachability using BFS\n");
    bfs(source);
    
    printf("Time Complexity: O(V + E) where V is vertices and E is edges.\n");
    return 0;
}

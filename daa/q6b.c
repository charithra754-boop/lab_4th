#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 5

int graph[N][N] = {
    {0, 10, 0, 0, 100},
    {10, 0, 50, 0, 0},
    {0, 50, 0, 20, 10},
    {0, 0, 20, 0, 60},
    {100, 0, 10, 60, 0}
};

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < N; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\t Distance\tPath\n");
    for (int i = 0; i < N; i++) {
        if (i == src) continue;
        printf("%d -> %d \t %d\t\t%d ", src + 1, i + 1, dist[i], src + 1);
        
        int p = parent[i];
        int path[N];
        int count = 0;
        while (p != -1 && p != src) {
            path[count++] = p;
            p = parent[p];
        }
        for(int j=count-1; j>=0; j--) {
            printf("-> %d ", path[j] + 1);
        }
        printf("-> %d\n", i + 1);
    }
}

void dijkstra(int src) {
    int dist[N];
    bool sptSet[N];
    int parent[N];
    
    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        
        for (int v = 0; v < N; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }
    
    printSolution(dist, parent, src);
}

int main() {
    int startLocation = 0; // Node 1 (index 0)
    
    printf("Dijkstra's Algorithm - Shortest Paths from Location %d\n", startLocation + 1);
    dijkstra(startLocation);
    
    printf("\nDesign Strategy: Greedy Method\n");
    printf("Time Complexity: O(V^2) with Adjacency Matrix\n");
    
    return 0;
}

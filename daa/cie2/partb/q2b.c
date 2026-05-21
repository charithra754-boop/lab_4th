#include <stdio.h>
#include <stdlib.h>

#define V 5

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

struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph) {
    int v = graph->v;
    struct Edge result[v];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->e, sizeof(graph->edge[0]), myComp);

    struct subset* subsets = (struct subset*)malloc(v * sizeof(struct subset));
    for (int v_idx = 0; v_idx < v; ++v_idx) {
        subsets[v_idx].parent = v_idx;
        subsets[v_idx].rank = 0;
    }

    while (e < v - 1 && i < graph->e) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Following are the edges in the constructed MST:\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost for Spanning Tree: %d\n", minimumCost);
}

int main() {
    int e = 8;
    struct Graph* graph = createGraph(V, e);

    // 1-2: 10, 1-4: 5, 1-5: 5, 2-3: 1, 2-4: 6, 3-4: 2, 4-5: 3, 5-3: 7
    graph->edge[0].src = 0; graph->edge[0].dest = 1; graph->edge[0].weight = 10;
    graph->edge[1].src = 0; graph->edge[1].dest = 3; graph->edge[1].weight = 5;
    graph->edge[2].src = 0; graph->edge[2].dest = 4; graph->edge[2].weight = 5;
    graph->edge[3].src = 1; graph->edge[3].dest = 2; graph->edge[3].weight = 1;
    graph->edge[4].src = 1; graph->edge[4].dest = 3; graph->edge[4].weight = 6;
    graph->edge[5].src = 2; graph->edge[5].dest = 3; graph->edge[5].weight = 2;
    graph->edge[6].src = 3; graph->edge[6].dest = 4; graph->edge[6].weight = 3;
    graph->edge[7].src = 4; graph->edge[7].dest = 2; graph->edge[7].weight = 7;

    printf("Algorithm: Kruskal's (Greedy Solution for Phone Company)\n");
    KruskalMST(graph);
    printf("Design Strategy: Greedy Method\n");
    printf("Time Complexity: O(E log E) or O(E log V)\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 8

struct Edge { int src, dest, weight; };
struct subset { int parent, rank; };

// Find returns the set representative for vertex i.
// This helps detect whether two vertices are already connected.
int find(struct subset subsets[V], int i) {
    return subsets[i].parent == i ? i : (subsets[i].parent = find(subsets, subsets[i].parent));
}

// unite merges two sets by rank so the tree stays shallow.
// This keeps future find operations fast.
void unite(struct subset subsets[V], int x, int y) {
    x = find(subsets, x);
    y = find(subsets, y);
    if (x == y) return;
    if (subsets[x].rank < subsets[y].rank)
        subsets[x].parent = y;
    else if (subsets[y].rank < subsets[x].rank)
        subsets[y].parent = x;
    else {
        subsets[y].parent = x;
        subsets[x].rank++;
    }
}

// Compare edges by weight so qsort can order them from smallest to largest.
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm adds the smallest edges first,
// but only when they connect two different components.
int main() {
    struct Edge edges[E] = {
        {0,1,10}, {0,3,5}, {0,4,5}, {1,2,1},
        {1,3,6}, {2,3,2}, {3,4,3}, {4,2,7}
    };

    struct subset subsets[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, E, sizeof(edges[0]), compareEdges);

    int cost = 0;
    printf("Edge  Weight\n");
    for (int i = 0, count = 0; i < E && count < V - 1; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);
        if (x != y) {
            unite(subsets, x, y);
            printf("%d -- %d    %d\n", edges[i].src + 1, edges[i].dest + 1, edges[i].weight);
            cost += edges[i].weight;
            count++;
        }
    }

    printf("Minimum Cost for Spanning Tree: %d\n", cost);
    return 0;
}

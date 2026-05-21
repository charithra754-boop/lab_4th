#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

void knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    printf("Maximum value that can be carried: %d\n", K[n][W]);
    
    printf("Items selected: ");
    int res = K[n][W];
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;
        else {
            printf("Item %d (Value %d, Weight %d) ", i, val[i - 1], wt[i - 1]);
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    printf("\n");
}

int main() {
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
    int W = 7;
    int n = sizeof(val) / sizeof(val[0]);
    
    printf("Algorithm: 0/1 Knapsack (Alia's Trekking Expedition)\n");
    knapSack(W, wt, val, n);
    printf("Design Strategy: Dynamic Programming\n");
    printf("Time Complexity: O(n * W)\n");
    
    return 0;
}

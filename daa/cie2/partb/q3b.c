#include <stdio.h>

int main() {
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
    int W = 7;
    int n = sizeof(val) / sizeof(val[0]);
    int K[5][8] = {0};

    // Build the DP table row by row.
    // For each item i and capacity w:
    //   if item i fits, choose the better of including it or excluding it.
    //   otherwise, copy the previous row.
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                int withItem = val[i - 1] + K[i - 1][w - wt[i - 1]];
                K[i][w] = withItem > K[i - 1][w] ? withItem : K[i - 1][w];
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    printf("Maximum value that can be carried: %d\n", K[n][W]);

    int res = K[n][W];
    int w = W;
    printf("Items selected: ");
    // Recover chosen items by comparing current and previous rows.
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != K[i - 1][w]) {
            // If the value changed, item i was included.
            printf("Item %d (Value %d, Weight %d) ", i, val[i - 1], wt[i - 1]);
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }
    printf("\n");
    return 0;
}

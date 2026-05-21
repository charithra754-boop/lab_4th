#include <stdio.h>
#include <stdlib.h>

typedef struct { int start, finish, profit; } Job;

// Sort jobs by finish time so we consider the earliest-ending jobs first.
int compareJob(const void* a, const void* b) {
    return ((Job*)a)->finish - ((Job*)b)->finish;
}

// Find the rightmost job before i that does not conflict with job i.
// This helps decide whether job i can be added to the existing solution.
int lastNonConflict(Job jobs[], int i) {
    for (int j = i - 1; j >= 0; j--)
        if (jobs[j].finish <= jobs[i].start)
            return j;
    return -1;
}

int main() {
    Job jobs[] = {{1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    qsort(jobs, n, sizeof(Job), compareJob);

    int dp[4];
    dp[0] = jobs[0].profit;

    // For each job i, compute the best profit including or excluding it.
    for (int i = 1; i < n; i++) {
        int incl = jobs[i].profit;
        int l = lastNonConflict(jobs, i);
        if (l != -1) incl += dp[l];
        // dp[i] is the best profit if we consider jobs up to i.
        dp[i] = incl > dp[i - 1] ? incl : dp[i - 1];
    }

    printf("Maximum Profit: %d\n", dp[n - 1]);
    return 0;
}

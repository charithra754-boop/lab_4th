#include <stdio.h>
#include <stdlib.h>

struct Job {
    int start, finish, profit;
};

int compareJobs(const void* a, const void* b) {
    struct Job* j1 = (struct Job*)a;
    struct Job* j2 = (struct Job*)b;
    return j1->finish - j2->finish;
}

int latestNonConflicting(struct Job jobs[], int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (jobs[j].finish <= jobs[i].start)
            return j;
    }
    return -1;
}

void findMaxProfit(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compareJobs);

    int *table = (int*)malloc(n * sizeof(int));
    table[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int inclProf = jobs[i].profit;
        int l = latestNonConflicting(jobs, i);
        if (l != -1)
            inclProf += table[l];
        
        table[i] = (inclProf > table[i - 1]) ? inclProf : table[i - 1];
    }

    printf("Maximum Profit: %d\n", table[n - 1]);
    free(table);
}

int main() {
    struct Job jobs[] = {{1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    printf("Algorithm: Weighted Interval Scheduling (Drama Venue Allocation)\n");
    findMaxProfit(jobs, n);
    printf("Design Strategy: Dynamic Programming\n");
    printf("Time Complexity: O(n^2) with simple search, O(n log n) with binary search\n");

    return 0;
}

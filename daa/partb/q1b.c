#include <stdio.h>
#include <stdbool.h>
#define N 3
// Men: A(0), B(1), C(2)
// Women: V(0), W(1), X(2)
int prefer[2 * N][N] = {
    // Men's preferences (A, B, C)
    {0, 1, 2}, 
    {1, 0, 2},
    {0, 1, 2}, 
    // Women's preferences (V, W, X)
    {0, 1, 2}, 
    {1, 2, 0}, 
    {2, 0, 1} 
};
bool notloyal(int prefer[2*N][N], int w, int m, int m1) {
    for (int i = 0; i < N; i++) {
        if (prefer[w + N][i] == m1) return true;
        if (prefer[w + N][i] == m) return false;
    }
}
void stableMarriage() {
    int wPartner[N];
    bool mFree[N];
    for (int i = 0; i < N; i++) {
        wPartner[i] = -1;
        mFree[i] = true;
    }
    int freeCount = N;
    while (freeCount > 0) {
        int m;
        for (m = 0; m < N; m++)
            if (mFree[m]) break; 
        for (int i = 0; i < N && mFree[m]; i++) {
            int w = prefer[m][i];
            if (wPartner[w] == -1) {
                wPartner[w] = m;
                mFree[m] = false;
                freeCount--;
            } else {
                int m1 = wPartner[w];
                if (notloyal(prefer, w, m, m1) == true) {
                    wPartner[w] = m;
                    mFree[m] = false;
                    mFree[m1] = true;
                }
            }
        }
    }
    printf("Stable Pairings:\n");
    printf("Woman   Man\n");
    char menNames[] = {'A', 'B', 'C'};
    char womenNames[] = {'V', 'W', 'X'};
    for (int i = 0; i < N; i++) {
        printf("  %c      %c\n", womenNames[i], menNames[wPartner[i]]);
    }
    printf("\nTime Complexity: O(N^2)\n");
}
int main() {
    stableMarriage();
    return 0;
}

#include <stdio.h>

// f(n) = 4n + 3
// To prove f(n) = O(n), find c and n0 such that f(n) <= c*n for n >= n0.
// Let c = 5. 4n + 3 <= 5n => 3 <= n. So n0 = 3.

int main() {
    int c = 5;
    int n0 = 3;
    
    printf("Proving f(n) = 4n + 3 is O(n)\n");
    printf("We choose c = %d and n0 = %d\n", c, n0);
    printf("For n >= %d, f(n) <= %d * n\n\n", n0, c);
    
    printf("%-5s | %-10s | %-10s\n", "n", "f(n)", "c*n");
    printf("--------------------------------\n");
    for (int n = 10; n <= 30; n++) {
        int fn = 4 * n + 3;
        int cn = c * n;
        printf("%-5d | %-10d | %-10d", n, fn, cn);
        if (fn <= cn) {
            printf(" (Condition Holds)\n");
        } else {
            printf(" (Condition Fails)\n");
        }
    }
    
    return 0;
}

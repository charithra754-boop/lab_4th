#include <stdio.h>

// f(n) = 3n^2 + 4n + 3
// To prove f(n) = Omega(n), we need to find c and n0 such that f(n) >= c*n for all n >= n0.
// Let c = 1, n0 = 1.
// 3n^2 + 4n + 3 >= 1*n for all n >= 1.

int main() {
    int c = 1;
    int n0 = 1;
    
    printf("Proving f(n) = 3n^2 + 4n + 3 is Omega(n)\n");
    printf("We choose c = %d and n0 = %d\n", c, n0);
    printf("For n >= %d, f(n) >= %d * n\n\n", n0, c);
    
    printf("%-5s | %-10s | %-10s\n", "n", "f(n)", "c*n");
    printf("--------------------------------\n");
    for (int n = 10; n <= 30; n++) {
        int fn = 3 * n * n + 4 * n + 3;
        int cn = c * n;
        printf("%-5d | %-10d | %-10d", n, fn, cn);
        if (fn >= cn) {
            printf(" (Condition Holds)\n");
        } else {
            printf(" (Condition Fails)\n");
        }
    }
    
    return 0;
}

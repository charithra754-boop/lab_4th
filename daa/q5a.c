#include <stdio.h>

// f(n) = 2n + 3n + 5 = 5n + 5
// To prove f(n) = Omega(n), find c and n0 such that f(n) >= c*n for n >= n0.
// Let c = 5, n0 = 1.
// 5n + 5 >= 5n is true for all n >= 1.

int main() {
    int c = 5;
    int n0 = 1;
    const char *csvFile = "q5a.csv";
    
    FILE *csv = fopen(csvFile, "w");
    if (csv == NULL) {
        perror("Unable to create CSV file");
        return 1;
    }
    
    fprintf(csv, "n,f(n),c*n\n");
    
    printf("Proving f(n) = 5n + 5 is Omega(n)\n");
    printf("We choose c = %d and n0 = %d\n", c, n0);
    printf("For n >= %d, f(n) >= %d * n\n\n", n0, c);
    
    printf("%-5s | %-10s | %-10s\n", "n", "f(n)", "c*n");
    printf("--------------------------------\n");
    for (int n = 10; n <= 30; n++) {
        int fn = 5 * n + 5;
        int cn = c * n;
        fprintf(csv, "%d,%d,%d\n", n, fn, cn);
        printf("%-5d | %-10d | %-10d", n, fn, cn);
        if (fn >= cn) {
            printf(" (Condition Holds)\n");
        } else {
            printf(" (Condition Fails)\n");
        }
    }
    
    fclose(csv);
    printf("\nCSV output written to %s\n", csvFile);
    return 0;
}

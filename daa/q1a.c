#include <stdio.h>

// f(n) = 7n + 5
// To prove f(n) = O(n), we need to find c and n0 such that f(n) <= c*n for all n >= n0.
// Let c = 8. Then 7n + 5 <= 8n => 5 <= n. So n0 = 5.

int main() {
    int c = 8;
    int n0 = 5;
    const char *csvFile = "q1a.csv";
    
    FILE *csv = fopen(csvFile, "w");
    if (csv == NULL) {
        perror("Unable to create CSV file");
        return 1;
    }
    
    fprintf(csv, "n,f(n),c*n\n");
    
    printf("Proving f(n) = 7n + 5 is O(n)\n");
    printf("We choose c = %d and n0 = %d\n", c, n0);
    printf("For n >= %d, f(n) <= %d * n\n\n", n0, c);
    
    printf("%-5s | %-10s | %-10s\n", "n", "f(n)", "c*n");
    printf("--------------------------------\n");
    for (int n = 10; n <= 30; n++) {
        int fn = 7 * n + 5;
        int cn = c * n;
        fprintf(csv, "%d,%d,%d\n", n, fn, cn);
        printf("%-5d | %-10d | %-10d", n, fn, cn);
        if (fn <= cn) {
            printf(" (Condition Holds)\n");
        } else {
            printf(" (Condition Fails)\n");
        }
    }
    
    fclose(csv);
    printf("\nCSV output written to %s\n", csvFile);
    return 0;
}

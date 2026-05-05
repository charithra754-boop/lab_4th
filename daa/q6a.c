#include <stdio.h>

// f(n) = 8n^2 + 3n + 3
// To prove f(n) = O(n^2), find c and n0 such that f(n) <= c*n^2 for n >= n0.
// Let c = 14. 8n^2 + 3n + 3 <= 8n^2 + 3n^2 + 3n^2 = 14n^2 for n >= 1.
// So n0 = 1.

int main() {
    int c = 14;
    int n0 = 1;
    const char *csvFile = "q6a.csv";
    
    FILE *csv = fopen(csvFile, "w");
    if (csv == NULL) {
        perror("Unable to create CSV file");
        return 1;
    }
    
    fprintf(csv, "n,f(n),c*n^2\n");
    
    printf("Proving f(n) = 8n^2 + 3n + 3 is O(n^2)\n");
    printf("We choose c = %d and n0 = %d\n", c, n0);
    printf("For n >= %d, f(n) <= %d * n^2\n\n", n0, c);
    
    printf("%-5s | %-15s | %-15s\n", "n", "f(n)", "c*n^2");
    printf("----------------------------------------\n");
    for (int n = 10; n <= 30; n++) {
        long long fn = 8 * n * n + 3 * n + 3;
        long long cn2 = (long long)c * n * n;
        fprintf(csv, "%d,%lld,%lld\n", n, fn, cn2);
        printf("%-5d | %-15lld | %-15lld", n, fn, cn2);
        if (fn <= cn2) {
            printf(" (Condition Holds)\n");
        } else {
            printf(" (Condition Fails)\n");
        }
    }
    
    fclose(csv);
    printf("\nCSV output written to %s\n", csvFile);
    return 0;
}

#include <stdio.h>

// f(n) = 7n^2 + 7n + 5
// To prove f(n) = Theta(n^2), we need c1, c2, n0 such that c1*n^2 <= f(n) <= c2*n^2 for n >= n0.
// Let c1 = 7. 7n^2 <= 7n^2 + 7n + 5 is true for n >= 1.
// Let c2 = 19. 7n^2 + 7n + 5 <= 7n^2 + 7n^2 + 5n^2 = 19n^2 for n >= 1.
// So n0 = 1.

int main() {
    int c1 = 7, c2 = 19, n0 = 1;
    const char *csvFile = "q3a.csv";
    
    FILE *csv = fopen(csvFile, "w");
    if (csv == NULL) {
        perror("Unable to create CSV file");
        return 1;
    }
    
    fprintf(csv, "n,c1*n^2,f(n),c2*n^2\n");
    
    printf("Proving f(n) = 7n^2 + 7n + 5 is Theta(n^2)\n");
    printf("We choose c1 = %d, c2 = %d, and n0 = %d\n", c1, c2, n0);
    printf("For n >= %d, %d*n^2 <= f(n) <= %d*n^2\n\n", n0, c1, c2);
    
    printf("%-5s | %-10s | %-10s | %-10s\n", "n", "c1*n^2", "f(n)", "c2*n^2");
    printf("--------------------------------------------------\n");
    for (int n = 10; n <= 30; n++) {
        int fn = 7 * n * n + 7 * n + 5;
        int c1n2 = c1 * n * n;
        int c2n2 = c2 * n * n;
        fprintf(csv, "%d,%d,%d,%d\n", n, c1n2, fn, c2n2);
        printf("%-5d | %-10d | %-10d | %-10d", n, c1n2, fn, c2n2);
        if (c1n2 <= fn && fn <= c2n2) {
            printf(" (Holds)\n");
        } else {
            printf(" (Fails)\n");
        }
    }
    
    fclose(csv);
    printf("\nCSV output written to %s\n", csvFile);
    return 0;
}

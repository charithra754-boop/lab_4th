#include <stdio.h>

// prove f(n) = 7n^2 + 7n + 5 is theta(n^2) by finding c1=7, c2=19, n0=1 where c1*n^2 <= f(n) <= c2*n^2 for n >= n0
// logic: check bounds for n from 10 to 30, output to console and csv

int main() {
    int c1 = 7, c2 = 19, n0 = 1;
    const char *csvfile = "q3a.csv";
    FILE *csv = fopen(csvfile, "w");
    if (csv == NULL) {
        perror("unable to create csv file");
        return 1;
    }
    fprintf(csv, "n,c1*n^2,f(n),c2*n^2\n");
    printf("proving f(n) = 7n^2 + 7n + 5 is theta(n^2)\nwe choose c1 = %d, c2 = %d, and n0 = %d\nfor n >= %d, %d*n^2 <= f(n) <= %d*n^2\n\n", c1, c2, n0, n0, c1, c2);
    printf("%-5s | %-10s | %-10s | %-10s\n--------------------------------------------------\n", "n", "c1*n^2", "f(n)", "c2*n^2");
    for (int n = 10; n <= 30; n++) {
        int fn = 7 * n * n + 7 * n + 5, c1n2 = c1 * n * n, c2n2 = c2 * n * n;
        fprintf(csv, "%d,%d,%d,%d\n", n, c1n2, fn, c2n2);
        printf("%-5d | %-10d | %-10d | %-10d %s\n", n, c1n2, fn, c2n2, (c1n2 <= fn && fn <= c2n2) ? "(holds)" : "(fails)");
    }
    fclose(csv);
    printf("\ncsv output written to %s\n", csvfile);
    return 0;
}

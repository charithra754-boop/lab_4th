#include <stdio.h>
// prove f(n) = 3n^2 + 4n + 3 is omega(n) by finding c=1, n0=1 where f(n) >= c*n for n >= n0
// logic: check inequality for n from 10 to 30, output to console and csv
int main() {
    int c = 1, n0 = 1;
    const char *csvfile = "q2a.csv";
    FILE *csv = fopen(csvfile, "w");
    if (csv == NULL) {
        perror("unable to create csv file");
        return 1;
    }
    fprintf(csv, "n,f(n),c*n\n");
    for (int n = 10; n <= 30; n++) {
        int fn = 3 * n * n + 4 * n + 3, cn = c * n;
        fprintf(csv, "%d,%d,%d\n", n, fn, cn);
        printf("%d | %d | %d %s\n", n, fn, cn, fn >= cn ? "(condition holds)" : "(condition fails)");
    }
    fclose(csv);
    printf("\ncsv output written to %s\n", csvfile);
    return 0;
}

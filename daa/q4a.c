#include <stdio.h>

// prove f(n) = 4n + 3 is o(n) by finding c=5, n0=3 where f(n) <= c*n for n >= n0
// logic: check inequality for n from 10 to 30, output to console and csv

int main() {
    int c = 5, n0 = 3;
    const char *csvfile = "q4a.csv";
    FILE *csv = fopen(csvfile, "w");
    if (csv == NULL) {
        perror("unable to create csv file");
        return 1;
    }
    fprintf(csv, "n,f(n),c*n\n");
    for (int n = 10; n <= 30; n++) {
        int fn = 4 * n + 3, cn = c * n;
        fprintf(csv, "%d,%d,%d\n", n, fn, cn);
        printf("%d | %d | %d %s\n", n, fn, cn, fn <= cn ? "(condition holds)" : "(condition fails)");
    }
    fclose(csv);
    printf("\ncsv output written to %s\n", csvfile);
    return 0;
}

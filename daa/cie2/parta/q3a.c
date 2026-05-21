#include <stdio.h>
// prove f(n) = 4n^2 + 3n + 5 is theta(n^2) by finding c1=4, c2=12, n0=1 where c1*n^2 <= f(n) <= c2*n^2 for n >= n0
// logic: check bounds for n from 10 to 30, output to console and csv
int main() {
    int c1 = 4, c2 = 12, n0 = 1;
    const char *csvfile = "q3a.csv";
    FILE *csv = fopen(csvfile, "w");
    if (csv == NULL) {
        perror("unable to create csv file");
        return 1;
    }
    fprintf(csv, "n,c1*n^2,f(n),c2*n^2\n");
    for (int n = 10; n <= 30; n++) {
        long long fn = 4LL * n * n + 3 * n + 5, c1n2 = (long long)c1 * n * n, c2n2 = (long long)c2 * n * n;
        fprintf(csv, "%d,%lld,%lld,%lld\n", n, c1n2, fn, c2n2);
        printf("%d | %lld | %lld | %lld %s\n", n, c1n2, fn, c2n2, (c1n2 <= fn && fn <= c2n2) ? "(holds)" : "(fails)");
    }
    fclose(csv);
    printf("\ncsv output written to %s\n", csvfile);
    return 0;
}

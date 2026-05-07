#include <stdio.h>
// prove f(n) = 8n^2 + 3n + 3 is o(n^2) by finding c=14, n0=1 where f(n) <= c*n^2 for n >= n0
// logic: check inequality for n from 10 to 30, output to console and csv
int main() {
    int c = 14, n0 = 1;
    const char *csvfile = "q6a.csv";
    FILE *csv = fopen(csvfile, "w");
    if (csv == NULL) {
        perror("unable to create csv file");
        return 1;
    }
    fprintf(csv, "n,f(n),c*n^2\n");
    for (int n = 10; n <= 30; n++) {
        long long fn = 8LL * n * n + 3 * n + 3, cn2 = (long long)c * n * n;
        fprintf(csv, "%d,%lld,%lld\n", n, fn, cn2);
        printf("%d | %lld | %lld %s\n", n, fn, cn2, fn <= cn2 ? "(condition holds)" : "(condition fails)");
    }
    fclose(csv);
    printf("\ncsv output written to %s\n", csvfile);
    return 0;
}

/*
 * General Part A template.
 *
 * Use this structure in the exam for any asymptotic proof program.
 * Steps:
 * 1. Choose the relation: O, Ω, or Θ.
 * 2. Choose constants: c, n0 or c1, c2, n0.
 * 3. Compute f(n).
 * 4. Compare f(n) with the bound for each n.
 * 5. Print the result and conclude.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define START_N 10
#define END_N 30

typedef enum {
    REL_O,
    REL_OMEGA,
    REL_THETA
} Relation;

typedef struct {
    int id;
    const char *title;
    Relation relation;
    int power;
    long long c;
    long long c1;
    long long c2;
    const char *csvName;
} Problem;

long long computeFn(int id, int n) {
    switch (id) {
        case 1: return 7LL * n + 5;                     // q1: 7n + 5
        case 2: return 3LL * n * n + 4LL * n + 3;      // q2: 3n^2 + 4n + 3
        case 3: return 7LL * n * n + 7LL * n + 5;      // q3: 7n^2 + 7n + 5
        case 4: return 4LL * n + 3;                    // q4: 4n + 3
        case 5: return 5LL * n + 5;                    // q5: 5n + 5
        case 6: return 8LL * n * n + 3LL * n + 3;      // q6: 8n^2 + 3n + 3
        default: return 0;
    }
}

long long powerTerm(int n, int power) {
    if (power == 1) return n;
    if (power == 2) return 1LL * n * n;
    return 1;
}

bool checkRelation(const Problem *p, int n) {
    long long fn = computeFn(p->id, n);
    long long term = powerTerm(n, p->power);

    switch (p->relation) {
        case REL_O:
            return fn <= p->c * term;
        case REL_OMEGA:
            return fn >= p->c * term;
        case REL_THETA:
            return p->c1 * term <= fn && fn <= p->c2 * term;
        default:
            return false;
    }
}

const Problem problems[] = {
    {1, "q1a: 7n + 5 = O(n)", REL_O, 1, 8, 0, 0, "q1a.csv"},
    {2, "q2a: 3n^2 + 4n + 3 = Ω(n)", REL_OMEGA, 1, 1, 0, 0, "q2a.csv"},
    {3, "q3a: 7n^2 + 7n + 5 = Θ(n^2)", REL_THETA, 2, 0, 7, 19, "q3a.csv"},
    {4, "q4a: 4n + 3 = O(n)", REL_O, 1, 5, 0, 0, "q4a.csv"},
    {5, "q5a: 5n + 5 = Ω(n)", REL_OMEGA, 1, 5, 0, 0, "q5a.csv"},
    {6, "q6a: 8n^2 + 3n + 3 = O(n^2)", REL_O, 2, 14, 0, 0, "q6a.csv"}
};

int main(void) {
    int count = sizeof(problems) / sizeof(problems[0]);

    for (int i = 0; i < count; i++) {
        const Problem *p = &problems[i];
        FILE *csv = fopen(p->csvName, "w");
        if (csv == NULL) {
            perror("unable to create csv file");
            return 1;
        }

        if (p->relation == REL_THETA) {
            fprintf(csv, "n,c1*n^%d,f(n),c2*n^%d\n", p->power, p->power);
        } else {
            fprintf(csv, "n,c*n^%d,f(n)\n", p->power);
        }

        printf("\n=== %s ===\n", p->title);
        for (int n = START_N; n <= END_N; n++) {
            long long fn = computeFn(p->id, n);
            long long term = powerTerm(n, p->power);
            bool holds = checkRelation(p, n);

            if (p->relation == REL_THETA) {
                long long c1term = p->c1 * term;
                long long c2term = p->c2 * term;
                fprintf(csv, "%d,%lld,%lld,%lld\n", n, c1term, fn, c2term);
                printf("n=%2d | %lld <= %lld <= %lld %s\n", n, c1term, fn, c2term,
                       holds ? "(holds)" : "(fails)");
            } else {
                long long cterm = p->c * term;
                fprintf(csv, "%d,%lld,%lld\n", n, cterm, fn);
                printf("n=%2d | f(n)=%lld | %lld %s\n", n, fn, cterm,
                       holds ? "(holds)" : "(fails)");
            }
        }
        fclose(csv);
        printf("csv output written to %s\n", p->csvName);
    }

    printf("\nGeneral pattern: choose constants, test inequality for n >= n0, and confirm the bound.\n");
    return 0;
}

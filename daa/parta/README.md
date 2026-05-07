# DAA Part A — Quick Exam Guide

This README gives you the fastest way to write the Part A program and the exact exam-style write-up for every question.
Use it to memorize the code pattern, the constants, and the proof structure.

---

## What Part A is really asking
Each program proves a function belongs to one of these asymptotic classes:

- `O(...)` = upper bound
- `Ω(...)` = lower bound
- `Θ(...)` = tight bound (both upper and lower)

Every question uses the same idea:
- choose constant(s),
- write the inequality,
- verify it for `n >= n0`,
- print the result.

---

## Memorization aid: the simple formula

For each problem, fill in this template:

- `f(n) = ...`
- target: `O(g(n))`, `Ω(g(n))` or `Θ(g(n))`
- choose `c` and `n0` (or `c1`, `c2`, `n0`)
- check `f(n)` vs bound for `n >= n0`

The code pattern is always the same.

---

## Exam write-up template

### Step 1: State the problem
Example:
> Prove that `f(n) = 7n + 5` is `O(n)`.

### Step 2: Declare constants
Example:
> Choose `c = 8` and `n0 = 5`.

### Step 3: Write the inequality
- For `O(n)`: `7n + 5 <= 8n` for all `n >= 5`.
- For `Ω(n)`: `3n^2 + 4n + 3 >= 1*n` for all `n >= 1`.
- For `Θ(n^2)`: `7n^2 <= 7n^2 + 7n + 5 <= 19n^2` for all `n >= 1`.

### Step 4: Explain why it holds
- `O`: `5 <= n` when `n >= 5`.
- `Ω`: the polynomial is always larger than `n` because every term is positive.
- `Θ`: the extra lower-order terms are bounded by a constant multiple of `n^2`.

### Step 5: Conclude
Example:
> Therefore, `f(n) = 7n + 5` is `O(n)`.

---

## Code structure to write quickly

### Template for `O` or `Ω`

```c
#include <stdio.h>

int main(void) {
    int c = ...;
    int n0 = ...;

    for (int n = n0; n <= 30; n++) {
        long long fn = ...;         // compute f(n)
        long long bound = c * ...;  // c*n or c*n*n
        int holds = ...;            // fn <= bound or fn >= bound

        printf("n=%d | f(n)=%lld | bound=%lld %s\n",
               n, fn, bound, holds ? "(holds)" : "(fails)");
    }
    return 0;
}
```

### Template for `Θ`

```c
#include <stdio.h>

int main(void) {
    int c1 = ...;
    int c2 = ...;
    int n0 = ...;

    for (int n = n0; n <= 30; n++) {
        long long fn = ...;
        long long low = c1 * n * n;
        long long high = c2 * n * n;
        int holds = (low <= fn && fn <= high);

        printf("n=%d | %lld <= %lld <= %lld %s\n",
               n, low, fn, high, holds ? "(holds)" : "(fails)");
    }
    return 0;
}
```

---

## Question-by-question cheat sheet

### q1a
- `f(n) = 7n + 5`
- Target: `O(n)`
- Constants: `c = 8`, `n0 = 5`
- Check: `7n + 5 <= 8n`
- Write-up phrase: "upper bound with `c*n`."

### q2a
- `f(n) = 3n^2 + 4n + 3`
- Target: `Ω(n)`
- Constants: `c = 1`, `n0 = 1`
- Check: `3n^2 + 4n + 3 >= 1*n`
- Write-up phrase: "lower bound with `c*n`."

### q3a
- `f(n) = 7n^2 + 7n + 5`
- Target: `Θ(n^2)`
- Constants: `c1 = 7`, `c2 = 19`, `n0 = 1`
- Check: `7n^2 <= f(n) <= 19n^2`
- Write-up phrase: "tight bound with both constants."

### q4a
- `f(n) = 4n + 3`
- Target: `O(n)`
- Constants: `c = 5`, `n0 = 3`
- Check: `4n + 3 <= 5n`

### q5a
- `f(n) = 5n + 5`
- Target: `Ω(n)`
- Constants: `c = 5`, `n0 = 1`
- Check: `5n + 5 >= 5n`

### q6a
- `f(n) = 8n^2 + 3n + 3`
- Target: `O(n^2)`
- Constants: `c = 14`, `n0 = 1`
- Check: `8n^2 + 3n + 3 <= 14n^2`

---

## Fast memory anchors

- `O` = upper bound = `<=`
- `Ω` = lower bound = `>=`
- `Θ` = both bounds
- Always keep the form: `f(n)` and `c * g(n)`.
- In Part A, `g(n)` is always `n` or `n^2`.

Use this README to quickly turn any Part A question into a full exam answer and a complete C program.

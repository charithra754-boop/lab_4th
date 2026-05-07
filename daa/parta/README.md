# DAA Part A — Generalized Proofs and Exam Write-Up

This README explains the common structure of the Part A questions and gives you a memorization pattern for writing the full program in the exam.

---

## What all Part A questions have in common

Each program is a proof by inequality for one of these asymptotic relations:

- `O(n)` or `O(n^2)` — upper bound
- `Ω(n)` — lower bound
- `Θ(n^2)` — tight bound using both upper and lower constants

The general flow is:

1. Identify the function `f(n)`.
2. Choose constants `c`, `c1`, `c2`, and a threshold `n0`.
3. Write the inequality for all `n >= n0`.
4. Check the inequality for several sample values of `n`.
5. Print the result clearly.

This is the exact pattern used by `general.c`.

---

## General pattern for the code

Use these shared pieces in every program:

- `computeFn(n)` — evaluate the formula `f(n)`.
- `powerTerm(n, p)` — compute `n^p`, where `p` is 1 or 2.
- `checkRelation(...)` — verify the chosen inequality.
- `for (n = 10; n <= 30; n++)` — test a range of values.
- `printf` and `fprintf` — print results to the console and CSV.

This fixed structure helps you memorize one template and reuse it.

---

## Exam write-up structure

For each question, write the answer in this order:

1. **State the function:**
   - Example: `f(n) = 7n + 5`
2. **State the target class:**
   - `O(n)`, `Ω(n)`, or `Θ(n^2)`.
3. **Present constants:**
   - `c = 8`, `n0 = 5` for `O(n)`.
   - `c = 5`, `n0 = 1` for `Ω(n)`.
   - `c1 = 7`, `c2 = 19`, `n0 = 1` for `Θ(n^2)`.
4. **Write the inequality:**
   - `f(n) <= c*n`, `f(n) >= c*n`, or `c1*n^2 <= f(n) <= c2*n^2`.
5. **Explain why it holds for all `n >= n0`.**
6. **Conclude:**
   - `Therefore, f(n) = O(n).`
   - `Therefore, f(n) = Ω(n).`
   - `Therefore, f(n) = Θ(n^2).`

---

## Key memorization tips

- Think of every question as the same program with different constants:
  - `q1a`, `q4a`: upper bound `O(...)`
  - `q2a`, `q5a`: lower bound `Ω(...)`
  - `q3a`: tight bound `Θ(...)`
  - `q6a`: upper bound on `n^2`

- Use this phrase:
  - "Choose constants, test the inequality, then conclude the bound."

- If you need to write code fast, remember:
  - `f(n)` formula
  - `if (relation == O) then f(n) <= c * n^p`
  - `if (relation == Ω) then f(n) >= c * n^p`
  - `if (relation == Θ) then c1*n^p <= f(n) <= c2*n^p`

---

## Question-specific summary

- **q1a:** `f(n) = 7n + 5`, prove `O(n)` with `c = 8`, `n0 = 5`.
- **q2a:** `f(n) = 3n^2 + 4n + 3`, prove `Ω(n)` with `c = 1`, `n0 = 1`.
- **q3a:** `f(n) = 7n^2 + 7n + 5`, prove `Θ(n^2)` with `c1 = 7`, `c2 = 19`, `n0 = 1`.
- **q4a:** `f(n) = 4n + 3`, prove `O(n)` with `c = 5`, `n0 = 3`.
- **q5a:** `f(n) = 5n + 5`, prove `Ω(n)` with `c = 5`, `n0 = 1`.
- **q6a:** `f(n) = 8n^2 + 3n + 3`, prove `O(n^2)` with `c = 14`, `n0 = 1`.

---

## How to use `general.c`

- Compile and run it to see the same structure applied to every question.
- It prints the inequality result and writes CSV files.
- It is a reusable template for the exam, since the code pattern stays constant.

---

## Quick exam-friendly checklist

1. Write the `#include <stdio.h>` and `main()`.
2. Define the function and constants.
3. Use a `for` loop from `n = 10` to `n = 30`.
4. Print the inequality status.
5. Write a clear conclusion sentence.

Keep this README and `general.c` together to remember the pattern quickly.
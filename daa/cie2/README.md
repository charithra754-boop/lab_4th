# DAA CIE 2 Question Bank Solutions

This directory contains solutions for the DAA Lab CIE 2 Question Bank.

## Part A: Asymptotic Bounds

Each program proves a function belongs to a specific asymptotic class (O, Ω, or Θ).

- `q1a.c`: Prove `f(n) = 8n^2 + 3n + 3` is `Ω(n)`
- `q2a.c`: Prove `f(n) = 6n^2 + 2n + 2` is `O(n^2)`
- `q3a.c`: Prove `f(n) = 4n^2 + 3n + 5` is `Θ(n^2)`
- `q4a.c`: Prove `f(n) = 5n^2 + 6n + 3` is `Θ(n^2)`
- `q5a.c`: Prove `f(n) = 8n^2 + 3n + 3` is `Ω(n)`
- `q6a.c`: Prove `f(n) = 3n^2 + 4n + 3` is `Ω(n)`

## Part B: Algorithms

- `q1b.c`: **Prim's Algorithm** (Greedy) for the Car Driver problem.
- `q2b.c`: **Kruskal's Algorithm** (Greedy) for the Phone Company Spanning Tree.
- `q3b.c`: **0/1 Knapsack** (Dynamic Programming) for Alia's Trekking Expedition.
- `q4b.c`: **Weighted Interval Scheduling** (Dynamic Programming) for Drama Venue Allocation.
- `q5b.c`: **Bellman-Ford Algorithm** (Dynamic Programming) for Shortest Paths.
- `q6b.c`: **Randomized Quick Sort** (Divide and Conquer) for sorting large datasets.

## How to Compile and Run

To compile any file:
```bash
gcc parta/q1a.c -o q1a
./q1a
```
(Replace `parta/q1a.c` and `q1a` with the desired filename)

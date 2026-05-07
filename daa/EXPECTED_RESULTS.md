# DAA - Design & Analysis of Algorithms: Expected Results

## Q1a - Asymptotic Notation: Big O (o)
**Objective:** Prove that `f(n) = 7n + 5` is `o(n)` by finding constants `c=8` and `n0=5`.

**Expected Output:**
- CSV file `q1a.csv` with columns: `n, f(n), c*n`
- For all `n >= 10` (tested range), verify that `f(n) <= c*n` holds
- Example for n=10: `f(10)=75, c*n=80` ✓ (condition holds)
- All rows should satisfy: 75 ≤ 80, 82 ≤ 88, 89 ≤ 96, etc.

**Sample Output:**
```
n,f(n),c*n
10,75,80
11,82,88
12,89,96
...
30,215,240
```

---

## Q1b - Stable Marriage Problem
**Objective:** Implement the Gale-Shapley algorithm to find a stable matching between men and women.

**Expected Output:**
- Stable marriage pairs where no man-woman pair prefers each other to their current partners
- Console output showing each engagement and final matching
- For N=3: Should output 3 stable pairings
- No blocking pairs should exist

**Sample Output:**
```
A is engaged with V
B is engaged with W
C is engaged with X

Final Stable Matching:
A <-> V
B <-> W
C <-> X
```

---

## Q2a - Asymptotic Notation: Omega (Ω)
**Objective:** Prove that `f(n) = 3n² + 4n + 3` is `Ω(n)` by finding `c=1` and `n0=1`.

**Expected Output:**
- CSV file `q2a.csv` with columns: `n, f(n), c*n`
- For all `n >= 10` (tested range), verify that `f(n) >= c*n` holds
- Example for n=10: `f(10)=343, c*n=10` ✓ (condition holds)
- All rows should satisfy the condition

**Sample Output:**
```
n,f(n),c*n
10,343,10
11,410,11
12,483,12
...
30,2763,30
```

---

## Q2b
**Status:** Implementation needed

---

## Q3a - Asymptotic Notation: Theta (Θ)
**Objective:** Prove that `f(n) = 7n² + 7n + 5` is `Θ(n²)` by finding `c1=7`, `c2=19`, and `n0=1`.

**Expected Output:**
- CSV file `q3a.csv` with columns: `n, c1*n², f(n), c2*n²`
- For all `n >= 10` (tested range), verify that `c1*n² <= f(n) <= c2*n²` holds
- Example for n=10: `700 ≤ 775 ≤ 1900` ✓ (holds)
- All rows should satisfy the sandwich condition

**Sample Output:**
```
n,c1*n^2,f(n),c2*n^2
10,700,775,1900
11,847,943,2299
12,1008,1121,2736
...
30,6300,6665,17100
```

---

## Q3b
**Status:** Implementation needed

---

## Q4a - Asymptotic Notation: Big O (o)
**Objective:** Prove that `f(n) = 4n + 3` is `o(n)` by finding `c=5` and `n0=3`.

**Expected Output:**
- CSV file `q4a.csv` with columns: `n, f(n), c*n`
- For all `n >= 10` (tested range), verify that `f(n) <= c*n` holds
- Example for n=10: `f(10)=43, c*n=50` ✓ (condition holds)
- All rows should satisfy the condition

**Sample Output:**
```
n,f(n),c*n
10,43,50
11,47,55
12,51,60
...
30,123,150
```

---

## Q4b
**Status:** Implementation needed

---

## Q5a - Asymptotic Notation: Omega (Ω)
**Objective:** Prove that `f(n) = 5n + 5` is `Ω(n)` by finding `c=5` and `n0=1`.

**Expected Output:**
- CSV file `q5a.csv` with columns: `n, f(n), c*n`
- For all `n >= 10` (tested range), verify that `f(n) >= c*n` holds
- Example for n=10: `f(10)=55, c*n=50` ✓ (condition holds)
- All rows should satisfy the condition

**Sample Output:**
```
n,f(n),c*n
10,55,50
11,60,55
12,65,60
...
30,155,150
```

---

## Q5b
**Status:** Implementation needed

---

## Q6a
**Status:** Implementation needed

---

## Q6b
**Status:** Implementation needed

---

## Output Files Structure

```
daa/
  solutions/
    ├─ q1a.c
    ├─ q1b.c
    ├─ q2a.c
    ├─ q2b.c
    ├─ q3a.c
    ├─ q3b.c
    ├─ q4a.c
    ├─ q4b.c
    ├─ q5a.c
    ├─ q5b.c
    ├─ q6a.c
    └─ q6b.c
    
  outputs/
    ├─ q1_outputs/
    │   ├─ q1a
    │   └─ q1a.csv
    ├─ q2_outputs/
    │   └─ q2a
    ├─ q3_outputs/
    │   └─ q3a
    ├─ q4_outputs/
    │   └─ q4a
    └─ q5_outputs/
        └─ q5a
```

---

## Validation Criteria

✓ **CSV Files:** Properly formatted with correct headers  
✓ **Values:** All calculations are mathematically correct  
✓ **Conditions:** All inequalities hold for `n >= n0` in tested range (10-30)  
✓ **Consistency:** Console output matches CSV values  

## Notes

- All programs test mathematical properties for `n` from 10 to 30
- All inequality conditions must pass for `n >= n0` in the tested range
- CSV files should be generated in the outputs folders during execution

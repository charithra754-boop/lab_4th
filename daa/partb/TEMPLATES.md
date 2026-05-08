# Part B Program Templates

## Q1B: Stable Marriage

File: `q1b.c`

### Imports

```c
#include <stdio.h>
#include <stdbool.h>
```

- `stdio.h` is used for `printf`.
- `stdbool.h` is used for `bool`, `true`, and `false`.

### Global Declarations

```c
#define N 3
int prefer[2 * N][N] = {...};
```

- `N` stores the number of men and women.
- `prefer` stores all preference lists.
- The first `N` rows are men's preferences.
- The last `N` rows are women's preferences.

### Function: `notloyal`

```c
bool notloyal(int prefer[2*N][N], int w, int m, int m1)
```

Inputs:

- `prefer`: preference matrix.
- `w`: woman index.
- `m`: new man proposing.
- `m1`: current partner of woman `w`.

Logic:

- Traverse woman `w`'s preference list.
- If current partner `m1` appears before new man `m`, she stays with `m1`.
- If new man `m` appears before current partner `m1`, she switches.

Pivotal point:

- This function decides whether a woman's current match changes or remains stable.
- The name `notloyal` is slightly confusing because returning `true` currently means she keeps her current partner.

### Function: `stableMarriage`

```c
void stableMarriage()
```

Important declarations:

```c
int wPartner[N];
bool mFree[N];
int freeCount = N;
```

- `wPartner[i]` stores the man currently paired with woman `i`.
- `mFree[i]` stores whether man `i` is free.
- `freeCount` stores how many men are still unmatched.

Logic:

- Initialize every woman as unmatched using `wPartner[i] = -1`.
- Mark every man as free using `mFree[i] = true`.
- While free men exist:
  - Pick a free man.
  - Let him propose to women according to his preference list.
  - If the woman is free, match them.
  - If the woman is already matched, compare the current man and new man using `notloyal`.

Output:

```c
char menNames[] = {'A', 'B', 'C'};
char womenNames[] = {'V', 'W', 'X'};
```

- These arrays are used to print readable names instead of numeric indexes.

### Main

```c
int main() {
    stableMarriage();
    return 0;
}
```

Design strategy: Greedy matching

Time complexity: `O(N^2)`

---

## Q2B: BFS Reachability

File: `q2b.c`

### Import

```c
#include <stdio.h>
```

- `stdio.h` is used for printing output.

### Declarations

```c
#define N 5
int graph[N][N] = {...};
```

- `N` is the number of nodes.
- `graph` is an adjacency matrix.
- `graph[u][v] == 1` means there is an edge from node `u` to node `v`.

### Main Logic

Important declarations:

```c
int visited[N];
int queue[N], f = 0, r = 0;
```

- `visited[i] = -1` means node `i` is unvisited.
- `visited[i] = 1` means node `i` is visited and reachable.
- `queue` is used for BFS traversal.
- `f` is the queue front.
- `r` is the queue rear.

Logic:

- Start from node `1`, which is index `0`.
- Mark node `0` as visited.
- Insert node `0` into the queue.
- While the queue is not empty:
  - Remove one node from the queue.
  - Check all its neighboring nodes.
  - If an edge exists and the neighbor is unvisited:
    - Mark the neighbor as visited.
    - Add the neighbor to the queue.

Pivotal points:

- BFS uses a queue.
- BFS explores nodes level by level.
- `visited` prevents visiting the same node repeatedly.
- The program uses 0-based indexing internally but prints node numbers using 1-based indexing.

Output:

- Prints all nodes reachable from node `1`.

---

## Q3B: Merge Sort

File: `q3b.c`

### Imports

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
```

- `stdio.h` is used for printing.
- `stdlib.h` is used for `malloc`, `rand`, `srand`, and `free`.
- `time.h` is used for random seed and timing execution.

### Function: `merge`

```c
void merge(int arr[], int l, int m, int r)
```

Inputs:

- `arr[]`: array to be sorted.
- `l`: left index.
- `m`: middle index.
- `r`: right index.

Important declarations:

```c
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
```

- `n1` is the size of the left subarray.
- `n2` is the size of the right subarray.
- `L` temporarily stores the left half.
- `R` temporarily stores the right half.

Logic:

- Copy the left half into `L`.
- Copy the right half into `R`.
- Compare elements from `L` and `R`.
- Put the smaller element back into the original array.
- Copy any remaining elements after one side is exhausted.

Pivotal point:

- `merge()` assumes both halves are already sorted.
- This function performs the actual combining in sorted order.

### Function: `mergeSort`

```c
void mergeSort(int arr[], int l, int r)
```

Inputs:

- `arr[]`: array to sort.
- `l`: left index.
- `r`: right index.

Logic:

- If `l < r`, divide the array.
- Sort the left half recursively.
- Sort the right half recursively.
- Merge both sorted halves.

Pivotal line:

```c
int m = l + (r - l) / 2;
```

- This finds the middle index safely.
- The condition `l < r` is the base condition that stops recursion.

### Main Logic

Important declarations:

```c
int n = 10000;
int *arr = (int*)malloc(n * sizeof(int));
```

Logic:

- Create an array of size `10000`.
- Fill the array with random numbers.
- Start the timer.
- Call `mergeSort(arr, 0, n - 1)`.
- Stop the timer.
- Print the first 10 sorted elements.
- Print execution time.
- Free the dynamically allocated memory using `free(arr)`.

Design strategy: Divide and Conquer

Time complexity: `O(n log n)`

---

## Q4B: Count Inversions

File: `q4b.c`

### Imports

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
```

- `stdio.h` is used for printing.
- `stdlib.h` is included for utility functions.
- `time.h` is used for measuring execution time.

### Function: `mergeandcount`

```c
int mergeandcount(int arr[], int l, int m, int r)
```

Inputs:

- `arr[]`: array.
- `l`: left index.
- `m`: middle index.
- `r`: right index.

Important declarations:

```c
int inv_count = 0;
int L[n1], R[n2];
```

- `inv_count` stores the number of inversions found during merge.
- `L` stores the left half.
- `R` stores the right half.

Logic:

- Split the current section into left and right temporary arrays.
- Merge them in sorted order.
- If `L[i] <= R[j]`, copy `L[i]`.
- If `L[i] > R[j]`, copy `R[j]` and count inversions.

Pivotal line:

```c
inv_count += (n1 - i);
```

Why it matters:

- Since the left half is sorted, if `L[i] > R[j]`, then every remaining element from `L[i]` to `L[n1 - 1]` is also greater than `R[j]`.
- This counts many inversions at once.

### Function: `mergeSort`

```c
int mergeSort(int arr[], int l, int r)
```

Inputs:

- `arr[]`: array.
- `l`: left index.
- `r`: right index.

Logic:

- Count inversions in the left half.
- Count inversions in the right half.
- Count split inversions while merging.
- Return the total inversion count.

Important declaration:

```c
int inv_count = 0;
```

### Main Logic

Important declarations:

```c
int n = 10;
int arr[] = {3, 1, 8, 2, 7, 5, 6, 4, 10, 9};
```

Logic:

- Print the original array.
- Start the timer.
- Call `mergeSort(arr, 0, n - 1)`.
- Stop the timer.
- Print the sorted array.
- Print total inversions.
- Print time taken.

Pivotal point:

- An inversion means `i < j` but `arr[i] > arr[j]`.
- This program sorts the array and counts inversions at the same time.

---

## Q5B: Bipartite Check Using BFS

File: `q5b.c`

### Import

```c
#include <stdio.h>
```

- `stdio.h` is used for printing.

### Declarations

```c
#define N 10
int graph[N][N] = {0};
int edges[][2] = {...};
```

- `N` is the number of nodes.
- `graph` is an adjacency matrix.
- `edges` stores the undirected graph edges using 1-based node numbers.
- The edges are converted to 0-based indexing before inserting into `graph`.

### Color Declarations

```c
int color[N];
```

Meaning:

- `-1`: unvisited.
- `0`: first color.
- `1`: second color.

### Queue Declarations

```c
int queue[N], f = 0, r = 0;
```

- `queue` stores nodes for BFS.
- `f` is the queue front.
- `r` is the queue rear.

### Logic

- Initialize all colors to `-1`.
- Start from node `1`, index `0`.
- Color the starting node as `0`.
- Add it to the queue.
- While the queue is not empty:
  - Remove a node `u`.
  - Check all adjacent nodes `v`.
  - If `v` is unvisited, give it the opposite color.
  - If `v` already has the same color as `u`, the graph is not bipartite.

Pivotal line:

```c
color[v] = 1 - color[u];
```

Why it matters:

- This assigns the opposite color to neighboring nodes.

Conflict check:

```c
else if(color[v] == color[u])
```

- If two connected nodes have the same color, the graph is non-bipartite.

Design strategy: BFS layer-based coloring

---

## Q6B: Dijkstra's Algorithm

File: `q6b.c`

### Imports

```c
#include <stdio.h>
#include <limits.h>
```

- `stdio.h` is used for printing.
- `limits.h` provides `INT_MAX`.

### Declarations

```c
#define V 5
#define INF INT_MAX
```

- `V` is the number of vertices.
- `INF` represents infinity.

### Function: `printPath`

```c
void printPath(int parent[], int j)
```

Inputs:

- `parent[]`: stores the previous vertex in the shortest path.
- `j`: current destination vertex.

Logic:

- If `parent[j] == -1`, stop recursion.
- Recursively print the path up to the parent of `j`.
- Print vertex `j`.

Pivotal point:

- `parent[]` allows the program to print the actual shortest path, not just the shortest distance.

### Function: `dijkstra`

```c
void dijkstra(int graph[V][V], int src)
```

Inputs:

- `graph`: weighted adjacency matrix.
- `src`: source vertex.

Important declarations:

```c
int dist[V], visited[V] = {0}, parent[V];
```

- `dist[i]` stores the shortest known distance from source to vertex `i`.
- `visited[i]` tells whether the shortest distance for vertex `i` is finalized.
- `parent[i]` stores the previous vertex in the shortest path.

Logic:

- Initialize all distances as `INF`.
- Initialize all parents as `-1`.
- Set source distance to `0`.
- Repeat `V - 1` times:
  - Pick the unvisited vertex with the minimum distance.
  - Mark it as visited.
  - Relax its neighboring edges.

Pivotal condition:

```c
dist[u] + graph[u][v] < dist[v]
```

Why it matters:

- This checks whether going through vertex `u` gives a shorter path to vertex `v`.

### Main Logic

```c
int graph[V][V] = {...};
dijkstra(graph, 0);
```

- The graph is stored as a weighted adjacency matrix.
- `0` means no direct edge.
- The source is vertex `1`, represented by index `0`.

Design strategy: Greedy Method

Time complexity: `O(V^2)`

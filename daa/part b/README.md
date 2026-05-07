# DAA Part B — Algorithm Summary

This README summarizes the algorithms implemented in `/daa/part b/q1b.c` through `/daa/part b/q6b.c`.
It is written to help you remember the core idea, the code structure, and how to write each solution faster.

---

## Q1: Stable Marriage Problem (Gale-Shapley)

### Core idea
- Men propose to women in order of their preference list.
- Each woman accepts the best proposal she has seen so far and may reject a previous partner.
- Continue until all men are matched.

### Key code pattern
- `wPartner[N]` stores the current partner index for each woman.
- `mFree[N]` tracks free men.
- Outer loop continues while any man is free.
- Inner loop tries the next woman in the man`s preference list.
- If a woman is free, she accepts.
- If she is already engaged, compare the current and new men.

### Pseudocode
```
initialize all women as free
initialize all men as free
while there is a free man m:
    w = next woman on m's list
    if w is free:
        match m with w
    else:
        current = w's current partner
        if w prefers m over current:
            make current free
            match m with w
```

### Tip for memorizing
Remember the phrases: _propose_, _compare_, _keep best_, _repeat_.

---

## Q2: Breadth-First Search (BFS)

### Core idea
- Explore graph level by level using a queue.
- Mark nodes as visited when they are discovered.
- Enqueue all neighbors of the current node.

### Key code pattern
- `visited[N]` array.
- `queue[N]`, `front`, and `rear` indices.
- Visit a node, then enqueue each unvisited neighbor.
- Print queue state or visited order to trace each step.

### Pseudocode
```
mark source as visited
enqueue source
while queue not empty:
    node = dequeue
    for each neighbor:
        if neighbor not visited:
            mark visited
            enqueue neighbor
```

### Tip for memorizing
Visualize walking outward from the source in rings. Every time you pop a node, add its unvisited neighbors to the back of the queue.

---

## Q3: Merge Sort

### Core idea
- Divide the array into two halves.
- Recursively sort each half.
- Merge the sorted halves.

### Key code pattern
- `mergeSort(arr, l, r)` recursive divide.
- `merge(arr, l, m, r)` combines two sorted arrays.
- Use temporary arrays for left and right halves.

### Pseudocode
```
if left < right:
    mid = (left + right) / 2
    mergeSort(left half)
    mergeSort(right half)
    merge two halves
```

### Tip for memorizing
Learn the structure as “divide, sort each, merge”. If you remember just three steps, the code follows naturally.

---

## Q4: Count Inversions with Merge Sort

### Core idea
- Use merge sort and count how many times a right-side element is placed before a left-side element.
- Each such placement indicates an inversion.

### Key code pattern
- Same divide-and-conquer structure as merge sort.
- During merge, when `arr[j] < arr[i]`, add `(mid - i)` to inversions.
- Use a temporary array to merge sorted halves.

### Pseudocode
```
if left < right:
    mid = (left + right) / 2
    inv += count(left half)
    inv += count(right half)
    inv += mergeAndCount(left, right)
return inv
```

### Tip for memorizing
Pair this with merge sort: the only extra step is counting the skipped left elements when a right element is chosen.

---

## Q5: Bipartite Graph Check using BFS Coloring

### Core idea
- Use BFS to color nodes alternately (0 and 1).
- If two adjacent nodes ever get the same color, the graph is not bipartite.

### Key code pattern
- `color[N]` initialized to -1 for unvisited.
- Start from a node, assign color 0.
- For each neighbor, if unvisited assign opposite color.
- If visited and color equals current node, conflict.

### Pseudocode
```
color[start] = 0
enqueue start
while queue not empty:
    u = dequeue
    for each neighbor v:
        if color[v] == -1:
            color[v] = 1 - color[u]
            enqueue v
        else if color[v] == color[u]:
            not bipartite
```

### Tip for memorizing
Think “red-blue layers”. BFS ensures the graph is checked layer by layer.

---

## Q6: Dijkstra's Shortest Path

### Core idea
- Find the smallest distance unvisited vertex.
- Relax its outgoing edges by updating distances.
- Repeat until all vertices are visited.

### Key code pattern
- `dist[V]` stores current shortest distances.
- `visited[V]` marks nodes whose shortest path is finalized.
- `parent[V]` stores the path.
- Each iteration chooses the minimum unvisited vertex.
- For each neighbor, if new distance is smaller, update distance and parent.

### Pseudocode
```
for each vertex:
    dist[v] = INF
    visited[v] = false
    parent[v] = -1
s = source
dist[s] = 0
for count = 1 to V-1:
    u = min distance unvisited vertex
    visited[u] = true
    for each neighbor v of u:
        if not visited[v] and dist[u] + w(u,v) < dist[v]:
            dist[v] = dist[u] + w(u,v)
            parent[v] = u
```

### Tip for memorizing
Focus on the greedy step: always finalize the nearest unvisited node, then relax its neighbors.

---

## Memory and writing tips

1. Start with the problem goal.
   - Q1: stable pairs.
   - Q2: visit all reachable nodes.
   - Q3: sort by divide and conquer.
   - Q4: count inversions while sorting.
   - Q5: two-color the graph.
   - Q6: shortest paths by greedy choice.

2. Remember the state arrays.
   - `visited`, `queue`, `color`, `dist`, `parent`, `mFree`, `wPartner`.

3. Use a short story for each algorithm.
   - BFS = wave from source.
   - Merge sort = split and rejoin sorted halves.
   - Stable marriage = proposals and preference comparisons.
   - Dijkstra = always pick the nearest safe node.

4. Write the basic pseudocode first.
   - The code becomes easier after the structure is clear.
   - Use comments in the code to map lines to the pseudocode steps.

5. Practice by tracing one small example on paper.
   - For BFS and bipartite check, draw the queue evolution.
   - For merge sort and inversion count, trace one merge step.
   - For stable marriage and Dijkstra, trace partner/distance updates.

---

## Quick reference

- `q1b.c`: Stable Marriage — `O(N^2)`
- `q2b.c`: BFS Reachability — `O(V + E)`
- `q3b.c`: Merge Sort — `O(n log n)`
- `q4b.c`: Inversion Count via Merge Sort — `O(n log n)`
- `q5b.c`: Bipartite Check via BFS — `O(V + E)`
- `q6b.c`: Dijkstra Shortest Path — `O(V^2)`

Keep this README handy when practicing, and use the pseudocode patterns to build the C code from memory.

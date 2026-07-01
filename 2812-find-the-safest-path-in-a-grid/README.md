# Find the Safest Path in a Grid

## Problem Statement

You are given an `n × n` grid where:

- `grid[i][j] = 1` represents a cell containing a thief.
- `grid[i][j] = 0` represents an empty cell.

The **safeness factor** of a path is the minimum Manhattan distance from any cell on the path to any thief in the grid.

Return the **maximum safeness factor** among all paths from the top-left cell:

```cpp
(0, 0)
```

to the bottom-right cell:

```cpp
(n - 1, n - 1)
```

You may move in four directions:

- Up
- Down
- Left
- Right

---

# Solution: Multi-Source BFS + Binary Search

## Solution Overview

This solution consists of two phases:

1. **Multi-Source BFS**
   - Compute the minimum distance from every cell to the nearest thief.

2. **Binary Search + BFS**
   - Binary search the maximum possible safeness factor.
   - For each candidate safeness value, check whether a valid path exists using BFS.

This efficiently finds the largest safeness factor without testing every possible path individually.

---

## Phase 1: Multi-Source BFS

### Idea

Instead of running BFS from every cell, start BFS simultaneously from **all thief cells**.

This computes:

```cpp
dist[i][j]
```

=

```cpp
minimum distance from cell (i, j)
to the nearest thief.
```

---

### Algorithm

#### Step 1: Initialize

Create:

```cpp
dist[n][n]
```

Initialize every value to:

```cpp
-1
```

Create a queue.

---

#### Step 2: Insert All Thieves

For every cell:

```cpp
grid[i][j] == 1
```

Set:

```cpp
dist[i][j] = 0;
```

Push it into the queue.

---

#### Step 3: BFS Expansion

While the queue is not empty:

1. Remove one cell.
2. Visit its four neighbors.
3. If a neighbor has not been visited:

```cpp
dist[nr][nc] = dist[r][c] + 1;
```

Push it into the queue.

After BFS finishes:

```cpp
dist[i][j]
```

contains the distance to the nearest thief.

---

## Phase 2: Binary Search

The answer lies between:

```cpp
0
```

and

```cpp
2 * n
```

Binary search this value.

For every candidate:

```cpp
safe
```

check whether a path exists whose every cell satisfies:

```cpp
dist >= safe
```

---

## BFS Feasibility Check

The helper function:

```cpp
isPossible(dist, safe)
```

checks whether such a path exists.

---

### Step 1: Check Start and End

If either endpoint has:

```cpp
dist < safe
```

then the path is impossible.

Return:

```cpp
false
```

---

### Step 2: BFS Traversal

Start BFS from:

```cpp
(0,0)
```

Only move into neighbors satisfying:

```cpp
dist[nr][nc] >= safe
```

Maintain a visited matrix.

---

### Step 3: Reach Destination

If:

```cpp
(n-1, n-1)
```

is reached,

return:

```cpp
true
```

Otherwise,

return:

```cpp
false
```

---

## Binary Search

Initialize:

```cpp
low = 0
high = 2 * n
```

While:

```cpp
low <= high
```

Compute:

```cpp
mid
```

If:

```cpp
isPossible(mid)
```

is true:

```cpp
ans = mid;
low = mid + 1;
```

Otherwise:

```cpp
high = mid - 1;
```

Return:

```cpp
ans
```

---

## Complexity Analysis

Let:

```cpp
n = grid.size()
```

### Multi-Source BFS

Every cell is visited once.

```cpp
O(n²)
```

---

### Feasibility Check

Each BFS visits every cell at most once.

```cpp
O(n²)
```

---

### Binary Search

Search space:

```cpp
0 ... 2n
```

Number of iterations:

```cpp
O(log n)
```

---

### Overall Time Complexity

```cpp
O(n² log n)
```

---

### Space Complexity

Distance matrix:

```cpp
O(n²)
```

Visited matrix:

```cpp
O(n²)
```

Queue:

```cpp
O(n²)
```

Overall:

```cpp
O(n²)
```

---

## Notes

- Multi-Source BFS computes the nearest thief distance for every cell in one traversal.
- Binary search is used because the safeness factor is monotonic:
  - If a path exists for safeness `x`, it also exists for every value smaller than `x`.
- BFS checks whether a path satisfying the current safeness threshold exists.
- Avoids repeatedly computing distances for every candidate path.
- More efficient than brute-force path exploration.
- This is a standard optimal approach combining **Multi-Source BFS** and **Binary Search**.
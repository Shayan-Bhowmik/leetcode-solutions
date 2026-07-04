# Find a Safe Walk Through a Grid

## Problem Statement

You are given an `m × n` grid where each cell contains either:

- `0` representing a safe cell.
- `1` representing an unsafe cell.

You are also given an integer:

```cpp
health
```

You start at the top-left cell:

```cpp
(0, 0)
```

and want to reach the bottom-right cell:

```cpp
(m - 1, n - 1)
```

You may move in four directions:

- Up
- Down
- Left
- Right

Entering a safe cell costs:

```cpp
0
```

Entering an unsafe cell costs:

```cpp
1
```

Return `true` if there exists a path whose total health cost is **strictly less than** `health`; otherwise, return `false`.

---

# Solution: 0-1 BFS

## Solution Overview

This solution models the grid as a graph where each move has a weight of either:

- `0` (safe cell)
- `1` (unsafe cell)

Since edge weights are only `0` or `1`, the shortest path can be computed efficiently using **0-1 BFS**.

Key ideas:
- Maintain the minimum health cost required to reach every cell.
- Use a deque instead of a priority queue.
- Moves with cost `0` are processed immediately.
- Moves with cost `1` are processed after all current zero-cost moves.
- Finally, check whether the minimum cost to reach the destination is less than the available health.

This is more efficient than using Dijkstra's algorithm for graphs with only `0` and `1` edge weights.

---

## Algorithm

### Step 1: Initialize Distance Array

Create:

```cpp
dist[m][n]
```

Initialize every value to:

```cpp
INT_MAX
```

Set the starting cost:

```cpp
dist[0][0] = grid[0][0];
```

This accounts for the cost of entering the starting cell.

---

### Step 2: Initialize Deque

Create a deque:

```cpp
deque<pair<int, int>> dq;
```

Insert the starting cell:

```cpp
dq.push_front({0, 0});
```

---

### Step 3: Perform 0-1 BFS

While the deque is not empty:

Remove the front cell:

```cpp
(r, c)
```

Explore its four neighboring cells.

---

### Step 4: Compute Transition Cost

The cost of moving into a neighbor is:

```cpp
w = grid[nr][nc];
```

Possible values are:

- `0`
- `1`

If a cheaper path is found:

```cpp
dist[r][c] + w < dist[nr][nc]
```

update:

```cpp
dist[nr][nc]
```

---

### Step 5: Update the Deque

If:

```cpp
w == 0
```

insert the neighbor at the front:

```cpp
dq.push_front({nr, nc});
```

Otherwise:

```cpp
dq.push_back({nr, nc});
```

This guarantees that lower-cost paths are processed first.

---

### Step 6: Check Destination

After BFS completes, the minimum health cost required to reach:

```cpp
(m - 1, n - 1)
```

is stored in:

```cpp
dist[m - 1][n - 1]
```

Return:

```cpp
dist[m - 1][n - 1] < health
```

---

## Why 0-1 BFS Works

Unlike a normal BFS, edges do not all have the same weight.

However, every edge weight is either:

```cpp
0
```

or

```cpp
1
```

Using a deque ensures:

- Zero-cost moves are processed immediately.
- One-cost moves are delayed until all current zero-cost paths are explored.

This produces the same shortest-path result as Dijkstra's algorithm but more efficiently.

---

## Complexity Analysis

Let:

```cpp
m = number of rows
```

and

```cpp
n = number of columns
```

### Time Complexity

Each cell is processed at most a constant number of times.

Overall:

```cpp
O(m × n)
```

---

### Space Complexity

Distance array:

```cpp
O(m × n)
```

Deque:

```cpp
O(m × n)
```

Overall:

```cpp
O(m × n)
```

---

## Notes

- Models the grid as a weighted graph with edge weights `0` and `1`.
- Uses **0-1 BFS**, which is optimal for graphs with binary edge weights.
- The deque replaces the priority queue used in Dijkstra's algorithm.
- Zero-cost moves are explored before one-cost moves.
- Computes the minimum health cost needed to reach every cell.
- Returns `true` only if the destination can be reached using **strictly less** than the available health.
- This is the standard optimal solution for the problem.
# Path Existence Queries in a Graph II

## Problem Statement

You are given:

- An integer:
  ```cpp
  n
  ```
- An integer array:
  ```cpp
  nums
  ```
- An integer:
  ```cpp
  maxDiff
  ```
- A list of queries:
  ```cpp
  queries
  ```
  where each query is of the form:

  ```cpp
  [u, v]
  ```

A graph is formed where an edge exists between two indices if the difference between their corresponding values satisfies the problem constraints.

For each query, return:

- The minimum number of jumps required to travel from index:
  ```cpp
  u
  ```
  to:
  ```cpp
  v
  ```
- If no path exists, return:
  ```cpp
  -1
  ```

---

# Solution: Sorting + Connected Components + Binary Lifting

## Solution Overview

This solution combines several techniques to answer multiple shortest-path queries efficiently.

Key ideas:
- Sort the elements while remembering their original indices.
- Identify connected components.
- Compute the farthest index reachable in one jump using the two-pointer technique.
- Build a **Binary Lifting** table over these jumps.
- For every query, repeatedly jump using powers of two to find the minimum number of jumps.

This preprocessing allows each query to be answered in logarithmic time.

---

## Algorithm

### Step 1: Sort the Elements

Create pairs:

```cpp
(value, originalIndex)
```

Sort them by value.

This makes it easy to determine reachability based on value differences.

---

### Step 2: Store Sorted Positions

Create:

```cpp
pos[index]
```

which stores the position of every original index in the sorted array.

This allows queries to be converted into sorted-order positions.

---

### Step 3: Build Connected Components

Traverse the sorted array.

Whenever:

```cpp
a[i].first - a[i - 1].first > maxDiff
```

start a new connected component.

Store the component id:

```cpp
comp[i]
```

Two vertices are connected only if they belong to the same component.

---

### Step 4: Compute Farthest Reachable Position

Use the two-pointer technique.

For every position:

```cpp
l
```

find the farthest position:

```cpp
r
```

such that:

```cpp
a[r].first - a[l].first <= maxDiff
```

Store:

```cpp
nxt[l] = r;
```

This represents the farthest position reachable in one jump.

---

### Step 5: Build Binary Lifting Table

Create:

```cpp
up[k][i]
```

where:

```cpp
up[k][i]
```

stores the position reached after:

```cpp
2^k
```

jumps from position:

```cpp
i
```

Initialize:

```cpp
up[0][i] = nxt[i];
```

Then compute:

```cpp
up[k][i]
=
up[k-1][ up[k-1][i] ]
```

for every level.

---

### Step 6: Process Queries

Convert the original indices into sorted positions:

```cpp
u = pos[q[0]];
v = pos[q[1]];
```

Ensure:

```cpp
u <= v
```

by swapping if necessary.

---

### Step 7: Check Connectivity

If:

```cpp
comp[u] != comp[v]
```

the vertices belong to different connected components.

Return:

```cpp
-1
```

---

### Step 8: Compute Minimum Jumps

If:

```cpp
u == v
```

return:

```cpp
0
```

Otherwise, use Binary Lifting.

Starting from the largest power of two:

```cpp
LOG - 1
```

move whenever:

```cpp
up[k][cur] < v
```

Update:

```cpp
cur = up[k][cur];
```

Increase the jump count:

```cpp
res += (1 << k);
```

After processing all powers, one final jump reaches or passes:

```cpp
v
```

Return:

```cpp
res + 1
```

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

and

```cpp
q = queries.size()
```

### Preprocessing

Sorting:

```cpp
O(n log n)
```

Building connected components:

```cpp
O(n)
```

Two-pointer computation:

```cpp
O(n)
```

Binary lifting table:

```cpp
O(n log n)
```

---

### Query Processing

Each query performs Binary Lifting.

Time:

```cpp
O(log n)
```

---

### Overall Time Complexity

```cpp
O(n log n + q log n)
```

---

### Space Complexity

Sorted array:

```cpp
O(n)
```

Component array:

```cpp
O(n)
```

Position array:

```cpp
O(n)
```

Binary lifting table:

```cpp
O(n log n)
```

Overall:

```cpp
O(n log n)
```

---

## Notes

- Sorting allows efficient processing based on value differences.
- Connected components quickly identify unreachable queries.
- The two-pointer technique computes the maximum one-jump reach for every position.
- Binary Lifting enables fast minimum-jump computation.
- Each query is answered in logarithmic time after preprocessing.
- This is the standard optimal solution for the problem.
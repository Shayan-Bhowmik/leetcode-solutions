# Assign Edge Weights Queries

## Problem Statement

You are given an undirected tree represented by the array `edges` and a list of queries.

For each query:

```cpp
[u, v]
```

consider the unique path between nodes `u` and `v`.

Return the number of valid edge weight assignments for each query according to the problem rules.

Since the answer can be large, return it modulo:

```cpp
10^9 + 7
```

---

# Solution 1: Brute Force (Parent Traversal)

## Solution Overview

This approach computes the distance between two nodes by explicitly tracing both nodes to the root.

Key ideas:
- Root the tree at node `1`.
- Store the parent of every node.
- For each query:
  - Construct the path from both nodes to the root.
  - Find their Lowest Common Ancestor (LCA) by comparing paths.
  - Compute the distance between the nodes.
  - Use the formula:

```cpp
2^(distance-1)
```

to obtain the answer.

---

## Algorithm

### Step 1: Build Parent Array

Run DFS from node `1`.

For every child:

```cpp
per[child] = parent
```

This stores the tree structure.

---

### Step 2: Build Paths to Root

For query:

```cpp
(u, v)
```

Construct:

```cpp
u → root
```

and

```cpp
v → root
```

Store both paths in vectors.

---

### Step 3: Find Lowest Common Ancestor

Reverse both paths.

Compare nodes until they differ.

The last common node is the LCA.

---

### Step 4: Compute Distance

Let:

```cpp
i = first mismatch index
```

Distance becomes:

```cpp
(pathU.size() - i)
+
(pathV.size() - i)
```

---

### Step 5: Compute Number of Ways

Using fast exponentiation:

```cpp
2^(distance-1)
```

Return:

```cpp
power(2, distance-1)
```

modulo:

```cpp
10^9 + 7
```

---

## Complexity Analysis

Let:

```cpp
n = number of nodes
q = number of queries
```

### Time Complexity

DFS:

```cpp
O(n)
```

Each query:

```cpp
O(height)
```

Worst case:

```cpp
O(n)
```

Total:

```cpp
O(n + q·n)
```

---

### Space Complexity

```cpp
O(n)
```

for parent storage and temporary paths.

---

## Notes

- Simple and easy to understand.
- Explicitly constructs root paths.
- Efficient only for small trees.
- Can become slow when many queries exist.

---

# Solution 2: Optimized (Binary Lifting + LCA)

## Solution Overview

This solution uses **Binary Lifting** to answer Lowest Common Ancestor queries efficiently.

Key ideas:
- Precompute ancestors of every node.
- Compute node depths.
- Find LCA in logarithmic time.
- Distance between nodes becomes:

```cpp
depth[u] + depth[v] - 2 × depth[LCA]
```

- Use:

```cpp
2^(distance-1)
```

to obtain the answer.

This significantly improves query performance.

---

## Algorithm

### Step 1: Build Tree

Create adjacency list from the given edges.

---

### Step 2: DFS Preprocessing

Run DFS from root node:

```cpp
1
```

Store:

```cpp
depth[node]
```

and

```cpp
up[node][j]
```

where:

```cpp
up[node][j]
```

represents the:

```cpp
2^j-th ancestor
```

of the node.

---

### Step 3: Binary Lifting Table

For every node:

```cpp
up[node][0] = parent
```

For larger powers:

```cpp
up[node][j]
=
up[
    up[node][j-1]
][j-1]
```

---

### Step 4: Compute LCA

For nodes:

```cpp
u, v
```

1. Lift deeper node to the same depth.
2. Move both nodes upward together.
3. First common ancestor becomes the LCA.

---

### Step 5: Compute Distance

Distance between nodes:

```cpp
depth[u]
+
depth[v]
-
2 * depth[LCA]
```

---

### Step 6: Compute Answer

For distance:

```cpp
d
```

return:

```cpp
2^(d-1)
```

using modular exponentiation.

---

## Complexity Analysis

Let:

```cpp
n = number of nodes
q = number of queries
```

### Preprocessing

DFS:

```cpp
O(n)
```

Binary Lifting Table:

```cpp
O(n log n)
```

---

### Per Query

LCA:

```cpp
O(log n)
```

Distance calculation:

```cpp
O(1)
```

Total per query:

```cpp
O(log n)
```

---

### Total Complexity

```cpp
O(n log n + q log n)
```

---

### Space Complexity

Binary Lifting Table:

```cpp
O(n log n)
```

Depth Array:

```cpp
O(n)
```

Overall:

```cpp
O(n log n)
```

---

## Notes

- Uses Binary Lifting for efficient LCA queries.
- Much faster than explicit path comparison.
- Handles large numbers of queries efficiently.
- Distance is computed directly from depths and LCA.
- Modular exponentiation computes:
  ```cpp
  2^(distance-1)
  ```
  efficiently.
- This is the standard optimal solution for tree distance query problems.
# Count the Number of Complete Components

## Problem Statement

You are given an undirected graph with:

- `n` vertices numbered from:
  ```cpp
  0
  ```
  to:
  ```cpp
  n - 1
  ```
- An array:
  ```cpp
  edges
  ```
  where:

  ```cpp
  edges[i] = [ui, vi]
  ```

  represents an undirected edge between vertices `ui` and `vi`.

A **connected component** is called **complete** if every pair of distinct vertices within that component is connected by an edge.

Return the number of complete connected components in the graph.

---

# Solution: Depth-First Search (DFS)

## Solution Overview

This solution explores every connected component using **Depth-First Search (DFS)**.

Key ideas:
- Build an adjacency list for the graph.
- Traverse every connected component using DFS.
- For each component:
  - Count the number of vertices.
  - Compute the sum of the degrees of all vertices.
- A component containing:

```cpp
nodes
```

vertices is complete if its total degree sum equals:

```cpp
nodes × (nodes - 1)
```

This follows from the Handshaking Lemma, since a complete graph with `nodes` vertices contains:

```cpp
nodes × (nodes - 1) / 2
```

edges.

---

## Algorithm

### Step 1: Build the Graph

Create an adjacency list:

```cpp
adj
```

For every edge:

```cpp
[u, v]
```

add:

```cpp
adj[u].push_back(v);
adj[v].push_back(u);
```

since the graph is undirected.

---

### Step 2: Initialize Visited Array

Create:

```cpp
vis[n]
```

to keep track of visited vertices.

Initially, every vertex is unvisited.

---

### Step 3: Perform DFS

For every unvisited vertex:

```cpp
i
```

start a DFS.

During DFS:

- Count the number of vertices:

```cpp
nodes
```

- Accumulate the degree of every vertex:

```cpp
degreeSum
```

The DFS returns:

```cpp
{nodes, degreeSum}
```

for the current connected component.

---

### Step 4: Check Completeness

For a connected component containing:

```cpp
nodes
```

vertices,

the required degree sum for a complete graph is:

```cpp
nodes × (nodes - 1)
```

If:

```cpp
degreeSum == nodes * (nodes - 1)
```

then every possible edge exists.

Increment:

```cpp
ans++;
```

---

### Step 5: Return Result

Return:

```cpp
ans;
```

---

## Why the Formula Works

A complete graph with:

```cpp
k
```

vertices contains:

```cpp
k × (k - 1) / 2
```

edges.

Since every edge contributes to the degree of two vertices:

```cpp
degreeSum
=
2 × edges
```

Therefore:

```cpp
degreeSum
=
2 ×
(k × (k - 1) / 2)
=
k × (k - 1)
```

Thus, checking:

```cpp
degreeSum == nodes * (nodes - 1)
```

is sufficient.

---

## Complexity Analysis

Let:

```cpp
n = number of vertices
```

and

```cpp
m = number of edges
```

### Time Complexity

Building the adjacency list:

```cpp
O(m)
```

DFS traversal:

```cpp
O(n + m)
```

Overall:

```cpp
O(n + m)
```

---

### Space Complexity

Adjacency list:

```cpp
O(n + m)
```

Visited array:

```cpp
O(n)
```

DFS recursion stack:

```cpp
O(n)
```

Overall:

```cpp
O(n + m)
```

---

## Notes

- Uses Depth-First Search to explore each connected component.
- Simultaneously counts:
  - Number of vertices.
  - Sum of vertex degrees.
- Uses the Handshaking Lemma to verify whether a component is complete.
- Every connected component is processed exactly once.
- Efficient linear-time solution.
- This is the standard optimal solution for the problem.
# Maximum Path Score

## Problem Statement

You are given:

- A directed acyclic graph (DAG) represented by:
  ```cpp
  edges
  ```
  where each edge is of the form:
  ```cpp
  [from, to, weight]
  ```
- A boolean array:
  ```cpp
  online
  ```
  indicating whether each node is online.
- A budget:
  ```cpp
  k
  ```

Starting from node:

```cpp
0
```

you must reach node:

```cpp
n - 1
```

subject to the following conditions:

- Every edge used in the path must have a weight at least equal to the chosen path score.
- Offline nodes cannot be visited, except for the destination node.
- The total sum of edge weights along the path must not exceed:
  ```cpp
  k
  ```

Return the **maximum possible path score**. If no valid path exists, return:

```cpp
-1
```

---

# Solution: Binary Search + Topological Dynamic Programming

## Solution Overview

This solution combines **Binary Search** with **Dynamic Programming on a DAG**.

Key ideas:
- Binary search the maximum possible minimum edge weight.
- For every candidate score:
  - Ignore all edges with smaller weights.
  - Ignore offline intermediate nodes.
  - Compute the minimum path cost using a topological traversal.
- If the destination can be reached within budget:
  ```cpp
  k
  ```
  then the candidate score is feasible.

The largest feasible score is the answer.

---

## Algorithm

### Step 1: Build the Graph

Construct an adjacency list:

```cpp
graph[u]
```

storing:

```cpp
(v, weight)
```

Also compute:

```cpp
indegree[v]
```

for every node.

While building the graph, store:

```cpp
high
```

which is the maximum edge weight.

---

### Step 2: Binary Search

The answer lies between:

```cpp
0
```

and

```cpp
high
```

Initialize:

```cpp
low = 0
high = maximum edge weight
ans = -1
```

---

### Step 3: Feasibility Check

For every candidate:

```cpp
limit
```

determine whether a valid path exists.

---

## Topological Dynamic Programming

Since the graph is a DAG, process vertices in topological order.

---

### Step 1: Initialize Distance

Create:

```cpp
dist[n]
```

Initialize:

```cpp
LLONG_MAX
```

Set:

```cpp
dist[0] = 0;
```

This represents the minimum path cost from the source.

---

### Step 2: Topological Traversal

Copy the indegree array.

Insert every node with:

```cpp
indegree == 0
```

into the queue.

Process nodes in topological order.

---

### Step 3: Relax Valid Edges

For every edge:

```cpp
(u → v)
```

skip the edge if:

```cpp
weight < limit
```

because it cannot satisfy the required minimum score.

Also skip the node if:

```cpp
v != n - 1
```

and

```cpp
online[v] == false
```

since intermediate offline nodes cannot be visited.

Otherwise update:

```cpp
dist[v]
=
min(
    dist[v],
    dist[u] + weight
)
```

---

### Step 4: Continue Topological Order

Decrease:

```cpp
indegree[v]
```

When it becomes zero:

```cpp
push(v)
```

into the queue.

---

### Step 5: Check Budget

If:

```cpp
dist[n - 1] <= k
```

then the candidate score is feasible.

Return:

```cpp
true
```

Otherwise:

```cpp
false
```

---

## Binary Search Update

If:

```cpp
check(mid)
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

---

### Step 6: Return Answer

Return:

```cpp
ans
```

---

## Complexity Analysis

Let:

```cpp
n = number of nodes
```

and

```cpp
m = number of edges
```

### Time Complexity

Building graph:

```cpp
O(m)
```

Each feasibility check:

```cpp
O(n + m)
```

Binary search performs:

```cpp
O(log W)
```

iterations, where:

```cpp
W = maximum edge weight
```

Overall:

```cpp
O((n + m) log W)
```

---

### Space Complexity

Adjacency list:

```cpp
O(n + m)
```

Distance array:

```cpp
O(n)
```

Indegree array:

```cpp
O(n)
```

Queue:

```cpp
O(n)
```

Overall:

```cpp
O(n + m)
```

---

## Notes

- The graph is a **Directed Acyclic Graph (DAG)**, allowing efficient processing using topological order.
- Binary search is applied because the feasibility of a path is monotonic:
  - If a path exists for a minimum edge weight `x`, it also exists for every smaller value.
- Dynamic programming computes the minimum path cost for each candidate score.
- Offline nodes are ignored unless they are the destination.
- The algorithm finds the maximum feasible minimum edge weight while respecting the total budget.
- This is an efficient solution combining **Binary Search** with **Topological DP**.
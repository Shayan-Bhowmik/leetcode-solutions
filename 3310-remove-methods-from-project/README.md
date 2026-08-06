# Remove Methods From Project

## Problem Statement

You are given:

- An integer:

```cpp
n
```

representing the number of methods.

- An integer:

```cpp
k
```

representing the initially suspicious method.

- A list:

```cpp
invocations
```

where:

```cpp
[u, v]
```

means method `u` invokes method `v`.

A method becomes **suspicious** if it is reachable from method `k`.

You must determine whether all suspicious methods can be removed.

- If any suspicious method is still invoked by a non-suspicious method, then **no methods can be removed**, and you should return all methods.
- Otherwise, remove all suspicious methods and return the remaining methods.

---

# Solution: BFS Reachability + In-Degree Tracking

## Solution Overview

The solution consists of two phases:

1. **Find every suspicious method** reachable from `k` using **Breadth-First Search (BFS)**.
2. **Check whether any suspicious method still has an incoming edge from a non-suspicious method.**

To efficiently perform the second step, the algorithm decreases the indegree of every suspicious node while traversing the suspicious subgraph.

After the traversal:

- If a suspicious node still has a positive indegree, that incoming edge must originate from a non-suspicious node.
- In that case, removing all suspicious methods is impossible.

---

## Algorithm

### Step 1: Build the Graph

Create an adjacency list:

```cpp
edges
```

and compute the indegree of every node:

```cpp
inDegree[v]++;
```

for every invocation:

```cpp
u → v
```

---

### Step 2: Find Suspicious Methods

Perform BFS starting from:

```cpp
k
```

Maintain a bitset:

```cpp
sus
```

where

```cpp
sus[i]
```

indicates whether method `i` is suspicious.

Initially:

```cpp
sus.set(k);
```

During BFS:

- Visit every reachable node.
- Mark it suspicious.
- Decrease the indegree of each outgoing neighbor.

```cpp
inDegree[v]--;
```

This effectively removes edges originating from suspicious methods.

---

### Step 3: Validate Removal

Traverse every method.

If a suspicious method still satisfies:

```cpp
inDegree[i] > 0
```

then it still has an incoming edge from a non-suspicious method.

Therefore:

```cpp
canRemoveAll = false;
```

Otherwise, collect every non-suspicious method:

```cpp
rem.push_back(i);
```

---

### Step 4: Return the Result

If suspicious methods cannot all be removed:

Return:

```cpp
[0, 1, 2, ..., n-1]
```

Otherwise return:

```cpp
rem
```

which contains every remaining method.

---

## Why This Works

Initially:

```text
inDegree[node]
```

counts all incoming edges.

During BFS, every edge leaving a suspicious node is removed by decrementing the indegree of its destination.

After processing:

- Every remaining indegree corresponds only to edges coming from **non-suspicious** nodes.

Therefore,

```cpp
inDegree[i] > 0
```

for a suspicious node precisely means:

> Some non-suspicious method still invokes this suspicious method.

Hence, removing all suspicious methods would violate the dependency constraints.

---

## Complexity Analysis

Let:

```cpp
n = number of methods
```

and

```cpp
m = invocations.size()
```

### Time Complexity

Building the graph:

```cpp
O(m)
```

BFS traversal:

```cpp
O(n + m)
```

Final validation:

```cpp
O(n)
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

Indegree array:

```cpp
O(n)
```

Bitset:

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

- Uses Breadth-First Search (BFS) to identify every suspicious method reachable from the initial method `k`.
- Stores suspicious methods using a `bitset` for efficient membership checks.
- Updates indegrees during BFS to remove edges originating from suspicious methods.
- After traversal, any suspicious node with a positive indegree is still referenced by a non-suspicious method, making removal impossible.
- Returns all methods if removal is invalid; otherwise returns only the non-suspicious methods.
- Runs in linear time and is the standard optimal solution for the problem.
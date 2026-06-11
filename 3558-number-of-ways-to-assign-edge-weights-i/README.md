# Assign Edge Weights

## Problem Statement

You are given an undirected tree represented by the array `edges`, where:

```cpp
edges[i] = [ui, vi]
```

indicates an edge between nodes `ui` and `vi`.

Determine the number of valid ways to assign edge weights according to the problem constraints and return the answer modulo:

```cpp
10^9 + 7
```

---

# Solution: Tree Height + Fast Exponentiation

## Solution Overview

This solution is based on the observation that the answer depends only on the **maximum depth (height)** of the tree when rooted at node `1`.

Key ideas:
- Construct the tree using an adjacency list.
- Use DFS to compute the height of the tree.
- If the maximum depth is `h`, the answer becomes:

```cpp
2^(h-1)
```

- Compute the result efficiently using binary exponentiation.

---

## Algorithm

### Step 1: Build the Tree

Let:

```cpp
n = edges.size() + 1
```

Create an adjacency list:

```cpp
vector<vector<int>> arr(n + 1);
```

For every edge:

```cpp
[u, v]
```

insert:

```cpp
arr[u].push_back(v);
arr[v].push_back(u);
```

This represents the undirected tree.

---

### Step 2: Compute Tree Height Using DFS

Define:

```cpp
dfs(node, parent)
```

which returns the maximum depth reachable from the current node.

For every child:

```cpp
child != parent
```

compute:

```cpp
dfs(child, node) + 1
```

and keep the maximum value.

The DFS returns:

```cpp
maximum depth from current node
```

---

### Step 3: Obtain Maximum Depth

Start DFS from the root:

```cpp
dfs(1, 0)
```

Let:

```cpp
height = dfs(1, 0)
```

---

### Step 4: Compute Answer

The required number of assignments is:

```cpp
2^(height - 1)
```

Since the answer can be very large, compute it modulo:

```cpp
1,000,000,007
```

using binary exponentiation.

---

## Binary Exponentiation

The helper function:

```cpp
pow(base, exp)
```

computes:

```cpp
base^exp mod MOD
```

efficiently.

At each step:

- If the current bit is set:
  ```cpp
  res = res * base % mod
  ```
- Square the base:
  ```cpp
  base = base * base % mod
  ```
- Move to the next bit:
  ```cpp
  exp >>= 1
  ```

This reduces the complexity from:

```cpp
O(exp)
```

to:

```cpp
O(log exp)
```

---

## Complexity Analysis

Let:

```cpp
n = number of nodes
```

### Time Complexity

#### Building Adjacency List

```cpp
O(n)
```

#### DFS Traversal

```cpp
O(n)
```

Each node is visited exactly once.

#### Fast Exponentiation

```cpp
O(log n)
```

Overall:

```cpp
O(n)
```

---

### Space Complexity

Adjacency List:

```cpp
O(n)
```

DFS Recursion Stack:

```cpp
O(n)
```

Worst case for a skewed tree.

Overall:

```cpp
O(n)
```

---

## Notes

- The tree is rooted at node `1`.
- DFS computes the maximum depth of the tree.
- The answer depends only on the tree height.
- Fast exponentiation is used to handle very large powers efficiently.
- All calculations are performed modulo:
  ```cpp
  1,000,000,007
  ```
- This is an efficient linear-time solution for the problem.
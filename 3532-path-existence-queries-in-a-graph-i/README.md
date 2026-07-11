# Path Existence Queries in a Graph I

## Problem Statement

You are given:

- An integer:
  ```cpp
  n
  ```
- A sorted integer array:
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

A graph is formed where an edge exists between two **adjacent** indices if the difference between their corresponding values is at most:

```cpp
maxDiff
```

For each query, determine whether there exists a path between indices:

```cpp
u
```

and

```cpp
v
```

Return a boolean array where each element represents the answer for the corresponding query.

---

# Solution: Connected Components Preprocessing

## Solution Overview

This solution identifies all connected components in the graph before processing the queries.

Key ideas:
- Since the array is sorted, edges only depend on the difference between adjacent elements.
- Traverse the array once.
- Whenever the difference between two consecutive elements exceeds:
  ```cpp
  maxDiff
  ```
  start a new connected component.
- Assign every index a component ID.
- Two indices are connected if and only if they belong to the same component.

This allows every query to be answered in constant time.

---

## Algorithm

### Step 1: Initialize Component IDs

Create:

```cpp
group[n]
```

where:

```cpp
group[i]
```

stores the connected component containing index:

```cpp
i
```

Initialize:

```cpp
id = 0;
```

---

### Step 2: Traverse the Array

For every index:

```cpp
i = 1 ... n - 1
```

compute:

```cpp
nums[i] - nums[i - 1]
```

---

### Step 3: Detect Component Boundaries

If:

```cpp
nums[i] - nums[i - 1] > maxDiff
```

then a path cannot exist across this gap.

Start a new component:

```cpp
id++;
```

Assign:

```cpp
group[i] = id;
```

Otherwise, the current index belongs to the same component as the previous one.

---

### Step 4: Answer Queries

For every query:

```cpp
[u, v]
```

check:

```cpp
group[u] == group[v]
```

If both indices belong to the same component:

```cpp
true
```

Otherwise:

```cpp
false
```

Store the result in the answer array.

---

### Step 5: Return Result

Return:

```cpp
ans;
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

### Time Complexity

Preprocessing connected components:

```cpp
O(n)
```

Answering queries:

```cpp
O(q)
```

Overall:

```cpp
O(n + q)
```

---

### Space Complexity

Component array:

```cpp
O(n)
```

Answer array:

```cpp
O(q)
```

Overall:

```cpp
O(n + q)
```

---

## Notes

- Takes advantage of the fact that `nums` is sorted.
- Connected components are identified in a single traversal.
- Every index is assigned a component ID.
- Each query is answered in constant time by comparing component IDs.
- Avoids performing DFS or BFS for every query.
- This is the standard optimal solution for the problem.
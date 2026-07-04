# Minimum Score of a Path Between Two Cities

## Problem Statement

There is an undirected graph of `n` cities numbered from `1` to `n`.

You are given:

```cpp
roads[i] = [ai, bi, distancei]
```

which represents a bidirectional road between cities `ai` and `bi` with distance `distancei`.

The **score** of a path between two cities is defined as the minimum distance of a road in that path.

Return the minimum possible score of a path between city:

```cpp
1
```

and city:

```cpp
n
```

It is guaranteed that there is at least one path between the two cities.

---

# Solution: Depth-First Search (DFS)

## Solution Overview

This solution uses **Depth-First Search (DFS)** to explore every city that is connected to city `1`.

Key ideas:
- Build an adjacency list for the graph.
- Perform DFS starting from city `1`.
- While traversing the connected component, continuously track the minimum road distance encountered.
- Since every city in the connected component can be part of some valid path between city `1` and city `n`, the smallest edge in this component is the answer.

This avoids examining individual paths explicitly.

---

## Algorithm

### Step 1: Build the Graph

Create an adjacency list:

```cpp
adj[u]
```

where each entry stores:

```cpp
(v, distance)
```

For every road:

```cpp
[u, v, w]
```

add:

```cpp
adj[u].push_back({v, w});
adj[v].push_back({u, w});
```

since the graph is undirected.

---

### Step 2: Initialize Variables

Create:

```cpp
ans = INT_MAX;
```

This stores the minimum road distance encountered during DFS.

Create a visited array:

```cpp
vis[n + 1];
```

to avoid revisiting cities.

---

### Step 3: Perform DFS

Start DFS from:

```cpp
city 1
```

Mark the current city as visited:

```cpp
vis[node] = 1;
```

---

### Step 4: Explore Neighboring Roads

For every adjacent road:

```cpp
(node → neighbor)
```

update the answer:

```cpp
ans = min(ans, roadDistance);
```

If the neighboring city has not been visited:

```cpp
dfs(neighbor);
```

Continue until the entire connected component has been explored.

---

### Step 5: Return Result

After DFS completes, return:

```cpp
ans;
```

---

## Why This Works

Any path from city:

```cpp
1
```

to city:

```cpp
n
```

must lie entirely within the connected component containing city `1`.

Since you are allowed to revisit cities and edges while forming a valid path, every road in this connected component can potentially be included in some path.

Therefore, the minimum road distance in the connected component is the minimum possible path score.

---

## Complexity Analysis

Let:

```cpp
n = number of cities
```

and

```cpp
m = number of roads
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

- Uses Depth-First Search to explore the connected component containing city `1`.
- Continuously tracks the smallest edge weight encountered during traversal.
- Does not explicitly search for individual paths.
- Relies on the property that every edge in the connected component can contribute to some valid path.
- Efficient linear-time solution.
- This is the standard optimal solution for the problem.
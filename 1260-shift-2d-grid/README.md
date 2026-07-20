# Shift 2D Grid

## Problem Statement

You are given an `m x n` 2D grid:

```cpp
grid
```

and an integer:

```cpp
k
```

In one shift operation:

- The element at position `(i, j)` moves to `(i, j + 1)`.
- The element at the end of a row moves to the beginning of the next row.
- The element at the bottom-right corner moves to the top-left corner.

Return the grid after performing exactly:

```cpp
k
```

shift operations.

---

# Solution: Index Mapping

## Solution Overview

Instead of performing the shift operation one step at a time, this solution treats the 2D grid as a **flattened 1D array**.

Key ideas:
- Convert every cell into its corresponding 1D index.
- Compute its new position after shifting by `k`.
- Convert the new index back into 2D coordinates.
- Place the element directly into its final position.

This avoids repeated shifting and completes the task in a single traversal.

---

## Algorithm

### Step 1: Determine Grid Dimensions

Compute:

```cpp
m = grid.size();
n = grid[0].size();
```

The total number of elements is:

```cpp
total = m * n;
```

---

### Step 2: Reduce the Number of Shifts

Since shifting by `total` positions returns the grid to its original state, reduce:

```cpp
k %= total;
```

This avoids unnecessary work.

---

### Step 3: Create the Result Grid

Initialize an empty grid of the same dimensions:

```cpp
vector<vector<int>> ans(m, vector<int>(n));
```

---

### Step 4: Map Each Element

For every cell:

```cpp
(i, j)
```

compute its flattened index:

```cpp
idx = i * n + j;
```

Its new position after shifting is:

```cpp
newIdx = (idx + k) % total;
```

Convert the new index back into row and column:

```cpp
row = newIdx / n;
col = newIdx % n;
```

Place the element:

```cpp
ans[row][col] = grid[i][j];
```

---

### Step 5: Return the Result

Return:

```cpp
ans;
```

---

## Why Index Mapping Works

A 2D grid can be viewed as a continuous 1D sequence.

For example:

```text
1 2 3
4 5 6
```

corresponds to:

```text
[1, 2, 3, 4, 5, 6]
```

Shifting the flattened array by `k` positions produces the same result as repeatedly applying the grid shift operation.

The formulas:

```cpp
idx = row * n + col
```

and

```cpp
row = idx / n
col = idx % n
```

allow seamless conversion between 2D and 1D representations.

---

## Complexity Analysis

Let:

```cpp
m = number of rows
n = number of columns
```

### Time Complexity

Each element is processed exactly once.

```cpp
O(m × n)
```

---

### Space Complexity

The result grid stores all shifted elements.

```cpp
O(m × n)
```

---

## Notes

- Treats the 2D grid as a flattened 1D array.
- Uses modular arithmetic to compute each element's final position directly.
- Avoids performing `k` individual shift operations.
- Converts between 2D and 1D indices using simple arithmetic.
- Processes every element exactly once, resulting in `O(m × n)` time complexity.
- This is the standard optimal solution for the problem.
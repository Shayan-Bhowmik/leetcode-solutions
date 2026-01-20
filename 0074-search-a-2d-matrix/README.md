# Search a 2D Matrix

## Problem Statement
You are given an `m x n` integer matrix with the following properties:

- Each row is sorted in **ascending order**
- The first integer of each row is **greater than the last integer of the previous row**

Given an integer `target`, return `true` if `target` exists in the matrix, otherwise return `false`.

---

## Approach 1: Brute Force

### Solution Overview
The brute-force approach simply **checks every element** in the matrix.

This method does not use the sorted properties of the matrix, but it is straightforward and easy to understand.

---

### Algorithm
1. Determine the number of rows `m` and columns `n`.
2. Use two nested loops to iterate through each element:
   - Compare the current element with `target`.
3. If a match is found, return `true`.
4. If the entire matrix is traversed without a match, return `false`.

---

### Complexity Analysis
- **Time Complexity:** `O(m × n)`
- **Space Complexity:** `O(1)`

---

### Limitations
- This approach ignores the sorted structure of the matrix.
- It is inefficient for large matrices and not optimal.

---

## Approach 2: Optimized Binary Search

### Solution Overview
The optimized approach uses **binary search twice**:

1. Binary search on rows to identify the **potential row** that may contain the target.
2. Binary search within that row to check if the target exists.

This works because the matrix behaves like a **flattened sorted array**.

---

### Algorithm
1. Perform binary search on the rows:
   - Check if `target` lies between the first and last elements of the middle row.
2. If the correct row is found:
   - Perform binary search on that row.
3. If the target is found at any stage, return `true`.
4. If the search space is exhausted, return `false`.

---

### Complexity Analysis
- **Time Complexity:** `O(log m + log n)`
- **Space Complexity:** `O(1)`

---

## Notes
- The helper function `searchInRow()` performs binary search within a single row.
- `start + (end - start) / 2` prevents integer overflow.
- This solution fully leverages the sorted structure of the matrix.
- The optimized approach is the expected solution in interviews.
- Both solutions are correct, but the optimized version is significantly faster.
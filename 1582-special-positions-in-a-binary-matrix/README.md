# Special Positions in a Binary Matrix

## Problem Statement
Given an `m x n` binary matrix `mat`, return the number of **special positions** in the matrix.

A position `(i, j)` is called **special** if:
- `mat[i][j] == 1`
- All other elements in row `i` are `0`
- All other elements in column `j` are `0`

---

# Solution: Row and Column Counting

## Solution Overview
This solution counts the number of `1`s in each row and column first, then checks which positions satisfy the special condition.

Key ideas:
- A special position must have exactly **one `1` in its row** and **one `1` in its column**.
- First count the number of `1`s in each row and column.
- Then check each cell to see if it meets the special position condition.

This avoids repeatedly scanning rows and columns for each cell.

---

## Algorithm
1. Let `rows = mat.size()` and `cols = mat[0].size()`.
2. Create two arrays:
   - `rowCount` of size `rows`
   - `colsCount` of size `cols`
3. Traverse the matrix:
   - If `mat[i][j] == 1`, increment:
     - `rowCount[i]`
     - `colsCount[j]`
4. Initialize `count = 0`.
5. Traverse the matrix again:
   - If `mat[i][j] == 1` **and**
     - `rowCount[i] == 1`
     - `colsCount[j] == 1`
   - Increment `count`.
6. Return `count`.

---

## Complexity Analysis
- **Time Complexity:** `O(m × n)`  
  The matrix is traversed twice.
- **Space Complexity:** `O(m + n)`  
  For storing row and column counts.

---

## Notes
- Precomputing row and column counts avoids repeated scanning.
- Ensures that a `1` is the only one in both its row and column.
- Works efficiently even for large matrices.
- This approach separates counting and validation for clarity.
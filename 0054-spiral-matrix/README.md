# Spiral Matrix

## Problem Statement
Given an `m x n` matrix, return all elements of the matrix in **spiral order**.

Spiral order means traversing the matrix in this sequence:
- Left → Right (top row)
- Top → Bottom (right column)
- Right → Left (bottom row)
- Bottom → Top (left column)
- Repeat for inner layers until all elements are visited.

---

## Approach: Boundary Traversal

### Solution Overview
We maintain four boundaries to represent the current layer of the matrix:

- `sRow` → Starting row  
- `eRow` → Ending row  
- `sCol` → Starting column  
- `eCol` → Ending column  

We traverse the matrix layer by layer and shrink these boundaries inward after completing each outer loop.

This ensures every element is visited exactly once.

---

## Algorithm
1. Get the dimensions of the matrix.
2. Initialize four boundary pointers.
3. Traverse:
   - Left to Right across `sRow`
   - Top to Bottom across `eCol`
   - Right to Left across `eRow` (if `sRow != eRow`)
   - Bottom to Top across `sCol` (if `sCol != eCol`)
4. Move boundaries inward.
5. Repeat until boundaries overlap.

---

## Complexity Analysis
- **Time Complexity:** `O(m × n)`  
  Every element is visited exactly once.
- **Space Complexity:** `O(1)`  
  (excluding the output vector)

---

## Notes
- Boundary checks prevent duplicate traversal in single row or single column cases.
- No extra visited matrix is required.
- This is the optimal and interview-expected solution.
# Container With Most Water

## Problem Statement
You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `iᵗʰ` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container such that the container contains the most water.

Return the maximum amount of water a container can store.

---

## Solution Overview
This problem is approached using two different methods:

1. **Brute Force Approach**  
   A straightforward solution that checks all possible pairs of lines.  
   This approach is intuitive but results in **Time Limit Exceeded (TLE)** on large inputs.

2. **Two Pointer Optimized Approach**  
   An efficient solution that uses two pointers to reduce the time complexity and passes all constraints.

Both implementations are included to demonstrate the progression from a naive solution to an optimized one.

---

## Approach 1: Brute Force (TLE)

### Algorithm
1. Use two nested loops to consider every possible pair of indices `(i, j)`.
2. For each pair:
   - Width = `j - i`
   - Height = `min(height[i], height[j])`
3. Compute the area and keep track of the maximum value.
4. Return the maximum area found.

### Complexity Analysis
- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

### Result
- ❌ **Time Limit Exceeded** for large inputs.

---

## Approach 2: Two Pointer (Optimized)

### Algorithm
1. Initialize two pointers:
   - `left` at the beginning of the array
   - `right` at the end of the array
2. Compute the area formed by the lines at these pointers.
3. Move the pointer pointing to the smaller height inward, since the height limits the container capacity.
4. Repeat until both pointers meet.
5. Track and return the maximum area obtained.

### Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

### Result
- ✅ **Accepted**

---

## Notes
- The brute-force solution helps in understanding the problem but is not scalable.
- The two-pointer technique optimizes the search space by eliminating unnecessary comparisons.
- Including both approaches highlights algorithmic improvement and performance trade-offs.
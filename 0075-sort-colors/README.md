# Sort Colors

## Problem Statement
Given an integer array `nums` containing only `0`, `1`, and `2`, sort the array **in-place** so that all `0`s come first, followed by `1`s, and then `2`s.

The solution must not use the built-in sort function.

---

## Solution Overview
This problem can be solved using two approaches:

- A **counting-based approach**, which counts the occurrences of each value and reconstructs the array.
- The **Dutch National Flag algorithm**, which sorts the array in a single pass using three pointers.

Both approaches satisfy the problem constraints.

---

## Algorithm
### Approach 1: Counting Method
1. Traverse the array and count the number of `0`s, `1`s, and `2`s.
2. Rewrite the array:
   - First with all `0`s
   - Then with all `1`s
   - Finally with all `2`s

### Approach 2: Dutch National Flag Algorithm
1. Initialize three pointers: `low`, `mid`, and `high`.
2. Traverse the array while `mid <= high`.
3. Swap elements into their correct regions based on their value.
4. Continue until the array is fully sorted.

---

## Complexity Analysis

### Counting Method
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(1)`

### Dutch National Flag Algorithm
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(1)`

---

## Notes
- The counting method is easier to understand but requires two passes.
- The Dutch National Flag algorithm sorts the array in a single pass.
- The DNF approach is optimal and commonly expected in interviews.
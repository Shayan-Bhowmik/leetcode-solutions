# Maximum Subarray

## Problem Statement
Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

---

## Solution Overview
This problem is solved using two approaches:

1. **Brute Force Approach**  
   Computes the sum of all possible subarrays and tracks the maximum sum.  
   While correct, this approach is inefficient and results in **Time Limit Exceeded (TLE)** for large inputs.

2. **Kadane’s Algorithm (Optimized)**  
   Uses a running sum strategy to efficiently determine the maximum subarray sum in linear time.

Both approaches are included to illustrate the transition from a naive solution to an optimal one.

---

## Approach 1: Brute Force (TLE)

### Algorithm
1. Iterate over all possible starting indices of subarrays.
2. For each starting index, extend the subarray to the right while maintaining a running sum.
3. Update the maximum sum whenever a larger subarray sum is found.
4. Return the maximum sum after checking all subarrays.

### Complexity Analysis
- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

### Result
- ❌ **Time Limit Exceeded** for large inputs.

---

## Approach 2: Kadane’s Algorithm (Optimized)

### Algorithm
1. Initialize two variables:
   - `curr_sum` to store the running sum
   - `max_sum` to store the maximum sum found so far
2. Traverse the array:
   - Add the current element to `curr_sum`.
   - Update `max_sum` if `curr_sum` is greater.
   - If `curr_sum` becomes negative, reset it to `0`.
3. Return `max_sum`.

### Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

### Result
- ✅ **Accepted**

---

## Notes
- The brute-force solution helps in understanding the problem but does not scale well.
- Kadane’s Algorithm works by discarding subarrays that reduce the overall sum.
- This optimized approach satisfies all problem constraints efficiently.
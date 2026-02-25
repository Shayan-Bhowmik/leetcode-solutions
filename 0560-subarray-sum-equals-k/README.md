# Subarray Sum Equals K

## Problem Statement
Given an array of integers `nums` and an integer `k`, return the total number of **continuous subarrays** whose sum equals `k`.

A subarray is a contiguous non-empty sequence of elements within an array.

---

# Solution 1: Brute Force (Nested Loop)

## Solution Overview
This approach checks all possible subarrays and counts how many of them have a sum equal to `k`.

Key ideas:
- Fix a starting index `i`
- Expand the subarray using index `j`
- Maintain a running sum
- Increment count whenever the sum equals `k`

---

## Algorithm
1. Initialize `count = 0`.
2. Iterate `i` from `0` to `n-1`:
   - Initialize `sum = 0`.
3. Iterate `j` from `i` to `n-1`:
   - Add `nums[j]` to `sum`.
   - If `sum == k`, increment `count`.
4. Return `count`.

---

## Complexity Analysis
- **Time Complexity:** `O(n²)`  
  Two nested loops generate all possible subarrays.
- **Space Complexity:** `O(1)`  
  No extra data structures are used.

---

## Notes
- Simple and easy to understand.
- Works correctly for negative numbers.
- Inefficient for large input sizes due to quadratic time complexity.

---

# Solution 2: Optimal (Prefix Sum + Hash Map)

## Solution Overview
This approach uses **prefix sums** and a **hash map** to efficiently count subarrays whose sum equals `k`.

Key ideas:
- Compute prefix sum array
- If `prefixSum[j] - k` has appeared before, a valid subarray exists
- Use a hash map to store frequency of prefix sums
- Handle the case where prefix sum itself equals `k`

---

## Algorithm
1. Compute the prefix sum array.
2. Initialize an unordered map `m` to store frequencies of prefix sums.
3. Traverse the prefix sum array:
   - If `prefixSum[j] == k`, increment `count`.
   - Let `val = prefixSum[j] - k`.
   - If `val` exists in the map, add its frequency to `count`.
   - Increment the frequency of `prefixSum[j]` in the map.
4. Return `count`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Single pass traversal with constant-time hash map operations.
- **Space Complexity:** `O(n)`  
  Hash map stores prefix sums in the worst case.

---

## Notes
- Efficient for large input sizes.
- Works with negative numbers.
- Hash map stores frequency of prefix sums.
- This is the standard optimal approach for this problem.
- Prefix sum technique is widely used in subarray sum problems.
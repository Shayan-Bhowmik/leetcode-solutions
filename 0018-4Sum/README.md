# 4Sum

## Problem Statement
Given an array `nums` of `n` integers, return an array of all the **unique quadruplets** `[nums[a], nums[b], nums[c], nums[d]]` such that:

- `0 <= a, b, c, d < n`
- `a`, `b`, `c`, and `d` are **distinct**
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in any order.

---

## Solution Overview
This solution finds all unique quadruplets that sum to the given `target` using **sorting and the two-pointer technique**.

Key ideas:
- Sort the array to make duplicate handling easier
- Fix the first two elements using nested loops
- Use two pointers to find the remaining two elements
- Skip duplicates to ensure only unique quadruplets are added
- Use `long long` while calculating sum to prevent overflow

---

## Algorithm
1. Sort the array.
2. Iterate `i` from `0` to `n-1`:
   - Skip duplicates for `i`.
3. Iterate `j` from `i+1` to `n-1`:
   - Skip duplicates for `j`.
4. Use two pointers:
   - `p = j + 1`
   - `q = n - 1`
5. While `p < q`:
   - Compute the sum of four elements.
   - If sum < target → move `p` forward.
   - If sum > target → move `q` backward.
   - If sum == target:
     - Store the quadruplet.
     - Move both pointers.
     - Skip duplicates for `p`.
6. Return the list of quadruplets.

---

## Complexity Analysis
- **Time Complexity:** `O(n³)`  
  Two nested loops and a two-pointer traversal inside.
- **Space Complexity:** `O(1)` (excluding output)  
  Only constant extra space is used apart from the result container.

---

## Notes
- Sorting helps efficiently skip duplicates.
- Duplicate checks ensure unique quadruplets.
- Using `long long` prevents integer overflow during sum calculation.
- The two-pointer approach reduces one nested loop compared to brute force.
- This is a standard optimized approach for this problem.
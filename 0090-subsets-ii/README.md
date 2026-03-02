# Subsets II

## Problem Statement
Given an integer array `nums` that may contain duplicates, return all possible **subsets** (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

---

# Solution: Backtracking with Duplicate Handling

## Solution Overview
This solution generates all subsets using **recursion and backtracking**, while carefully handling duplicate elements.

Key ideas:
- Sort the array first so duplicates are adjacent.
- At every index, we have two choices:
  - Include the current element
  - Exclude the current element
- When excluding an element, skip all its duplicates.
- When we reach the end of the array, store the current subset.

Sorting ensures duplicate subsets are avoided.

---

## Algorithm
1. Sort the array.
2. Define a helper function `printSubset(nums, ans, i, allSubsets)`.
3. Base Case:
   - If `i == nums.size()`, add the current subset `ans` to `allSubsets` and return.
4. Include the current element:
   - Add `nums[i]` to `ans`.
   - Recursively call for `i + 1`.
5. Backtrack:
   - Remove the last element from `ans`.
6. Skip duplicates:
   - Move index forward while the next element is equal to the previous one.
7. Exclude the current element:
   - Recursively call using the updated index.
8. Return all generated subsets.

---

## Complexity Analysis
- **Time Complexity:** `O(2^n)`  
  Each element has two choices (include or exclude).
- **Space Complexity:** `O(n)`  
  Due to recursion stack depth.

---

## Notes
- Sorting is essential to handle duplicates.
- Skipping consecutive duplicates prevents duplicate subsets.
- Generates only unique subsets.
- Backtracking ensures systematic exploration of combinations.
- This is the standard approach for handling subsets with duplicates.
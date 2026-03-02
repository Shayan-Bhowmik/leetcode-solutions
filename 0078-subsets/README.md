# Subsets

## Problem Statement
Given an integer array `nums` of unique elements, return all possible **subsets** (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

---

# Solution: Backtracking (Recursion)

## Solution Overview
This solution generates all subsets using **recursion and backtracking**.

Key ideas:
- At every index, we have two choices:
  - Include the current element
  - Exclude the current element
- When we reach the end of the array, store the current subset.
- Backtracking ensures we explore all possible combinations.

This approach systematically builds the power set.

---

## Algorithm
1. Define a helper function `printSubset(nums, ans, i, allSubsets)`.
2. Base Case:
   - If `i == nums.size()`, add the current subset `ans` to `allSubsets` and return.
3. Include the current element:
   - Add `nums[i]` to `ans`.
   - Recursively call for `i + 1`.
4. Backtrack:
   - Remove the last element from `ans`.
5. Exclude the current element:
   - Recursively call for `i + 1`.
6. In the main function:
   - Initialize an empty result vector.
   - Call helper starting from index `0`.
7. Return all generated subsets.

---

## Complexity Analysis
- **Time Complexity:** `O(2^n)`  
  Each element has two choices (include or exclude).
- **Space Complexity:** `O(n)`  
  Due to recursion stack depth.

---

## Notes
- This is a standard backtracking approach.
- Generates exactly `2^n` subsets.
- Works because the input contains unique elements.
- Backtracking avoids unnecessary copying.
- Clean and interview-standard solution for generating power sets.
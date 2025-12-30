# Missing Number

## Problem Statement
Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

---

## Solution Overview
This solution uses a **sorting-based approach**.

The idea is to first sort the array so that each number ideally appears at its corresponding index.  
After sorting, the array is scanned to find the first index where the value does not match the index, which represents the missing number.

---

## Algorithm
1. Sort the array in ascending order using a comparison-based sorting method.
2. Traverse the sorted array:
   - If `nums[i] != i`, then `i` is the missing number.
3. If all indices match their values, then the missing number is `n`.
4. Return the missing number.

---

## Complexity Analysis
- **Time Complexity:** `O(n²)`  
  (due to the sorting method used)
- **Space Complexity:** `O(1)`

---

## Notes
- This approach is simple and easy to understand.
- More optimal solutions exist using XOR or mathematical summation with `O(n)` time complexity.
- This implementation demonstrates a straightforward method based on sorting and index comparison.
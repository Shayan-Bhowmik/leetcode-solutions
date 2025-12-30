# Search in Rotated Sorted Array

## Problem Statement
There is an integer array `nums` sorted in ascending order (with distinct values), and it is possibly rotated at an unknown pivot.

Given the array `nums` and an integer `target`, return the index of `target` if it is in the array, or `-1` if it is not.

You must write an algorithm with `O(log n)` runtime complexity.

---

## Solution Overview
This problem is solved using a **modified binary search**.

Even though the array is rotated, at least **one half of the array is always sorted**.  
By identifying the sorted half at each step, the search space can be reduced efficiently.

---

## Algorithm
1. Initialize two pointers:
   - `start` at index `0`
   - `end` at index `n - 1`
2. While `start <= end`:
   - Compute `mid`.
   - If `nums[mid]` equals `target`, return `mid`.
3. Check which half is sorted:
   - If the **left half** (`start` to `mid`) is sorted:
     - Check if `target` lies within this range.
     - If yes, move `end` to `mid - 1`.
     - Otherwise, move `start` to `mid + 1`.
   - Else, the **right half** (`mid` to `end`) is sorted:
     - Check if `target` lies within this range.
     - If yes, move `start` to `mid + 1`.
     - Otherwise, move `end` to `mid - 1`.
4. If the loop ends without finding the target, return `-1`.

---

## Complexity Analysis
- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---

## Notes
- This approach preserves binary search efficiency despite the rotation.
- It works because at every step, one side of the array remains sorted.
- This is the optimal solution required by the problem constraints.
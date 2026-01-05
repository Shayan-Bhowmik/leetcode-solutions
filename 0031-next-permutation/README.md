# Next Permutation

## Problem Statement
Given an array of integers `nums`, rearrange the numbers into the **next lexicographically greater permutation**.

If such an arrangement is not possible, rearrange the array into the **lowest possible order** (i.e., sorted in ascending order).

The replacement must be done **in-place** with **constant extra memory**.

---

## Solution Overview
This solution uses a **greedy, in-place approach** to compute the next permutation efficiently.

The key idea is to identify the first position (from the right) where the array stops increasing, then make the smallest possible change to form the next greater permutation. Finally, the remaining suffix is reversed to get the lowest possible order.

---

## Algorithm
1. Traverse the array from right to left to find the first index `pivot` such that:
   - `nums[pivot] < nums[pivot + 1]`
2. If no such index exists:
   - The array is already the largest permutation
   - Reverse the entire array and return
3. Traverse again from the right to find the first element greater than `nums[pivot]`
4. Swap this element with `nums[pivot]`
5. Reverse the subarray to the right of `pivot` to get the smallest lexicographic order
6. The array is now modified to the next permutation

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  (single pass scans and a reverse operation)
- **Space Complexity:** `O(1)`  
  (in-place operations, no extra memory used)

---

## Notes
- Finding the pivot identifies where the next permutation can be formed.
- Swapping ensures the permutation is just larger than the current one.
- Reversing the suffix guarantees the smallest possible order after the pivot.
- This is the optimal solution expected in interviews and competitive programming.
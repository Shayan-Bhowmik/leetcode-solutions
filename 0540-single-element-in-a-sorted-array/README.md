# Single Element in a Sorted Array

## Problem Statement
Given a **sorted integer array** `nums` where every element appears **exactly twice** except for one element that appears **only once**, return the single element.

The solution must run in `O(log n)` time and use `O(1)` extra space.

---

## Solution Overview
This solution uses a **binary search–based approach** that relies on the pairing pattern in a sorted array.

In a valid paired array:
- Pairs start at **even indices** before the single element
- The single element breaks this pattern

By analyzing index parity and neighboring elements, the search space is reduced efficiently.

---

## Algorithm
1. If the array has only one element, return it.
2. Initialize two pointers:
   - `start = 0`
   - `end = n - 1`
3. Perform binary search:
   - Compute `mid`
   - Handle boundary cases:
     - If `mid == 0` and `nums[0] != nums[1]`, return `nums[0]`
     - If `mid == n - 1` and `nums[n - 1] != nums[n - 2]`, return `nums[n - 1]`
   - If `nums[mid]` is different from both neighbors, return it.
4. Use index parity:
   - If `mid` is even:
     - If `nums[mid] == nums[mid - 1]`, search left
     - Otherwise, search right
   - If `mid` is odd:
     - If `nums[mid] == nums[mid - 1]`, search right
     - Otherwise, search left
5. Continue until the single element is found.

---

## Complexity Analysis
- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---

## Notes
- Boundary checks prevent out-of-bounds access.
- Index parity helps identify the invalid half of the array.
- Binary search ensures optimal performance.
# Merge Sorted Array

## Problem Statement
You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n` representing the number of valid elements in `nums1` and `nums2` respectively.

Merge `nums2` into `nums1` so that `nums1` becomes a single sorted array.

The array `nums1` has a size of `m + n`, where the last `n` elements are empty space (`0`) to accommodate elements from `nums2`.

---

## Solution Overview
This solution uses a **two-pointer approach starting from the end** of both arrays.

By merging from the back, we avoid overwriting useful elements in `nums1`. The largest elements are placed first, ensuring the final array remains sorted without using extra space.

---

## Algorithm
1. Initialize three pointers:
   - `i` at the last valid element of `nums1` (`m - 1`)
   - `j` at the last element of `nums2` (`n - 1`)
   - `index` at the last position of `nums1` (`m + n - 1`)
2. While both arrays have elements:
   - Compare `nums1[i]` and `nums2[j]`
   - Place the larger value at `nums1[index]`
   - Move the corresponding pointer backward
3. After the loop:
   - If elements remain in `nums2`, copy them into `nums1`
   - Remaining elements in `nums1` are already in correct position
4. The merged array is stored directly in `nums1`.

---

## Complexity Analysis
- **Time Complexity:** `O(m + n)`  
  (each element is processed exactly once)
- **Space Complexity:** `O(1)`  
  (in-place merge, no extra space used)

---

## Notes
- Merging from the end prevents overwriting elements in `nums1`.
- Only remaining elements from `nums2` need to be copied after the main loop.
- This approach satisfies the in-place constraint efficiently and is optimal for this problem.
# Median of Two Sorted Arrays

## Problem Statement
Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the **median** of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

---

# Solution: Merge and Sort

## Solution Overview
This solution combines both arrays into a single array and then sorts it to compute the median.

Key ideas:
- Merge both arrays into one vector.
- Sort the combined array.
- If the total number of elements is odd → return the middle element.
- If even → return the average of the two middle elements.

This approach is simple and straightforward, though not optimal.

---

## Algorithm
1. Create an empty vector `ans`.
2. Insert all elements from `nums1` into `ans`.
3. Insert all elements from `nums2` into `ans`.
4. Sort the vector `ans`.
5. Let `n = ans.size()`.
6. If `n` is even:
   - Take elements at indices `n/2 - 1` and `n/2`
   - Return their average.
7. If `n` is odd:
   - Return the element at index `n/2`.

---

## Complexity Analysis
- **Time Complexity:** `O((m+n) log (m+n))`  
  Due to sorting the combined array.
- **Space Complexity:** `O(m+n)`  
  Extra space used to store merged array.

---

## Notes
- This is a straightforward approach but does not meet the optimal requirement.
- The expected optimal solution uses binary search with `O(log(min(m, n)))` time.
- Works correctly for all edge cases.
- Easy to implement and understand.
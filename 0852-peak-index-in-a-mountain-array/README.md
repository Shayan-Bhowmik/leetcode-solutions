# Peak Index in a Mountain Array

## Problem Statement
An array `arr` is a **mountain array** if the following properties hold:

- `arr.length >= 3`
- There exists some index `i` (0 < i < arr.length - 1) such that:
  - `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
  - `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given a mountain array `arr`, return the index `i` such that `arr[i]` is the peak of the mountain.

---

## Solution Overview
This solution applies **binary search** to exploit the ordered structure of a mountain array.

At any index, comparing the element with its neighbors reveals whether the current position lies on the increasing slope, decreasing slope, or exactly at the peak.  
Using this observation, the search space is reduced by half at each step until the peak index is found.

---

## Algorithm
1. Initialize:
   - `start = 1`
   - `end = arr.size() - 2`  
   (The peak cannot be at the boundaries)
2. While `start <= end`:
   - Calculate `mid`
   - If `arr[mid]` is greater than both neighbors, return `mid`
   - If `arr[mid - 1] < arr[mid]`, move the search to the right half
   - Otherwise, move the search to the left half
3. Return `-1` as a fallback (the peak is guaranteed to exist)

---

## Complexity Analysis
- **Time Complexity:** `O(log n)`  
  (Binary search)
- **Space Complexity:** `O(1)`  
  (Constant extra space)

---

## Notes
- The input is guaranteed to be a valid mountain array.
- Boundary indices are excluded to prevent out-of-range access.
- Binary search significantly improves performance over a linear scan.
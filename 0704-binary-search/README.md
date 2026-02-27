# Binary Search

## Problem Statement
Given an array of integers `nums` which is sorted in **ascending order**, and an integer `target`, write a function to search `target` in `nums`.

If `target` exists, return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

---

# Solution: Recursive Binary Search

## Solution Overview
This solution uses the **Binary Search algorithm** to efficiently find the target element in a sorted array.

Key ideas:
- Binary Search works only on sorted arrays.
- Compare the target with the middle element.
- If equal → return index.
- If target is greater → search in right half.
- If target is smaller → search in left half.
- Continue recursively until the element is found or the search space becomes empty.

The search space is reduced by half in each step.

---

## Algorithm
1. Define a helper function `binarySearch(nums, target, start, end)`.
2. While `start <= end`:
   - Compute `mid = start + (end - start) / 2`.
   - If `nums[mid] == target`, return `mid`.
   - If `nums[mid] < target`, search in right half:
     - Call `binarySearch(nums, target, mid + 1, end)`.
   - Otherwise, search in left half:
     - Call `binarySearch(nums, target, start, mid - 1)`.
3. If the search space becomes invalid, return `-1`.
4. In the main function, call the helper with:
   - `start = 0`
   - `end = nums.size() - 1`

---

## Complexity Analysis
- **Time Complexity:** `O(log n)`  
  The search space is halved in every recursive call.
- **Space Complexity:** `O(log n)`  
  Due to recursive call stack depth.

---

## Notes
- Works only on sorted arrays.
- Mid calculation avoids overflow using:
  - `start + (end - start) / 2`
- Returns `-1` if the target does not exist.
- Recursive implementation is clean and expressive.
- An iterative version can reduce space complexity to `O(1)`.
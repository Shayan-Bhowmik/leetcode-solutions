# Most Frequent Even Element

## Problem Statement
Given an integer array `nums`, return the most frequent **even** element.

If there are multiple answers, return the **smallest** one.  
If there is no even element, return `-1`.

---

## Solution Overview
This solution uses a **sorting-based frequency counting approach**.

By sorting the array, equal elements are grouped together, making it easy to count frequencies.  
While traversing the sorted array, only even numbers are considered, and the one with the highest frequency is tracked.

---

## Algorithm
1. Sort the array in ascending order.
2. Initialize:
   - `currFreq` to track the frequency of the current number
   - `maxFreq` to store the highest frequency of any even number
   - `ans` to store the result (initialized to `-1`)
3. Traverse the array:
   - Reset `currFreq` when a new number is encountered.
   - Increment `currFreq` for repeated numbers.
4. For each element:
   - If it is even and its frequency is greater than `maxFreq`, update `maxFreq` and `ans`.
5. Return `ans`.

---

## Complexity Analysis
- **Time Complexity:** `O(n log n)`  
  (due to sorting)
- **Space Complexity:** `O(1)`  
  (excluding sorting overhead)

---

## Notes
- Sorting simplifies frequency counting by grouping identical elements.
- Only even numbers are considered when updating the result.
- Returning the smallest even number in case of ties is naturally handled by sorting.
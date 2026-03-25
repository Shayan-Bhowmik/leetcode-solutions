# Merge Intervals

## Problem Statement
Given an array of `intervals` where `intervals[i] = [startᵢ, endᵢ]`, merge all overlapping intervals and return an array of the **non-overlapping intervals** that cover all the intervals in the input.

---

# Solution: Sorting + Greedy Merge

## Solution Overview
This solution sorts the intervals and then merges overlapping ones using a **greedy approach**.

Key ideas:
- Sort intervals based on starting time.
- Compare the current interval with the last merged interval.
- If they overlap → merge them.
- If they don’t overlap → add a new interval.

This ensures all overlapping intervals are combined efficiently.

---

## Algorithm
1. Sort the `intervals` array.
2. Initialize result vector `ans` and add the first interval.
3. Iterate from the second interval to the end:
   - Let last merged interval be `[i1, j1]`.
   - Current interval is `[i2, j2]`.
4. If `j1 >= i2` (overlap exists):
   - Merge by updating:
     - `ans.back()[1] = max(j1, j2)`
5. Else:
   - Add current interval to `ans`.
6. Return `ans`.

---

## Complexity Analysis
- **Time Complexity:** `O(n log n)`  
  Due to sorting the intervals.
- **Space Complexity:** `O(n)`  
  For storing the merged intervals.

---

## Notes
- Sorting is essential to bring overlapping intervals together.
- Greedy merging ensures optimal combination in one pass.
- Works for all overlapping and non-overlapping cases.
- Uses `ans.back()` to efficiently access the last merged interval.
- This is the standard approach for interval merging problems.
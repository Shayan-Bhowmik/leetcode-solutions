# Longest Common Prefix

## Problem Statement
Write a function to find the **longest common prefix** string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

---

# Solution: Sorting + Comparison

## Solution Overview
This solution uses sorting to simplify the comparison process.

Key ideas:
- Sort the array of strings lexicographically.
- The common prefix of the entire array will be the common prefix of:
  - The first string (smallest)
  - The last string (largest)
- Compare characters of these two strings until they differ.

This works because sorting groups similar prefixes together.

---

## Algorithm
1. Let `n = strs.size()`.
2. Sort the array `strs`.
3. Take:
   - `start = strs[0]`
   - `end = strs[n-1]`
4. Initialize an empty string `ans`.
5. Iterate from `i = 0` to `min(start.size(), end.size()) - 1`:
   - If `start[i] != end[i]`, return `ans`.
   - Otherwise, append `start[i]` to `ans`.
6. Return `ans`.

---

## Complexity Analysis
- **Time Complexity:** `O(n log n + m)`  
  - Sorting takes `O(n log n)`  
  - Comparing characters takes `O(m)` where `m` is length of prefix
- **Space Complexity:** `O(1)`  
  No extra space apart from the result.

---

## Notes
- Sorting reduces the problem to comparing only two strings.
- Efficient and clean approach.
- Works because lexicographically first and last strings bound the prefix.
- Avoids comparing all strings pairwise.
- This is a common interview-friendly solution.
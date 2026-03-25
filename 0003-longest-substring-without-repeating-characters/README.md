# Longest Substring Without Repeating Characters

## Problem Statement
Given a string `s`, find the length of the **longest substring** without repeating characters.

A substring is a contiguous sequence of characters within the string.

---

# Solution: Sliding Window + Hash Map

## Solution Overview
This solution uses the **sliding window technique** along with a **hash map** to track characters and their latest indices.

Key ideas:
- Maintain a window `[j, i]` representing the current substring.
- Use a hash map to store the last seen index of each character.
- If a character repeats, move the left pointer `j` to avoid duplicates.
- Update the maximum length at each step.

This ensures the window always contains unique characters.

---

## Algorithm
1. Initialize:
   - `j = 0` (left pointer)
   - `maxLen = 0`
   - Hash map `m` to store character → last index
2. Iterate `i` from `0` to `n-1`:
   - If `s[i]` is already in the map:
     - Update `j = max(j, m[s[i]] + 1)`
   - Update the last seen index:
     - `m[s[i]] = i`
   - Update maximum length:
     - `maxLen = max(maxLen, i - j + 1)`
3. Return `maxLen`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Each character is processed at most once.
- **Space Complexity:** `O(n)`  
  In the worst case, the hash map stores all unique characters.

---

## Notes
- Sliding window ensures optimal linear time complexity.
- Hash map helps track last occurrence of characters efficiently.
- `j` only moves forward, never backward.
- Handles all cases including repeated characters.
- This is the standard optimal approach for this problem.
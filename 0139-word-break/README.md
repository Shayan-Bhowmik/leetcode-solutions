# Word Break

## Problem Statement
Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

---

# Solution: Dynamic Programming + Hash Set

## Solution Overview
This solution uses **dynamic programming** along with a **hash set** to efficiently check if the string can be segmented.

Key ideas:
- Use a boolean DP array where `ans[i]` indicates whether the substring `s[0...i-1]` can be segmented.
- Convert the word dictionary into a hash set for fast lookup.
- For each index `i`, check all possible partitions ending at `i`.
- If a valid word is found and the previous part is segmentable, mark `ans[i] = true`.

---

## Algorithm
1. Convert `wordDict` into an unordered set `dict`.
2. Let `n = s.size()`.
3. Create a boolean vector `ans` of size `n+1`, initialized to `false`.
4. Set `ans[0] = true` (empty string is always valid).
5. For `i` from `1` to `n`:
   - For `j` from `0` to `i-1`:
     - Extract substring `word = s.substr(j, i - j)`.
     - If `ans[j]` is `true` and `word` exists in `dict`:
       - Set `ans[i] = true`
       - Break inner loop.
6. Return `ans[n]`.

---

## Complexity Analysis
- **Time Complexity:** `O(n³)`  
  - Outer loop: `O(n)`  
  - Inner loop: `O(n)`  
  - Substring creation: `O(n)`
- **Space Complexity:** `O(n)`  
  For DP array and hash set.

---

## Notes
- Hash set ensures `O(1)` average lookup time.
- DP avoids recomputation of subproblems.
- `ans[i]` depends on previously computed states.
- Works for reuse of words in the dictionary.
- This is the standard DP solution for this problem.
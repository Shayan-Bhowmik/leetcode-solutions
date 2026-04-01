# Longest Palindromic Substring

## Problem Statement
Given a string `s`, return the **longest palindromic substring** in `s`.

A palindrome is a string that reads the same forward and backward.

---

# Solution: Expand Around Center

## Solution Overview
This solution finds the longest palindromic substring by expanding around each possible center.

Key ideas:
- A palindrome can have:
  - Odd length (center at one character)
  - Even length (center between two characters)
- For each index, expand outward while characters match.
- Track the longest substring found.

This avoids checking all substrings explicitly.

---

## Algorithm
1. If string length `n <= 1`, return `s`.
2. Initialize `result` as an empty string.
3. For each index `i` from `0` to `n-1`:
   
   **Case 1: Odd-length palindrome**
   - Set `start = i`, `end = i`
   - Expand while:
     - `start >= 0`, `end < n`, and `s[start] == s[end]`
   - Extract substring and update result if longer

   **Case 2: Even-length palindrome**
   - Set `start = i`, `end = i + 1`
   - Expand similarly
   - Extract substring and update result if longer

4. Return `result`.

---

## Complexity Analysis
- **Time Complexity:** `O(n²)`  
  Each center expansion can take linear time.
- **Space Complexity:** `O(1)`  
  No extra space is used apart from the result.

---

## Notes
- Handles both odd and even length palindromes.
- Expanding around center is more efficient than brute force.
- Works well for most practical inputs.
- This is a standard and commonly used approach.
- There exists a more advanced algorithm (Manacher’s Algorithm) with `O(n)` time complexity.
# Permutation in String

## Problem Statement
Given two strings `s1` and `s2`, determine if `s2` contains a **permutation** of `s1`.

In other words, check whether any substring of `s2` is an anagram of `s1`.

---

## Solution Overview
This solution uses **frequency counting** to check for permutations.

The main idea is:
- A permutation of `s1` will have the **same character frequency** as `s1`
- For each possible substring of `s2` with length equal to `s1`, compare character frequencies
- If any substring matches, a permutation exists

---

## Algorithm
1. Create a frequency array `freq` of size 26 for string `s1`.
2. Count the frequency of each character in `s1`.
3. For every possible starting index `i` in `s2`:
   - Create a new frequency array `windowFreq` for the current substring.
   - Build the frequency for the substring of length `s1.length()` starting at index `i`.
4. Compare `freq` and `windowFreq`:
   - If both frequency arrays are identical, return `true`.
5. If no matching substring is found, return `false`.

---

## Complexity Analysis
- **Time Complexity:** `O(n * 26 * k)` ≈ `O(n²)` (worst case)  
  For each index in `s2`, a window of size `s1` is processed.
- **Space Complexity:** `O(1)`  
  Only fixed-size arrays of length 26 are used.

---

## Notes
- The helper function `isSameFreq()` compares two frequency arrays.
- This approach explicitly rebuilds the frequency array for each window.
- While correct, this solution is **not optimal** for large inputs.
- A sliding window approach can reduce the time complexity to `O(n)`.
- This implementation prioritizes clarity and correctness over optimization.

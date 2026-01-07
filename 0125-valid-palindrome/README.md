# Valid Palindrome

## Problem Statement
Given a string `s`, determine if it is a palindrome, considering **only alphanumeric characters** and **ignoring cases**.

A string is a palindrome if it reads the same forward and backward after removing non-alphanumeric characters and normalizing letter case.

---

## Solution Overview
This problem is solved using the **two-pointer technique**.

The idea is to compare characters from the beginning and end of the string while:
- Skipping any characters that are **not alphanumeric**
- Comparing characters in a **case-insensitive** manner

If all valid character pairs match, the string is a palindrome.

---

## Algorithm
1. Initialize two pointers:
   - `start` at the beginning of the string
   - `end` at the end of the string
2. While `start < end`:
   - If `s[start]` is not alphanumeric, increment `start` and continue.
   - If `s[end]` is not alphanumeric, decrement `end` and continue.
   - Convert both characters to lowercase and compare them.
     - If they do not match, return `false`.
   - Move both pointers inward (`start++`, `end--`).
3. If all comparisons pass, return `true`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Each character is processed at most once.
- **Space Complexity:** `O(1)`  
  No extra space is used apart from variables.

---

## Notes
- The `isalnum()` function is used to filter out non-alphanumeric characters.
- The `tolower()` function ensures case-insensitive comparison.
- This approach avoids creating a new filtered string, making it space-efficient.
- The two-pointer technique is optimal for palindrome-related problems.
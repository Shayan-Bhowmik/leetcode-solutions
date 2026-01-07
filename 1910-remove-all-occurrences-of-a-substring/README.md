# Remove All Occurrences of a Substring

## Problem Statement
Given two strings `s` and `part`, repeatedly remove the **leftmost occurrence** of `part` from `s` until `part` no longer exists in `s`.

Return the final string after all such removals.

---

## Solution Overview
This problem is solved using **string search and erase operations**.

The core idea is to:
- Continuously search for the substring `part` inside `s`
- Remove it whenever it is found
- Repeat the process until `part` no longer appears in `s`

This guarantees that all occurrences are removed in the required order.

---

## Algorithm
1. While the string `s` is not empty:
   - Search for `part` in `s` using `find()`.
2. If `part` is found:
   - Remove it from `s` using `erase()` starting at the found index.
3. Repeat the above steps until `find()` no longer locates `part`.
4. Return the final modified string `s`.

---

## Complexity Analysis
- **Time Complexity:** `O(n²)` (worst case)  
  Each `find()` operation can take `O(n)`, and it may be called multiple times.
- **Space Complexity:** `O(1)`  
  The string is modified in place without extra data structures.

---

## Notes
- `string::find()` returns the index of the first occurrence of `part`.
- `string::erase(pos, len)` removes a substring of length `len` starting at index `pos`.
- The condition `s.find(part) < s.length()` ensures that `part` exists in `s`.
- This solution is simple and effective for typical input sizes.
- More optimized approaches (e.g., stack-based solutions) can reduce time complexity for very large inputs.
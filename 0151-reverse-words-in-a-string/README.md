# Reverse Words in a String

## Problem Statement
Given a string `s`, reverse the **order of words** in the string.

A word is defined as a sequence of non-space characters.  
The returned string should:
- Have words in reverse order
- Contain **only a single space** between words
- Have **no leading or trailing spaces**

---

## Solution Overview
This solution works by **reversing the entire string first**, and then reversing each individual word to restore its correct orientation.

By doing this:
- The word order is reversed automatically
- Extra spaces are handled by explicitly constructing the result string

---

## Algorithm
1. Reverse the entire string `s`.
2. Initialize an empty string `ans` to store the result.
3. Traverse the reversed string:
   - Extract characters until a space is encountered to form a word.
   - Reverse the extracted word.
4. If the word is non-empty:
   - Append it to `ans` with a single space.
5. Remove the leading space from `ans` and return the final string.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Each character is processed a constant number of times.
- **Space Complexity:** `O(n)`  
  Extra space is used to build the result string.

---

## Notes
- `reverse(s.begin(), s.end())` reverses the full string to invert word order.
- Each word is reversed individually to correct character order.
- Empty words caused by multiple spaces are skipped.
- `substr(1)` removes the extra leading space added during construction.
- This approach avoids using additional data structures like stacks or arrays.
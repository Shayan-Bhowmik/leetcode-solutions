# String Compression

## Problem Statement
Given an array of characters `chars`, compress it using the following rules:

- Characters that appear consecutively should be replaced by the character followed by the count.
- If a character appears only once, it should remain unchanged.
- The compressed result must be stored **in the same array**.
- Return the **new length** of the array after compression.

You must use **constant extra space**.

---

## Solution Overview
This solution performs **in-place compression** using two pointers:

- One pointer scans the input array to count consecutive characters.
- Another pointer (`index`) keeps track of the position where the compressed output should be written.

By overwriting the original array, the space constraint is satisfied.

---

## Algorithm
1. Initialize `index` to track the write position in the array.
2. Traverse the array using index `i`:
   - Store the current character.
   - Count how many times it appears consecutively.
3. Write the character at position `index`.
4. If the count is greater than `1`:
   - Convert the count to a string.
   - Write each digit of the count into the array.
5. Adjust the loop index to continue processing correctly.
6. Resize the array to the compressed length.
7. Return the final value of `index`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Each character is processed once.
- **Space Complexity:** `O(1)`  
  Compression is done in place without extra data structures.

---

## Notes
- The `index` pointer ensures that the compressed result overwrites the original array.
- `to_string(count)` is used to handle multi-digit counts.
- The `i--` adjustment accounts for the extra increment in the inner loop.
- `chars.resize(index)` trims the array to the final compressed size.
- This solution satisfies both the in-place and constant space constraints.
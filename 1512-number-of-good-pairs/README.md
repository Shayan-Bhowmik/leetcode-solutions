# Number of Good Pairs

## Problem Statement
Given an array of integers `nums`, return the number of **good pairs**.

A pair `(i, j)` is called good if:
- `nums[i] == nums[j]`
- `i < j`

---

# Solution: Brute Force (Nested Loop)

## Solution Overview
This approach checks every possible pair `(i, j)` such that `i < j` and counts how many pairs contain equal values.

Key ideas:
- Use two nested loops
- Ensure `j` always starts from `i + 1`
- Compare elements directly
- Increment count when a good pair is found

---

## Algorithm
1. Initialize `count = 0`.
2. Let `n` be the size of the array.
3. Iterate `i` from `0` to `n-1`.
4. For each `i`, iterate `j` from `i+1` to `n-1`.
5. If `nums[i] == nums[j]`, increment `count`.
6. Return `count`.

---

## Complexity Analysis
- **Time Complexity:** `O(n²)`  
  Two nested loops check all possible pairs.
- **Space Complexity:** `O(1)`  
  Only constant extra space is used.

---

## Notes
- Straightforward implementation.
- Ensures `i < j` by starting inner loop at `i + 1`.
- Works efficiently for small input sizes.
- Can be optimized further using a hash map to count frequencies.
- This approach clearly demonstrates the pair comparison logic.
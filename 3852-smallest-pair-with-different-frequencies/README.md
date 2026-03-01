# Minimum Distinct Frequency Pair

## Problem Statement
Given an integer array `nums`, return a pair of distinct integers `[a, b]` such that:

- `a` and `b` both exist in `nums`
- The frequency of `a` is different from the frequency of `b`
- `a < b`

If multiple valid pairs exist, return any one of them.

If no such pair exists, return `[-1, -1]`.

---

# Solution: Frequency Counting + Sorting

## Solution Overview
This solution first counts the frequency of each distinct element using a hash map.  
Then it checks all pairs of distinct elements to find two whose frequencies are different.

Key ideas:
- Use a hash map to store frequency of each number.
- Extract all distinct numbers.
- Sort them to maintain ascending order.
- Check pairs of distinct elements.
- Return the first pair whose frequencies are different.

---

## Algorithm
1. If the size of `nums` is less than 2, return `[-1, -1]`.
2. Create an unordered map `m` to store frequencies.
3. Traverse the array and increment frequency of each number.
4. Store all distinct keys from the map into a vector `v`.
5. Sort the vector `v`.
6. Use two nested loops:
   - For each `i`, check elements `j > i`.
   - If `m[v[i]] != m[v[j]]`, return `{v[i], v[j]}`.
7. If no valid pair is found, return `[-1, -1]`.

---

## Complexity Analysis
- **Time Complexity:**  
  - Frequency counting: `O(n)`  
  - Sorting distinct elements: `O(d log d)`  
  - Pair comparison: `O(d²)`  
  Overall: `O(n + d²)` in the worst case, where `d` is the number of distinct elements.
- **Space Complexity:** `O(d)`  
  For storing frequencies and distinct elements.

---

## Notes
- Uses `unordered_map` for efficient frequency counting.
- Sorting ensures the returned pair satisfies `a < b`.
- Returns the first valid pair found.
- If all elements have identical frequencies, the function returns `[-1, -1]`.
- This approach prioritizes clarity over optimal pair selection.
# Two Sum

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two distinct elements such that their sum equals `target`.

You may assume that exactly one valid solution exists, and the same element cannot be used twice.

---

# Approach 1: Brute Force

## Solution Overview

This approach checks all possible pairs in the array to find two numbers whose sum equals the target.

It uses two nested loops:
- The outer loop selects the first element.
- The inner loop checks every remaining element after it.

As soon as a valid pair is found, their indices are returned.

---

## Algorithm

1. Get the size of the array `n`.
2. Use a loop from `i = 0` to `n - 1`.
3. For each `i`, run another loop from `j = i + 1` to `n - 1`.
4. Check if `nums[i] + nums[j] == target`.
5. If true, return `{i, j}`.
6. Since exactly one solution exists, the function exits immediately after finding the pair.

---

## Complexity Analysis (Brute Force)

- **Time Complexity:**  
  `O(n²)` — Every pair is checked in the worst case.

- **Space Complexity:**  
  `O(1)` — No additional data structures are used.

---

# Approach 2: Hashing (Optimized)

## Solution Overview

This approach uses a hash map (`unordered_map`) to store previously visited elements and their indices.

Instead of checking all pairs, we compute the complement (`target - current_element`) and check if it already exists in the map.

If it exists, we have found the required pair.

---

## Algorithm

1. Create an empty hash map `m`.
2. Traverse the array using index `i`.
3. For each element:
   - Let `first = nums[i]`
   - Compute `second = target - first`
4. Check if `second` exists in the hash map:
   - If yes, return `{i, m[second]}`
5. Otherwise, store `first` and its index in the map.
6. Continue until the pair is found.

---

## Complexity Analysis (Hashing)

- **Time Complexity:**  
  `O(n)` — Each element is processed once, and hash lookups take constant time on average.

- **Space Complexity:**  
  `O(n)` — Extra space is used to store elements in the hash map.

---

# Conclusion

- The **Brute Force** solution is simple and intuitive.
- The **Hashing** approach is more efficient and preferred for large datasets.
- Both solutions correctly solve the problem under the given constraints.
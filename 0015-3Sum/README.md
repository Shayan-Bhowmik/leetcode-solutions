# 3Sum

## Problem Statement
Given an integer array `nums`, return all the unique triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `i != k`, and `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set must not contain duplicate triplets.

---

# Approach 1: Brute Force (Triple Nested Loop)

## Solution Overview
This approach checks **every possible combination of three elements** using three nested loops.

To avoid duplicate triplets:
- Each valid triplet is sorted.
- A `set` is used to store only unique triplets.

---

## Algorithm
1. Initialize an empty result vector `ans`.
2. Use three nested loops:
   - `i` from `0 → n-1`
   - `j` from `i+1 → n-1`
   - `k` from `j+1 → n-1`
3. If `nums[i] + nums[j] + nums[k] == 0`:
   - Store them in a vector.
   - Sort the triplet.
   - Insert into a `set` to prevent duplicates.
4. Convert set to vector and return.

---

## Complexity Analysis
- **Time Complexity:** `O(n³)`  
- **Space Complexity:** `O(n)` (for storing unique triplets)

---

# Approach 2: Better (Hashing)

## Solution Overview
Instead of checking all three combinations directly:

- Fix one element.
- Use a `set` to check if the required third element exists.
- Store triplets in a `set` to avoid duplicates.

This reduces one loop and improves time complexity.

---

## Algorithm
1. Initialize a set `uniqueTriplet`.
2. For each index `i`:
   - Set `target = -nums[i]`
   - Use a `set<int>` to track seen elements.
3. For each `j` from `i+1`:
   - Compute `third = target - nums[j]`
   - If `third` exists in set:
     - Form triplet
     - Sort and insert into `uniqueTriplet`
   - Insert `nums[j]` into set
4. Convert set to vector and return.

---

## Complexity Analysis
- **Time Complexity:** `O(n² log n)`  
  (due to set insertions)
- **Space Complexity:** `O(n)`

---

# Approach 3: Optimal (Two Pointer Technique)

## Solution Overview
This is the most efficient approach.

Steps:
- First, sort the array.
- Fix one element.
- Use two pointers (`j` and `k`) to find the remaining two elements.
- Skip duplicates carefully to avoid repeated triplets.

This removes the need for extra data structures.

---

## Algorithm
1. Sort the array.
2. Iterate `i` from `0 → n-1`:
   - Skip duplicate values of `nums[i]`.
3. Set:
   - `j = i + 1`
   - `k = n - 1`
4. While `j < k`:
   - Compute sum.
   - If sum < 0 → move `j++`
   - If sum > 0 → move `k--`
   - If sum == 0:
     - Store triplet.
     - Move both pointers.
     - Skip duplicate values.
5. Return result.

---

## Complexity Analysis
- **Time Complexity:** `O(n²)`  
- **Space Complexity:** `O(1)` (excluding output)

---

# Final Notes

- Brute force is good for understanding the logic.
- Hashing improves performance but still uses extra space.
- Two-pointer approach is the most optimal and preferred in interviews.
- Sorting is the key optimization step in the optimal solution.

This progression (Brute → Better → Optimal) clearly shows how the solution is improved step by step.
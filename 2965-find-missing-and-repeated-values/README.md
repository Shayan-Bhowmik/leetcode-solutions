# Find Missing and Repeated Values

## Problem Statement
You are given an `n x n` grid containing numbers from `1` to `n²`.  

Exactly:
- One number appears twice (repeated).
- One number is missing.

Return a vector containing the repeated number followed by the missing number.

---

## Approach: Hashing + Mathematical Formula

### Solution Overview

Since the grid should contain numbers from `1` to `n²`, we know the expected total sum using the formula:

Expected Sum = n² × (n² + 1) / 2

We:
- Traverse the grid once.
- Use an unordered set to detect the repeated number.
- Compute the actual sum of all elements.
- Use the difference between expected and actual sums to calculate the missing number.

This allows us to solve the problem efficiently with a single traversal.

---

## Algorithm

1. Initialize:
   - A hash set to track visited elements.
   - Variables for `actualSum` and `expectedSum`.
   - Variables `a` (repeated) and `b` (missing).

2. Traverse the grid:
   - Add each element to `actualSum`.
   - If the element already exists in the set:
     - Mark it as the repeated number.
   - Otherwise, insert it into the set.

3. Compute the expected sum using:
   
   expectedSum = (n × n) × ((n × n) + 1) / 2

4. Compute the missing number using:

   missing = expectedSum + repeated - actualSum

5. Return `{repeated, missing}`.

---

## Complexity Analysis

- **Time Complexity:** `O(n²)`  
  Every element in the grid is visited once.

- **Space Complexity:** `O(n²)`  
  The unordered set stores up to `n²` elements.

---

## Notes

- Hashing helps efficiently detect the duplicate.
- The mathematical sum formula helps derive the missing number.
- No sorting or extra nested traversal is required.
- This approach balances clarity and efficiency.
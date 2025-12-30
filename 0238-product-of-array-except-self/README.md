# Product of Array Except Self

## Problem Statement
Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

You must write an algorithm that runs in `O(n)` time and **without using the division operation**.

---

## Solution Overview
This problem is solved using two approaches:

1. **Brute Force Approach**  
   For each index, compute the product of all other elements by iterating through the array.  
   While correct, this approach is inefficient and results in **Time Limit Exceeded (TLE)**.

2. **Optimized Prefix & Suffix Product Approach**  
   Uses prefix and suffix products to compute the result in linear time without division.

Both approaches are included to demonstrate optimization from a naive solution to an efficient one.

---

## Approach 1: Brute Force (TLE)

### Algorithm
1. For each index `i`, initialize `product` as `1`.
2. Iterate through the array again:
   - Multiply all elements except `nums[i]`.
3. Store the computed product in the result array.
4. Return the result array.

### Complexity Analysis
- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)` (excluding output array)

### Result
- ❌ **Time Limit Exceeded** for large inputs.

---

## Approach 2: Prefix & Suffix Product (Optimized)

### Algorithm
1. Create two auxiliary arrays:
   - `prefix[i]` stores the product of all elements before index `i`.
   - `suffix[i]` stores the product of all elements after index `i`.
2. Compute the prefix products from left to right.
3. Compute the suffix products from right to left.
4. For each index `i`, compute: answer[i] = prefix[i] * suffix[i]
5. Return the result array.

### Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

### Result
- ✅ **Accepted**

---

## Notes
- The optimized solution avoids division as required.
- Prefix and suffix products allow efficient computation in a single pass each.
- This approach handles cases involving zero values correctly.
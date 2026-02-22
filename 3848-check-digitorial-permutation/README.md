# Check Digitorial Permutation

## Problem Description

You are given an integer `n`.

Define the **digitorial** of a number as the sum of the factorials of its digits.

A number `n` is called a **digitorial permutation** if the digits of `n` can be rearranged to form its digitorial value.

Return `true` if `n` is a digitorial permutation, otherwise return `false`.

---

## Solution Overview

This problem involves two main steps:

1. Compute the **digitorial value**:
   - Extract each digit of `n`
   - Compute its factorial
   - Add all factorial values

2. Check whether:
   - The digits of the original number `n`
   - And the digits of the digitorial sum  
   
   Are permutations of each other.

To verify permutation:
- Convert both numbers to strings
- Sort both strings
- Compare them

If both sorted strings are equal, then `n` is a digitorial permutation.

---

## Algorithm

1. Define a helper function `factorial(int n)`:
   - Compute factorial using an iterative loop.
2. Store original number in `Onum`.
3. Extract digits of `n`:
   - Compute factorial of each digit
   - Accumulate the sum.
4. Convert:
   - `Onum` → string → sort
   - `sum` → string → sort
5. If lengths differ → return `false`.
6. If sorted strings are equal → return `true`.
7. Otherwise → return `false`.

---

## Complexity Analysis

Let `d` be the number of digits in `n`.

- **Time Complexity:** `O(d log d)`
  - Extracting digits → `O(d)`
  - Sorting strings → `O(d log d)`
  - Factorial computation is constant time (digit ≤ 9).

- **Space Complexity:** `O(d)`
  - Used for storing string representations.

---

## Key Observations

- Since digits range from `0–9`, factorial computation is bounded.
- Sorting is an efficient way to verify digit permutations.
- If the number of digits differs between original number and digitorial sum, permutation is impossible.
- The solution is straightforward and works efficiently for typical integer constraints.
# Total Waviness of Numbers in a Range

## Problem Statement

Given two integers `num1` and `num2`, calculate the **total waviness** of all numbers in the inclusive range `[num1, num2]`.

A digit is considered **wavy** if it is either:
- Strictly greater than both of its adjacent digits (a local maximum), or
- Strictly smaller than both of its adjacent digits (a local minimum).

Only digits with both a left and right neighbor can contribute to waviness.

Return the total waviness count across all numbers in the range.

---

# Solution: Range Traversal + Digit Comparison

## Solution Overview

This solution examines every number in the given range and counts the digits that form local peaks or valleys.

Key ideas:
- Convert each number to a string for easy digit access.
- Numbers with fewer than 3 digits cannot contain a wavy digit.
- For each middle digit:
  - Check if it is greater than both neighbors.
  - Check if it is smaller than both neighbors.
- Increment the waviness count whenever either condition is satisfied.

---

## Algorithm

1. Initialize:
   ```cpp
   waviness = 0
   ```
2. Traverse every number from `num1` to `num2`.
3. Convert the current number to a string.
4. Let:
   ```cpp
   n = str.size()
   ```
5. If `n < 3`:
   - Continue to the next number.
6. Traverse each middle digit:
   ```cpp
   i = 1 to n - 2
   ```
7. Check if the digit forms:
   - A local maximum:
     ```cpp
     str[i] > str[i-1] && str[i] > str[i+1]
     ```
   - A local minimum:
     ```cpp
     str[i] < str[i-1] && str[i] < str[i+1]
     ```
8. If either condition is true:
   - Increment `waviness`.
9. Return the total waviness count.

---

## Complexity Analysis

Let:

- `R = num2 - num1 + 1`
- `D` = maximum number of digits among numbers in the range

### Time Complexity

- **O(R × D)**

Each number is processed once, and each digit is examined at most once.

### Space Complexity

- **O(D)**

Used for storing the string representation of the current number.

---

## Notes

- Numbers with fewer than three digits cannot contribute to waviness.
- A wavy digit must have both a left and right neighbor.
- Local maxima and local minima both contribute to the count.
- Converting numbers to strings simplifies digit access.
- This is a straightforward brute-force solution.
- Can become expensive for very large ranges due to checking every number individually.
# Fibonacci Number

## Problem Statement
The **Fibonacci numbers**, commonly denoted `F(n)`, form a sequence such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is:

- `F(0) = 0`
- `F(1) = 1`
- `F(n) = F(n - 1) + F(n - 2)`, for `n > 1`

Given `n`, calculate `F(n)`.

---

# Solution: Recursive Approach

## Solution Overview
This solution directly follows the mathematical definition of the Fibonacci sequence using recursion.

Key ideas:
- Base cases: `F(0) = 0` and `F(1) = 1`
- For `n > 1`, recursively compute:
  - `fib(n-1)`
  - `fib(n-2)`
- Return their sum

This approach mirrors the recurrence relation exactly.

---

## Algorithm
1. If `n == 0` or `n == 1`, return `n`.
2. Otherwise, return:
   - `fib(n - 1) + fib(n - 2)`.

---

## Complexity Analysis
- **Time Complexity:** `O(2^n)`  
  Each function call makes two recursive calls, leading to exponential growth.
- **Space Complexity:** `O(n)`  
  Due to recursion stack depth in the worst case.

---

## Notes
- This approach is simple and directly reflects the Fibonacci definition.
- It is not efficient for large `n` due to repeated calculations.
- Many subproblems are recomputed multiple times.
- Can be optimized using:
  - Memoization (Top-Down DP)
  - Tabulation (Bottom-Up DP)
  - Space-optimized iterative approach
- This version is useful for understanding recursion fundamentals.
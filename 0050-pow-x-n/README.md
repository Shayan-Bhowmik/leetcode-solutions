# Pow(x, n)

## Problem Statement
Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., `xⁿ`).

---

## Solution Overview
This problem is solved using **binary exponentiation (fast power)**.

Instead of multiplying `x` repeatedly `n` times, the exponent is reduced by half at each step, resulting in a logarithmic time solution.  
Special care is taken to handle **negative exponents** and **integer overflow edge cases**.

---

## Algorithm
1. Store the exponent `n` in a variable of type `long` to safely handle edge cases such as `n = INT_MIN`.
2. If `n` is negative:
   - Convert the problem to a positive exponent by setting `x = 1 / x`.
   - Negate the exponent.
3. Initialize the result as `1`.
4. While the exponent is greater than `0`:
   - If the exponent is odd, multiply the result by `x`.
   - Square `x`.
   - Divide the exponent by `2`.
5. Return the final result.

---

## Complexity Analysis
- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---

## Notes
- Binary exponentiation significantly improves performance over the naive approach.
- Using a `long` variable for the exponent prevents overflow when handling `INT_MIN`.
- This solution satisfies all problem constraints and passes all test cases.
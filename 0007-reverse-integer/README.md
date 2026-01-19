# Reverse Integer

## Problem Statement
Given a signed 32-bit integer `x`, reverse its digits.

If reversing `x` causes the value to go outside the **32-bit signed integer range**
`[-2³¹, 2³¹ − 1]`, return `0`.

---

## Solution Overview
This solution reverses the integer **digit by digit** while carefully handling **overflow conditions**.

Instead of converting the integer to a string, it uses mathematical operations to:
- Extract digits
- Build the reversed number
- Detect overflow before it occurs

---

## Algorithm
1. Initialize `revNum` to `0`.
2. While `x` is not equal to `0`:
   - Extract the last digit using `x % 10`.
   - Check for overflow:
     - If `revNum > INT_MAX / 10` or `revNum < INT_MIN / 10`, return `0`.
   - Append the digit to `revNum` by multiplying it by `10` and adding the digit.
   - Remove the last digit from `x` using integer division.
3. Return `revNum`.

---

## Complexity Analysis
- **Time Complexity:** `O(log x)`  
  The loop runs once for each digit in the integer.
- **Space Complexity:** `O(1)`  
  Only constant extra space is used.

---

## Notes
- The overflow check is performed **before** updating `revNum`, ensuring correctness.
- This approach correctly handles both positive and negative integers.
- Using arithmetic operations avoids the overhead of string conversion.
- Returning `0` on overflow aligns with the problem constraints.
- This solution is optimal and commonly expected in interviews.
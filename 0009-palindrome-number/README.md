# Palindrome Number

## Problem Statement
Given an integer `x`, return `true` if `x` is a **palindrome**, and `false` otherwise.

An integer is a palindrome when it reads the same backward as forward.

---

## Solution Overview
This solution checks whether a number is a palindrome by **reversing the integer** and comparing it with the original value.

Key ideas:
- Negative numbers are **never palindromes**
- Reverse the digits using arithmetic operations
- Compare the reversed number with the original number

Overflow is handled safely during the reversal process.

---

## Algorithm
1. If `x` is negative, return `false`.
2. Reverse the integer using the helper function `reverse(x)`:
   - Extract digits using modulo (`% 10`)
   - Build the reversed number
   - Check for overflow before updating
3. Compare the reversed number with the original `x`:
   - If they are equal, return `true`
   - Otherwise, return `false`

---

## Complexity Analysis
- **Time Complexity:** `O(log x)`  
  The number of iterations depends on the number of digits in `x`.
- **Space Complexity:** `O(1)`  
  Only constant extra space is used.

---

## Notes
- Negative numbers are immediately rejected as palindromes.
- The helper `reverse()` function safely handles integer overflow.
- This approach avoids converting the integer to a string.
- Comparing the reversed number with the original value makes the logic simple and clear.
- This is a common and interview-acceptable approach for this problem.
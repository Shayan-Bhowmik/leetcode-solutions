# Valid Parentheses

## Problem Statement

Given a string `s` containing just the characters:

- `'('`, `')'`
- `'{'`, `'}'`
- `'['`, `']'`

Determine if the input string is valid.

A string is valid if:

1. Open brackets are closed by the same type of brackets.
2. Open brackets are closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

---

# Solution: Stack-Based Matching

## Solution Overview

This solution uses a **stack** to keep track of opening brackets.

Key ideas:
- Push every opening bracket onto the stack.
- When a closing bracket is encountered:
  - Check whether the stack is empty.
  - Verify that the top of the stack contains the matching opening bracket.
- If brackets do not match, the string is invalid.
- At the end, the stack must be empty for the string to be valid.

The stack naturally follows the Last-In-First-Out (LIFO) order required for bracket matching.

---

## Algorithm

1. Create an empty stack.
2. Traverse the string character by character.
3. If the current character is:
   - `'('`
   - `'{'`
   - `'['`
   
   Push it onto the stack.
4. Otherwise, the character is a closing bracket:
   - If the stack is empty:
     - Return `false`.
   - Check whether the top element matches the current closing bracket.
   - If it matches:
     - Pop the stack.
   - Otherwise:
     - Return `false`.
5. After processing all characters:
   - If the stack is empty:
     - Return `true`.
   - Otherwise:
     - Return `false`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  
  Each character is pushed and popped at most once.

- **Space Complexity:** `O(n)`
  
  In the worst case, all characters are opening brackets and are stored in the stack.

---

## Notes

- Stack is the ideal data structure for matching nested brackets.
- Detects invalid ordering immediately.
- Handles all three bracket types.
- Returns false if a closing bracket appears before its matching opening bracket.
- Ensures no unmatched opening brackets remain at the end.
- This is the standard optimal solution for the problem.
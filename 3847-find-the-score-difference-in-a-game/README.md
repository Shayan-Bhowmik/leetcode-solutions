# Find the Score Difference in a Game

## Problem Description

You are given an integer array `nums`.

Two players are playing a game where they process the array from left to right.  
A boolean variable `active` determines which player receives the current element.

The game follows these rules:

- Initially, `active = true`.
- For each element:
  - If the element is **odd**, the value of `active` is flipped.
  - If the current position (1-based index) is a multiple of `6`, the value of `active` is flipped.
- After applying the above rules:
  - If `active` is `true`, the current number is added to Player 1's score.
  - Otherwise, it is added to Player 2's score.

Return the difference between Player 1’s score and Player 2’s score.

---

## Solution Overview

This problem is solved using direct simulation.

We:

- Maintain two score variables (`score1`, `score2`)
- Maintain a boolean flag `active`
- Traverse the array once
- Apply toggle conditions before assigning the score

---

## Algorithm

1. Initialize:
   - `score1 = 0`
   - `score2 = 0`
   - `active = true`
2. Traverse the array:
   - If `nums[i]` is odd → toggle `active`
   - If `(i + 1) % 6 == 0` → toggle `active`
   - If `active` is true → add to `score1`
   - Else → add to `score2`
3. Return `score1 - score2`

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Observation

If both toggle conditions happen at the same index, `active` flips twice and remains unchanged.
This guarantees correct simulation in a single pass.
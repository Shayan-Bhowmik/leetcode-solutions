# Stone Game

## Problem Statement

Alice and Bob are playing a game with an even number of piles.

- There are:
  ```cpp
  piles
  ```
  where:

  ```cpp
  piles[i]
  ```

  represents the number of stones in the `i-th` pile.

- Alice and Bob take turns.
- Alice moves first.
- On each turn, a player removes **either the leftmost or the rightmost pile**.
- Both players play optimally.

Return:

```cpp
true
```

if Alice wins; otherwise return:

```cpp
false
```

---

# Solution: Mathematical Observation

## Solution Overview

This problem has a surprising mathematical result.

Since:

- The number of piles is **always even**.
- The total number of stones is **odd**, so ties are impossible.

Alice can always guarantee a win without needing Dynamic Programming.

Therefore, the solution simply returns:

```cpp
true;
```

---

## Why Alice Always Wins

Consider the pile indices:

```text
0 1 2 3 4 5 ...
```

There are exactly two groups:

- Even-indexed piles
- Odd-indexed piles

Before the game starts, Alice computes:

- Sum of stones at even indices.
- Sum of stones at odd indices.

She chooses whichever sum is larger.

---

### Key Observation

Initially, Alice can choose either:

- the leftmost pile, or
- the rightmost pile.

These two piles always belong to **different parity groups**.

By choosing appropriately on her first move, Alice commits herself to collecting **either all even-indexed piles or all odd-indexed piles** throughout the game.

No matter how Bob plays, Alice can always continue taking piles from her chosen parity.

Thus, Alice guarantees collecting the larger of:

```text
Sum of even-indexed piles
```

or

```text
Sum of odd-indexed piles
```

Since the total number of stones is odd:

```text
Even Sum ≠ Odd Sum
```

One of them is strictly larger.

Therefore, Alice always ends with more stones than Bob.

---

## Algorithm

### Step 1: Return True

Simply return:

```cpp
return true;
```

No further computation is necessary.

---

## Why Dynamic Programming Isn't Needed

A general interval DP solution exists:

```cpp
dp[i][j]
```

representing the maximum score difference for subarray:

```cpp
[i...j]
```

However, the constraints of this problem make that unnecessary.

The parity strategy guarantees Alice's victory for every valid input.

---

## Complexity Analysis

### Time Complexity

No iteration is performed.

```cpp
O(1)
```

---

### Space Complexity

No extra memory is used.

```cpp
O(1)
```

---

## Notes

- The number of piles is always even.
- The total number of stones is always odd, so a tie cannot occur.
- Alice can force herself to take either all even-indexed piles or all odd-indexed piles.
- She chooses the parity with the larger total number of stones.
- Therefore, Alice is guaranteed to win regardless of Bob's moves.
- This is the standard optimal solution for the problem.
# Winner Square Game

## Problem Statement

Alice and Bob play a game starting with:

```cpp
n
```

stones.

On each turn, a player can remove any **perfect square number** of stones:

```text
1, 4, 9, 16, ...
```

The player who cannot make a move loses.

Alice moves first, and both players play optimally.

Return:

```cpp
true
```

if Alice wins, otherwise return:

```cpp
false
```

---

# Solution: Dynamic Programming

## Solution Overview

This is a classic **Game DP** problem.

The key idea is:

> A position is winning if there exists at least one move that puts the opponent into a losing position.

We define:

```cpp
dp[i]
```

as whether the player whose turn it is can win when there are exactly `i` stones remaining.

---

## DP State

```cpp
dp[i] = true
```

means:

> The current player can force a win with `i` stones.

```cpp
dp[i] = false
```

means:

> The current player will lose with `i` stones if both players play optimally.

---

# Step 1: Base Case

With zero stones remaining:

```cpp
dp[0] = false;
```

The player whose turn it is cannot make a move, so they lose.

---

# Step 2: Try Every Perfect Square

For every number of stones:

```cpp
i = 1 ... n
```

try every possible perfect square:

```cpp
j * j <= i
```

If we remove:

```cpp
j * j
```

stones, the opponent receives:

```cpp
i - j * j
```

stones.

Therefore, if:

```cpp
dp[i - j * j] == false
```

the opponent is in a losing position.

So the current player can win:

```cpp
dp[i] = true;
```

---

## Transition

The recurrence is:

```cpp
dp[i] = true
```

if there exists some `j` such that:

```cpp
dp[i - j * j] == false
```

Otherwise:

```cpp
dp[i] = false;
```

In code:

```cpp
for (int j = 1; j * j <= i; j++) {
    if (!dp[i - j * j]) {
        dp[i] = true;
        break;
    }
}
```

---

# Why This Works

Consider:

```text
n = 2
```

Alice can only remove:

```text
1
```

stone.

The game becomes:

```text
2 → 1
```

Now Bob removes the final stone:

```text
1 → 0
```

Alice has no move, so Alice loses.

Therefore:

```cpp
dp[2] = false;
```

Now consider:

```text
n = 3
```

Alice can remove one stone:

```text
3 → 2
```

Since:

```cpp
dp[2] = false
```

Alice can force Bob into a losing position.

Therefore:

```cpp
dp[3] = true;
```

This principle is applied to every value up to `n`.

---

# Example

For small values:

| `n` | Result | Reason |
|---:|:---:|---|
| 0 | Lose | No move |
| 1 | Win | Take `1` |
| 2 | Lose | Only move leads to `1` |
| 3 | Win | Take `1`, leaving `2` |
| 4 | Win | Take `4` |
| 5 | Lose | Every move leads to a winning state |

The DP automatically determines these states.

---

# Complexity Analysis

Let:

```cpp
n = input size
```

### Time Complexity

For every `i`, we test all perfect squares up to `i`.

There are approximately:

```text
√i
```

such squares.

Therefore:

```text
O(n√n)
```

---

### Space Complexity

The DP array contains:

```cpp
n + 1
```

boolean values.

```text
O(n)
```

---

# Notes

- This is a **bottom-up Dynamic Programming** solution.
- `dp[i]` represents whether the current player can force a win with `i` stones.
- `dp[0] = false` because no move is possible.
- A state is winning if it has at least one move to a losing state.
- The available moves are all perfect squares:
  ```text
  1, 4, 9, 16, ...
  ```
- The solution runs in **O(n√n)** time and **O(n)** space.
- This is the standard DP solution for LeetCode 1510.
# Stone Game II

## Problem Statement

You are given an array:

```cpp
piles
```

where `piles[i]` represents the number of stones in the `i-th` pile.

Alice and Bob play a game:

- Alice starts first.
- At any turn, a player can take the next `X` piles.
- `X` can be any value from:
  ```text
  1 to 2M
  ```
- Initially:
  ```text
  M = 1
  ```
- After taking `X` piles:
  ```text
  M = max(M, X)
  ```
- The game continues until all piles are taken.
- Both players play optimally.

Return the maximum number of stones Alice can collect.

---

# Solution: Dynamic Programming + Suffix Sum

## Solution Overview

The important part of this problem is that the amount a player can take depends on the current value of:

```cpp
M
```

So we use a DP state:

```cpp
solve(i, M)
```

which represents the **maximum number of stones the current player can collect** starting from index `i` when the current limit is `M`.

The solution uses:

- **Suffix sums** to quickly calculate the total number of remaining stones.
- **Memoization** to avoid recalculating the same `(i, M)` state.

---

# DP State

Define:

```cpp
solve(i, M)
```

as:

> The maximum number of stones the current player can obtain from piles `i...n-1` when the current value of `M` is `M`.

---

# Step 1: Build Suffix Sum

Create:

```cpp
suffix
```

where:

```cpp
suffix[i]
```

stores the total number of stones from index `i` to the end.

For example:

```text
piles = [2, 7, 9, 4, 4]
```

The suffix sums are:

```text
suffix = [26, 24, 17, 8, 4, 0]
```

This lets us calculate the total remaining stones in:

```cpp
O(1)
```

time.

---

# Step 2: Base Case

If all piles have already been taken:

```cpp
if (i >= n)
    return 0;
```

There are no stones left.

---

# Step 3: Take All Remaining Piles

If:

```cpp
i + 2 * M >= n
```

the current player can take all remaining piles.

Therefore:

```cpp
return suffix[i];
```

This is an important optimization because there is no need to explore further choices.

---

# Step 4: Memoization

Before calculating a state, check whether it has already been computed:

```cpp
if (memo[i][M] != -1)
    return memo[i][M];
```

If so, return the stored result.

---

# Step 5: Try Every Possible Move

The current player can take:

```text
X = 1 ... 2M
```

piles.

For each choice:

```cpp
for (int X = 1; X <= 2 * M; X++)
```

the player takes:

```cpp
suffix[i] - suffix[i + X]
```

stones.

Instead of explicitly calculating that, the solution uses the score-difference idea:

```cpp
suffix[i] - solve(i + X, max(M, X))
```

---

# Why `suffix[i] - solve(...)` Works

Suppose there are:

```cpp
suffix[i]
```

total stones remaining.

After taking `X` piles, the opponent gets the remaining:

```cpp
suffix[i + X]
```

stones.

The opponent can optimally collect:

```cpp
solve(i + X, max(M, X))
```

from those remaining piles.

Therefore, the current player's maximum score is:

```text
Total remaining stones
− Opponent's maximum score
```

which gives:

```cpp
suffix[i] - solve(i + X, max(M, X))
```

We take the maximum over all possible `X`.

---

# Step 6: Store the Best Result

After considering every possible move:

```cpp
memo[i][M] = ans;
```

Return:

```cpp
ans;
```

---

# Example

Consider:

```text
piles = [2, 7, 9, 4, 4]
```

Initially:

```text
i = 0
M = 1
```

Alice can take only:

```text
X = 1 or 2
```

### If Alice takes 1 pile

She takes:

```text
2
```

The new state becomes:

```text
solve(1, 1)
```

### If Alice takes 2 piles

She takes:

```text
2 + 7 = 9
```

and:

```text
M = max(1, 2) = 2
```

The new state becomes:

```text
solve(2, 2)
```

The DP explores these possibilities and chooses the one that maximizes Alice's final score.

---

# Why This DP Works

At every state, the current player has complete control over how many piles to take.

For every possible:

```cpp
X
```

the opponent's optimal response is represented by:

```cpp
solve(i + X, max(M, X))
```

Therefore, considering all possible `X` guarantees that the optimal strategy is found.

Memoization ensures that each state is solved only once.

---

# Complexity Analysis

Let:

```cpp
n = piles.size()
```

There are approximately:

```text
O(n²)
```

possible `(i, M)` states.

For each state, up to:

```text
O(n)
```

choices may be considered.

### Time Complexity

```cpp
O(n³)
```

---

### Space Complexity

The memoization table contains:

```cpp
O(n²)
```

states.

The suffix array uses:

```cpp
O(n)
```

space.

Overall:

```cpp
O(n²)
```

---

# Notes

- Uses **top-down Dynamic Programming with memoization**.
- `solve(i, M)` represents the maximum stones the current player can collect from index `i`.
- `suffix[i]` gives the total number of remaining stones in `O(1)`.
- The transition:
  ```cpp
  suffix[i] - solve(i + X, max(M, X))
  ```
  accounts for the opponent's optimal strategy.
- The player can take between `1` and `2M` piles.
- If all remaining piles can be taken, the current player simply takes them all.
- This solution avoids brute-force recursion by caching previously solved states.
- Time complexity: **O(n³)**.
- Space complexity: **O(n²)**.
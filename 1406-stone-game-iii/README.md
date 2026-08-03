# Stone Game III

## Problem Statement

Alice and Bob are playing a game with an array:

```cpp
stoneValue
```

where:

```cpp
stoneValue[i]
```

represents the value of the `i-th` stone.

Rules:

- Alice moves first.
- On each turn, a player may take **1, 2, or 3 consecutive stones** from the beginning of the remaining array.
- The value of the taken stones is added to the player's score.
- Both players play optimally.

Return:

- `"Alice"` if Alice wins.
- `"Bob"` if Bob wins.
- `"Tie"` if both obtain the same score.

---

# Solution: Dynamic Programming (Score Difference)

## Solution Overview

Instead of computing Alice's and Bob's scores separately, this solution computes the **maximum score difference** the current player can achieve over the opponent.

Define:

```text
Score Difference = Current Player's Score − Opponent's Score
```

For every position:

- The current player may take 1, 2, or 3 stones.
- After taking those stones, the opponent becomes the current player for the remaining suffix.
- Since the opponent also plays optimally, subtract their best possible score difference.

Memoization ensures each state is computed only once.

---

## Dynamic Programming State

Let:

```cpp
solve(i)
```

represent the maximum score difference the current player can obtain starting from index:

```cpp
i
```

---

## Recursive Transition

Suppose the player takes:

- 1 stone
- 2 stones
- 3 stones

Let:

```cpp
sum
```

be the total value of the stones taken.

The opponent's optimal score difference is:

```cpp
solve(nextIndex)
```

Therefore, the current player's score difference becomes:

```cpp
sum - solve(nextIndex)
```

Take the maximum among all valid choices.

---

## Algorithm

### Step 1: Base Case

If all stones have been taken:

```cpp
if(i >= n)
    return 0;
```

No score difference remains.

---

### Step 2: Memoization

If the answer has already been computed:

```cpp
if(dp[i] != INT_MIN)
    return dp[i];
```

reuse it.

---

### Step 3: Try Taking 1–3 Stones

Maintain:

```cpp
sum = 0;
best = INT_MIN;
```

For:

```cpp
j = 1 to 3
```

- Stop if the array ends.
- Add the current stone:

```cpp
sum += stoneValue[i + j - 1];
```

Compute:

```cpp
best = max(best,
           sum - solve(i + j));
```

---

### Step 4: Store the Result

Save:

```cpp
dp[i] = best;
```

and return it.

---

### Step 5: Determine the Winner

Compute:

```cpp
diff = solve(0);
```

If:

```cpp
diff > 0
```

Alice scores more.

Return:

```cpp
"Alice"
```

If:

```cpp
diff < 0
```

Bob scores more.

Return:

```cpp
"Bob"
```

Otherwise:

```cpp
"Tie"
```

---

## Why This Works

At every turn, the current player wants to maximize the score difference.

If the player takes stones worth:

```cpp
sum
```

the opponent then plays optimally on the remaining stones and gains:

```cpp
solve(nextIndex)
```

Therefore, the net advantage is:

```cpp
sum - solve(nextIndex)
```

Considering all three possible moves guarantees the optimal strategy.

---

## Complexity Analysis

Let:

```cpp
n = stoneValue.size()
```

### Time Complexity

There are:

```cpp
n
```

DP states.

Each state considers at most:

```cpp
3
```

moves.

Overall:

```cpp
O(n)
```

---

### Space Complexity

Memoization array:

```cpp
O(n)
```

Recursion stack:

```cpp
O(n)
```

Overall:

```cpp
O(n)
```

---

## Notes

- Uses Dynamic Programming with memoization.
- `solve(i)` stores the maximum score difference the current player can achieve starting from index `i`.
- At each state, the player can take 1, 2, or 3 consecutive stones.
- The transition is:
  ```cpp
  sum - solve(nextIndex)
  ```
  because the opponent also plays optimally.
- The final score difference determines whether Alice wins, Bob wins, or the game ends in a tie.
- Runs in linear time and is the standard optimal solution for the problem.
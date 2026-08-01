# Predict the Winner

## Problem Statement

You are given an integer array:

```cpp
nums
```

Two players play a game by taking turns choosing either the **first** or the **last** number from the array.

- Player 1 moves first.
- Both players play optimally.
- The chosen number is added to the player's score.

Return:

```cpp
true
```

if Player 1 can achieve a score greater than or equal to Player 2's score; otherwise, return:

```cpp
false
```

---

# Solution: Dynamic Programming (Score Difference)

## Solution Overview

Instead of tracking the individual scores of both players, this solution tracks the **maximum score difference** that the current player can achieve over the opponent.

Key ideas:
- Let the DP state represent the best score difference for every subarray.
- At each turn, a player has two choices:
  - Take the leftmost number.
  - Take the rightmost number.
- Since the opponent also plays optimally, subtract the opponent's best possible score difference.
- The final score difference determines whether Player 1 can win.

Additionally, if the array length is even, Player 1 can always guarantee a win by choosing either all even-indexed or all odd-indexed elements, so the answer is immediately `true`.

---

## Dynamic Programming State

Define:

```cpp
dp[j]
```

as the maximum score difference the current player can achieve for the subarray:

```cpp
nums[i...j]
```

where:

```text
score(current player) − score(opponent)
```

Initially:

```cpp
dp[i] = nums[i];
```

because a single element is taken directly.

---

## Algorithm

### Step 1: Handle Even-Length Arrays

If the number of elements is even:

```cpp
if (n % 2 == 0)
    return true;
```

Player 1 can always force a win.

---

### Step 2: Initialize DP

Copy the array into:

```cpp
dp
```

Each element initially represents the score difference for a subarray of length 1.

---

### Step 3: Expand the Subarray

Process subarrays from smaller to larger.

Traverse:

```cpp
i = n - 2 ... 0
```

and for every:

```cpp
j = i + 1 ... n - 1
```

compute the best possible score difference.

---

### Step 4: Compute Two Choices

If the player picks the left element:

```cpp
nums[i] - dp[j]
```

because:

```cpp
dp[j]
```

is the opponent's best score difference for:

```cpp
nums[i+1...j]
```

If the player picks the right element:

```cpp
nums[j] - dp[j - 1]
```

Take the better choice:

```cpp
dp[j] = max(nums[i] - dp[j],
            nums[j] - dp[j - 1]);
```

---

### Step 5: Determine the Winner

After filling the DP:

```cpp
dp[n - 1]
```

contains the maximum score difference Player 1 can achieve.

If:

```cpp
dp[n - 1] >= 0
```

Player 1 can tie or win.

Return:

```cpp
true;
```

Otherwise:

```cpp
false;
```

---

## Why the Transition Works

For a subarray:

```text
[i ... j]
```

Player 1 has two choices.

Take the left element:

```text
nums[i]
```

The opponent then plays optimally on:

```text
[i+1 ... j]
```

whose advantage is:

```cpp
dp[j]
```

Therefore the resulting score difference is:

```cpp
nums[i] - dp[j]
```

Similarly, taking the right element gives:

```cpp
nums[j] - dp[j-1]
```

Choosing the larger value guarantees the best possible outcome.

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

The DP processes every subarray once.

```cpp
O(n²)
```

---

### Space Complexity

Only a one-dimensional DP array is used.

```cpp
O(n)
```

---

## Notes

- Uses Dynamic Programming based on score difference instead of individual scores.
- `dp[j]` stores the maximum score difference for the current subarray.
- At each step, the player chooses the better of taking the leftmost or rightmost element.
- Uses a 1D DP array to optimize space from `O(n²)` to `O(n)`.
- Immediately returns `true` for even-length arrays because Player 1 has a guaranteed winning strategy.
- This is the standard optimal solution for the problem.
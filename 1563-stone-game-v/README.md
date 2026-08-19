# Stone Game V

## Problem Statement

You are given an array:

```cpp
stoneValue
```

Alice and Bob play a game.

On each turn:

1. The current array is divided at some position into two non-empty parts.
2. Compare the sum of the left part and the right part.
3. The player keeps the part with the **smaller sum**.
4. If both sums are equal, the player can choose either part.
5. The player earns the sum of the part they keep.
6. The game continues until only one stone remains.

Alice plays first, and both players play optimally.

Return the maximum score Alice can obtain.

---

# Solution: Dynamic Programming + Prefix Sums + Two Pointers

## Solution Overview

The natural DP is:

```cpp
dp[l][r]
```

which represents the maximum score the current player can obtain from the subarray:

```text
[l ... r]
```

The difficulty is that for every possible split:

```text
[l ... k] | [k+1 ... r]
```

we need to compare the two sums.

A straightforward implementation checks every `k`, giving:

```text
O(n³)
```

This solution optimizes that using:

- **Prefix sums** for `O(1)` range-sum queries.
- **Two pointers** to find the useful split positions.
- `leftBest` and `rightBest` to retrieve the best DP value over ranges efficiently.

This reduces the solution to approximately:

```text
O(n²)
```

---

# Step 1: Prefix Sum

Create:

```cpp
prefix
```

where:

```cpp
prefix[i]
```

stores the sum of the first `i` elements.

Therefore, the sum of:

```text
stoneValue[l ... r]
```

is:

```cpp
prefix[r + 1] - prefix[l]
```

For example:

```text
stoneValue = [6, 2, 3, 4]
```

The prefix array is:

```text
[0, 6, 8, 11, 15]
```

So the sum from index `1` to `3` is:

```text
prefix[4] - prefix[1]
= 15 - 6
= 9
```

---

# Step 2: DP State

Define:

```cpp
dp[l][r]
```

as:

> The maximum score the current player can obtain from the subarray `[l, r]`.

For a split at `k`:

```text
[l ... k] | [k+1 ... r]
```

let:

```text
leftSum  = sum(l, k)
rightSum = sum(k+1, r)
```

There are three possibilities.

---

# Case 1: Left Sum < Right Sum

If:

```text
leftSum < rightSum
```

the player must keep the left part.

The score gained is:

```text
leftSum
```

and the game continues on:

```text
[l, k]
```

Therefore:

```text
candidate = leftSum + dp[l][k]
```

---

# Case 2: Right Sum < Left Sum

If:

```text
rightSum < leftSum
```

the player must keep the right part.

The score gained is:

```text
rightSum
```

and the game continues on:

```text
[k+1, r]
```

Therefore:

```text
candidate = rightSum + dp[k+1][r]
```

---

# Case 3: Both Sums Are Equal

If:

```text
leftSum == rightSum
```

the player may choose either side.

So we can take:

```text
max(
    leftSum + dp[l][k],
    rightSum + dp[k+1][r]
)
```

Since the sums are equal, this becomes choosing the better DP result.

---

# The Main Difficulty

A direct implementation would do:

```cpp
for every l
    for every r
        for every k
```

which results in:

```text
O(n³)
```

The provided solution avoids this.

---

# Step 3: Find Useful Split Positions

For a fixed interval `[l, r]`, let:

```cpp
total = sum(l, r)
```

For a split at `k`:

```cpp
leftSum = sum(l, k)
rightSum = total - leftSum
```

The condition:

```text
leftSum <= rightSum
```

is equivalent to:

```text
2 * leftSum <= total
```

The condition:

```text
leftSum < rightSum
```

is equivalent to:

```text
2 * leftSum < total
```

This means we can locate the boundary where the left side becomes larger using a pointer instead of checking every split independently.

---

# `leftPtr`

The code maintains:

```cpp
leftPtr[l]
```

which tracks the largest split position satisfying:

```text
2 * leftSum <= total
```

The loop:

```cpp
while (leftPtr[l] + 1 <= r - 1) {
    int k = leftPtr[l] + 1;
    long long leftSum = prefix[k + 1] - prefix[l];

    if (2 * leftSum > total)
        break;

    ++leftPtr[l];
}
```

moves the pointer forward while the left side is not larger than the right side.

This identifies the region where the left part can be selected.

---

# `rightPtr`

Similarly:

```cpp
rightPtr[l]
```

tracks the first position where:

```text
leftSum >= rightSum
```

The condition is:

```cpp
2 * leftSum >= total
```

The loop:

```cpp
while (rightPtr[l] <= r - 1) {
    int k = rightPtr[l];

    long long leftSum =
        prefix[k + 1] - prefix[l];

    if (2 * leftSum >= total)
        break;

    ++rightPtr[l];
}
```

moves the pointer until the left side becomes at least as large as the right side.

This handles the region where the right side can be selected.

---

# Step 4: Why `leftBest` and `rightBest` Are Needed

Even after finding the valid split range, we don't want to iterate over every split.

So the solution maintains:

```cpp
leftBest
```

and:

```cpp
rightBest
```

These arrays store accumulated best values.

---

## `leftBest`

```cpp
leftBest[l][r]
```

stores the maximum value of:

```text
dp[l][k] + sum(l, k)
```

over the relevant split positions `k` in `[l, r]`.

This allows us to obtain the best left-side transition in:

```text
O(1)
```

time.

---

## `rightBest`

Similarly:

```cpp
rightBest[l][r]
```

stores the maximum value of:

```text
dp[k][r] + sum(k, r)
```

over the appropriate right-side split positions.

This allows the best right-side transition to also be obtained in:

```text
O(1)
```

time.

---

# Step 5: Calculate `dp[l][r]`

The solution starts with:

```cpp
int best = 0;
```

If a valid left-side split exists:

```cpp
if (leftPtr[l] >= l) {
    best = leftBest[l][leftPtr[l]];
}
```

Then it checks the right-side possibility:

```cpp
if (rightPtr[l] <= r - 1) {
    best = max(
        best,
        rightBest[rightPtr[l] + 1][r]
    );
}
```

Therefore:

```cpp
dp[l][r] = best;
```

---

# Step 6: Update the Helper Tables

After computing:

```cpp
dp[l][r]
```

we update `leftBest`:

```cpp
leftBest[l][r] = max(
    leftBest[l][r - 1],
    dp[l][r] + total
);
```

This carries forward the best left-side value.

Similarly:

```cpp
rightBest[l][r] = max(
    rightBest[l + 1][r],
    dp[l][r] + total
);
```

stores the best right-side value.

---

# Why the Two-Pointer Optimization Works

All values in `stoneValue` are positive.

Therefore, as the split point moves from left to right:

```text
leftSum increases
```

and:

```text
rightSum decreases
```

So the condition:

```text
leftSum <= rightSum
```

changes only once.

This monotonicity allows `leftPtr` and `rightPtr` to move forward instead of scanning all split points repeatedly.

That is the key optimization that reduces the complexity from:

```text
O(n³)
```

to:

```text
O(n²)
```

---

# DP Order

The code processes:

```cpp
len = 2 ... n
```

so shorter intervals are solved before longer intervals.

For example:

```text
length 2
   ↓
length 3
   ↓
length 4
   ↓
...
length n
```

This guarantees that when calculating:

```cpp
dp[l][r]
```

all required smaller subproblems are already available.

---

# Example

Consider:

```text
stoneValue = [6, 2, 3, 4]
```

For the full interval:

```text
[6, 2, 3, 4]
```

possible splits include:

```text
[6] | [2,3,4]
6   | 9
```

The left side has the smaller sum, so Alice keeps:

```text
[6]
```

and earns:

```text
6
```

Another split:

```text
[6,2] | [3,4]
8     | 7
```

The right side has the smaller sum, so the player keeps:

```text
[3,4]
```

and earns:

```text
7
```

The DP evaluates these possibilities and chooses the move that maximizes the eventual score.

---

# Complexity Analysis

Let:

```cpp
n = stoneValue.size()
```

### Prefix Sum

Building the prefix array:

```text
O(n)
```

### DP

There are:

```text
O(n²)
```

intervals.

The two pointers move monotonically, allowing the split positions to be processed efficiently.

Therefore the overall DP complexity is:

```text
O(n²)
```

### Space Complexity

The solution uses:

```cpp
prefix   → O(n)
dp       → O(n²)
leftBest → O(n²)
rightBest → O(n²)
```

Therefore:

```text
O(n²)
```

space.

---

# Notes

- Uses **Dynamic Programming + Prefix Sums + Two Pointers**.
- `dp[l][r]` represents the maximum score obtainable from interval `[l, r]`.
- Prefix sums make range-sum calculations `O(1)`.
- Because all stone values are positive, left sums increase monotonically as the split moves right.
- `leftPtr` finds the region where the left side is smaller or equal.
- `rightPtr` finds the region where the right side is smaller or equal.
- `leftBest` and `rightBest` avoid scanning every possible split.
- The naive DP is `O(n³)`, while this optimized solution achieves **O(n²)**.
- Space complexity is **O(n²)**.
- This is an optimized solution for LeetCode 1563.
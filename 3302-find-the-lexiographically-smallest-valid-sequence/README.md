# Find the Lexicographically Smallest Valid Sequence

## Problem Statement

You are given two strings:

```cpp
word1
word2
```

Find the **lexicographically smallest sequence of indices** of length `m = word2.length()` such that:

- The selected indices are strictly increasing.
- The characters at those indices form `word2`.
- At most **one character** can be different from the corresponding character in `word2`.

In other words, we need to select indices:

```text
i0 < i1 < i2 < ... < i(m-1)
```

such that:

```text
word1[i0...i(m-1)]
```

matches `word2` with at most one mismatch.

If no such sequence exists, return an empty vector.

---

# Solution: Greedy + Suffix Matching

## Solution Overview

The key challenge is deciding **where to use the one allowed mismatch**.

A greedy approach can match characters from left to right, but we need to know whether choosing a mismatch now will still allow the remaining characters of `word2` to be matched.

To solve this, the algorithm preprocesses the string from **right to left**.

Key ideas:

1. Build `last[j]`, storing the latest position in `word1` where `word2[j]` can be matched while preserving the suffix.
2. Scan `word1` from left to right.
3. Always take an exact match when possible.
4. If the current character does not match, use the one allowed mismatch only if the remaining suffix can still be matched.
5. Since indices are considered from left to right, the first valid sequence found is lexicographically smallest.

---

# Step 1: Build the `last` Array

Create:

```cpp
vector<int> last(m, -1);
```

`last[j]` represents the position in `word1` that can match:

```cpp
word2[j]
```

while still allowing the remaining characters of `word2` to be matched afterward.

Traverse both strings from the end:

```cpp
int i = n - 1;
int j = m - 1;
```

Whenever:

```cpp
word1[i] == word2[j]
```

store:

```cpp
last[j] = i;
```

and move to the previous character of `word2`.

This gives us information about whether the suffix can still be completed.

---

# Step 2: Greedily Build the Answer

Start from the beginning:

```cpp
j = 0;
```

where `j` represents the current position in `word2`.

For every position:

```cpp
i
```

in `word1`, there are two possibilities.

---

## Case 1: Exact Match

If:

```cpp
word1[i] == word2[j]
```

we take the current index:

```cpp
ans[j] = i;
j++;
```

This is always the best choice because we want the lexicographically smallest sequence of indices.

---

## Case 2: Use the One Allowed Mismatch

If the characters don't match, we can use our one allowed mismatch.

But we cannot blindly use it.

We must ensure that the remaining part of `word2` can still be matched.

The condition is:

```cpp
j == m - 1 || i < last[j + 1]
```

### Why?

If:

```cpp
j == m - 1
```

we are matching the last character of `word2`, so there is no suffix left to worry about.

Otherwise, we need:

```cpp
i < last[j + 1]
```

which guarantees that the remaining characters can be matched at positions after `i`.

If this condition holds:

```cpp
ans[j] = i;
j++;
used = true;
```

The mismatch is now consumed.

---

# Step 3: Check Whether a Complete Sequence Was Found

If:

```cpp
j == m
```

all characters of `word2` have been matched.

Return:

```cpp
ans;
```

Otherwise, no valid sequence exists:

```cpp
return {};
```

---

# Why the Greedy Approach Works

The goal is to obtain the **lexicographically smallest sequence of indices**.

Therefore, at every position we want to choose the smallest possible index.

The algorithm processes `word1` from left to right, so the first feasible index encountered is the smallest possible index.

However, using the mismatch too early can make the remaining suffix impossible.

The `last` array solves this problem by telling us whether the rest of `word2` can still be matched after the current position.

Therefore:

- Exact matches are always preferred.
- A mismatch is used only when it is safe.
- The earliest feasible index is always selected.

This gives the lexicographically smallest valid sequence.

---

# Example

Consider:

```text
word1 = "abcde"
word2 = "abd"
```

We need three indices whose characters match `"abd"` with at most one mismatch.

The algorithm tries to match:

```text
a → b → d
```

The first two characters can be matched exactly:

```text
a = word1[0]
b = word1[1]
```

For the final character:

```text
e ≠ d
```

but this is the final character, so the mismatch can safely be used.

Result:

```text
[0, 1, 4]
```

---

# Complexity Analysis

Let:

```cpp
n = word1.length()
m = word2.length()
```

### Time Complexity

Building the `last` array:

```cpp
O(n)
```

Greedy scan:

```cpp
O(n)
```

Overall:

```cpp
O(n)
```

---

### Space Complexity

The `last` array:

```cpp
O(m)
```

The answer:

```cpp
O(m)
```

Overall:

```cpp
O(m)
```

---

# Notes

- Uses a **greedy + suffix feasibility** approach.
- The `last` array allows the algorithm to determine whether using the one mismatch is safe.
- Exact matches are always preferred.
- The mismatch is used at most once.
- Processing indices from left to right guarantees the lexicographically smallest valid sequence.
- No backtracking or exponential search is required.
- Runs in **O(n)** time and **O(m)** extra space.
- This is the standard optimal approach for LeetCode 3302.
# Maximum Length Substring With Two Occurrences

## Problem Statement

You are given a string:

```cpp
s
```

Find the length of the **longest substring** such that every character appears at most **two times**.

Return the maximum possible length.

---

# Solution: Sliding Window + Hash Map

## Solution Overview

This problem can be solved efficiently using a **Sliding Window**.

Maintain a window:

```text
[i ... j]
```

where every character occurs at most twice.

We use:

```cpp
unordered_map<int, int> m;
```

to store the frequency of each character inside the current window.

For every new character:

1. Add it to the window.
2. Increase its frequency.
3. If its frequency becomes greater than `2`, shrink the window from the left.
4. Once the window becomes valid again, update the maximum length.

---

# Step 1: Initialize the Window

```cpp
int i = 0;
int j = 0;
int ans = 0;
```

Here:

- `i` = left boundary.
- `j` = right boundary.
- `ans` = longest valid substring found so far.

The map:

```cpp
m
```

stores character frequencies inside the current window.

---

# Step 2: Expand the Window

For every position `j`:

```cpp
m[s[j]]++;
```

This adds:

```cpp
s[j]
```

to the current window.

---

# Step 3: Check Whether the Window Is Invalid

Every character is allowed to occur at most:

```text
2 times
```

Therefore, if:

```cpp
m[s[j]] > 2
```

the newly added character appears too many times.

The current window is invalid.

---

# Step 4: Shrink the Window

Move the left pointer forward:

```cpp
while (m[s[j]] > 2) {
    m[s[i]]--;
    i++;
}
```

Each time `i` moves, the character leaving the window has its frequency decreased.

Continue until:

```cpp
m[s[j]] <= 2
```

At this point, the window is valid again.

---

# Why We Only Check `m[s[j]]`

Before adding:

```cpp
s[j]
```

the current window was already valid.

Therefore, every character already inside the window occurred at most twice.

The only character whose frequency could have become `3` is the newly added:

```cpp
s[j]
```

So checking:

```cpp
m[s[j]] > 2
```

is sufficient.

---

# Step 5: Update the Answer

Once the window is valid:

```cpp
ans = max(ans, j - i + 1);
```

The current window length is:

```text
j - i + 1
```

---

# Example

Consider:

```text
s = "bcbbbcba"
```

Suppose the current window reaches:

```text
"bcbbb"
```

The frequency of `'b'` becomes:

```text
4
```

which is invalid.

So we move `i` forward while decreasing frequencies until `'b'` occurs at most twice.

Once the window becomes valid, we calculate its length and compare it with `ans`.

---

# Why Sliding Window Works

The condition:

```text
Every character occurs at most twice
```

is suitable for sliding window.

When adding a new character makes the window invalid, making the window larger cannot fix the problem.

We must remove characters from the left.

Therefore:

```text
expand right → invalid → shrink left → valid
```

allows us to efficiently consider all useful windows.

---

# Complexity Analysis

Let:

```cpp
n = s.length()
```

### Time Complexity

The right pointer:

```cpp
j
```

moves through the string once.

The left pointer:

```cpp
i
```

also moves through the string at most once.

Therefore:

```text
O(n)
```

on average.

---

### Space Complexity

The map stores character frequencies.

Since the string contains lowercase English letters, at most 26 entries are needed:

```text
O(26) = O(1)
```

---

# Notes

- Uses the **Sliding Window** technique.
- `i` represents the left boundary and `j` represents the right boundary.
- The frequency map tracks characters in the current window.
- If the newly added character occurs more than twice, the window is shrunk.
- `j - i + 1` gives the current valid substring length.
- Both pointers only move forward.
- Time complexity: **O(n)**.
- Space complexity: **O(1)** for the fixed lowercase alphabet.
- This is the standard optimal approach for LeetCode 3090.
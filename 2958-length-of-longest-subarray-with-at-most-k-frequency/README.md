# Maximum Subarray With Bounded Frequency

## Problem Statement

You are given an integer array:

```cpp
nums
```

and an integer:

```cpp
k
```

Find the length of the **longest contiguous subarray** in which every number appears at most `k` times.

---

# Solution: Sliding Window + Hash Map

## Solution Overview

We use the **Sliding Window** technique.

Maintain a window:

```text
[i ... j]
```

where:

- `i` is the left boundary.
- `j` is the right boundary.
- `m[x]` stores how many times `x` appears inside the current window.

As we move `j` forward, we add:

```cpp
nums[j]
```

to the window.

If its frequency becomes greater than `k`, the current window is invalid.

So we move `i` forward and remove elements until the window becomes valid again.

---

## Step 1: Initialize

```cpp
unordered_map<int,int> m;

int i = 0;
int j = 0;
int ans = 0;
```

Here:

```cpp
i
```

is the left side of the window and:

```cpp
j
```

is the right side.

---

## Step 2: Expand the Window

For every `j`:

```cpp
m[nums[j]]++;
```

We add the new element to the window.

---

## Step 3: Shrink When Invalid

If:

```cpp
m[nums[j]] > k
```

then the number `nums[j]` appears too many times.

The window is invalid.

So we remove elements from the left:

```cpp
while(m[nums[j]] > k) {
    m[nums[i]]--;
    i++;
}
```

We continue until:

```cpp
m[nums[j]] <= k
```

Again, the window is valid.

---

## Step 4: Update the Maximum

Once the window is valid:

```cpp
ans = max(ans, j - i + 1);
```

The current window length is:

```text
j - i + 1
```

We keep the largest one.

---

# Example

Consider:

```text
nums = [1, 2, 1, 2, 1]
k = 2
```

Initially:

```text
window = [1]
```

Then:

```text
[1, 2]
[1, 2, 1]
[1, 2, 1, 2]
```

This window is valid because both `1` and `2` appear at most twice.

When we add another `1`:

```text
[1, 2, 1, 2, 1]
```

the frequency of `1` becomes:

```text
3
```

which is greater than `k = 2`.

So we move the left pointer forward:

```text
remove 1
```

and the window becomes:

```text
[2, 1, 2, 1]
```

Now every element appears at most twice again.

---

# Why Sliding Window Works

The important property is:

> If a window becomes invalid because some number occurs more than `k` times, moving the left pointer forward can only decrease frequencies.

Therefore, once the window becomes invalid, we don't need to restart from scratch.

We simply shrink it until it becomes valid again.

This allows both pointers to move only forward.

---

# Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

Each element:

- enters the window once.
- leaves the window at most once.

Therefore:

```text
O(n)
```

on average, because `unordered_map` operations are `O(1)` average.

---

### Space Complexity

The hash map can contain up to `n` different values:

```text
O(n)
```

---

## Notes

- Uses **Sliding Window + Hash Map**.
- `i` represents the left boundary.
- `j` represents the right boundary.
- The hash map stores frequencies inside the current window.
- If a frequency exceeds `k`, shrink the window from the left.
- Once valid, update the maximum window length.
- Time complexity: **O(n)** average.
- Space complexity: **O(n)**.
- This is the standard optimal approach for LeetCode 2958.
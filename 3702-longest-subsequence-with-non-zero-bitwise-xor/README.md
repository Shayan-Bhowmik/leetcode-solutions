# Longest Subsequence With Non-Zero XOR

## Problem Statement

You are given an integer array:

```cpp
nums
```

Find the length of the **longest subsequence** whose bitwise XOR is **not equal to `0`**.

Return the maximum possible length.

---

# Solution: XOR Observation

## Solution Overview

The key observation is that we don't actually need Dynamic Programming or subsequence generation.

There are only three cases:

1. XOR of the entire array is non-zero.
2. XOR of the entire array is zero, but at least one element is non-zero.
3. Every element is zero.

We can solve the problem by calculating the XOR of all elements.

---

# Case 1: Total XOR Is Non-Zero

Suppose:

```cpp
xr != 0
```

Then the XOR of the entire array is already non-zero.

Therefore, we can simply take **all `n` elements**.

So:

```cpp
return n;
```

This is obviously the longest possible subsequence because no subsequence can contain more than `n` elements.

---

# Case 2: Total XOR Is Zero but There Is a Non-Zero Element

Suppose:

```cpp
xr == 0
```

but at least one element is non-zero.

The entire array cannot be used because its XOR is:

```text
0
```

Now remove any one **non-zero** element.

Let the XOR of the entire array be:

```text
A = 0
```

If we remove an element `x`, the XOR of the remaining elements becomes:

```text
A XOR x
```

Since:

```text
A = 0
```

we get:

```text
0 XOR x = x
```

Because `x` is non-zero, the resulting XOR is also non-zero.

Therefore, we can always construct a valid subsequence containing:

```text
n - 1
```

elements.

So:

```cpp
return n - 1;
```

---

# Case 3: All Elements Are Zero

If:

```cpp
xr == 0
```

and there is no non-zero element, then every element is:

```text
0
```

Any subsequence will also have XOR:

```text
0
```

Therefore, no valid non-empty subsequence exists.

Return:

```cpp
return 0;
```

---

# Algorithm

### Step 1: Calculate the XOR

```cpp
int xr = 0;

for (int x : nums) {
    xr ^= x;
}
```

---

### Step 2: Check Whether a Non-Zero Element Exists

During the same traversal:

```cpp
if (x != 0)
    hasNonZero = true;
```

This avoids another pass through the array.

---

### Step 3: Determine the Answer

If:

```cpp
xr != 0
```

return:

```cpp
n;
```

Otherwise, if:

```cpp
hasNonZero
```

return:

```cpp
n - 1;
```

Otherwise return:

```cpp
0;
```

---

# Example 1

```text
nums = [1, 2, 3]
```

Total XOR:

```text
1 XOR 2 XOR 3 = 0
```

But there are non-zero elements.

Remove `3`:

```text
[1, 2]
```

XOR:

```text
1 XOR 2 = 3
```

which is non-zero.

Therefore:

```text
answer = 3 - 1 = 2
```

---

# Example 2

```text
nums = [1, 2, 4]
```

XOR:

```text
1 XOR 2 XOR 4 = 7
```

Since the XOR is already non-zero, use the entire array.

```text
answer = 3
```

---

# Example 3

```text
nums = [0, 0, 0]
```

Every subsequence has XOR `0`.

Therefore:

```text
answer = 0
```

---

# Why This Works

The entire array is always the longest possible subsequence.

- If its XOR is non-zero, we're done.
- If its XOR is zero and there is a non-zero element, removing one non-zero element changes the XOR from `0` to that non-zero value.
- If every element is zero, no valid subsequence exists.

Thus, there is never a need to search through different subsequences.

---

# Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

We traverse the array once:

```text
O(n)
```

### Space Complexity

Only a few variables are used:

```text
O(1)
```

---

## Notes

- Uses the properties of **bitwise XOR** rather than explicitly generating subsequences.
- If total XOR is non-zero → take all `n` elements.
- If total XOR is zero but a non-zero element exists → remove one non-zero element and take `n - 1`.
- If all elements are zero → answer is `0`.
- Time complexity: **O(n)**.
- Space complexity: **O(1)**.
- This is the optimal solution for LeetCode 3702.
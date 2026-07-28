# Find the Number of Unique XOR Triplets

## Problem Statement

You are given an integer array:

```cpp
nums
```

Return the number of distinct values that can be obtained by taking the XOR of any triplet of elements from the array.

A triplet may contain repeated indices if allowed by the problem constraints.

---

# Solution: Mathematical Observation

## Solution Overview

This solution is based on a mathematical property of XOR values.

Key ideas:
- If the array contains only one or two elements, the number of distinct XOR triplets is simply the number of available elements.
- For larger arrays, every possible XOR value in the range determined by the smallest power of two greater than `n` can be formed.
- Therefore, the answer is the smallest power of two strictly greater than the size of the array.

This eliminates the need to explicitly generate or examine all triplets.

---

## Algorithm

### Step 1: Handle Small Arrays

If the array contains at most two elements:

```cpp
if (n <= 2)
    return n;
```

the number of distinct XOR triplets equals the number of elements.

---

### Step 2: Find the Smallest Power of Two

Initialize:

```cpp
ans = 1;
```

Repeatedly double it until:

```cpp
ans > n
```

using:

```cpp
while (ans <= n)
    ans <<= 1;
```

This computes the smallest power of two greater than:

```cpp
n
```

---

### Step 3: Return the Answer

Return:

```cpp
ans;
```

---

## Why This Works

For sufficiently large arrays, the XOR operation can generate every value within a complete binary range.

The number of distinct XOR values therefore becomes the size of that range, which is the smallest power of two greater than the number of elements.

Instead of checking all possible triplets, the answer follows directly from this mathematical observation.

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

The loop doubles the value until it exceeds `n`.

```cpp
O(log n)
```

---

### Space Complexity

Only a few integer variables are used.

```cpp
O(1)
```

---

## Notes

- Relies on a mathematical property of XOR triplets.
- Handles arrays of size `1` and `2` as special cases.
- Computes the smallest power of two greater than `n`.
- Avoids generating all possible triplets.
- Requires constant extra space.
- Runs in `O(log n)` time.
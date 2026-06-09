# Maximize Total Value of Selected Elements

## Problem Statement

Given an integer array `nums` and an integer `k`, determine the maximum total value that can be obtained after performing the operation exactly `k` times.

The value contributed by each operation is the difference between the maximum and minimum element in the array.

Return the maximum total value.

---

# Solution: Maximum-Minimum Difference

## Solution Overview

This solution observes that the maximum contribution from a single operation is determined by:

```cpp
maximum element - minimum element
```

Key ideas:
- Find the largest element in the array.
- Find the smallest element in the array.
- Compute their difference.
- Since the same maximum contribution can be obtained in each of the `k` operations, multiply the difference by `k`.

This directly gives the maximum total value.

---

## Algorithm

### Step 1: Find Maximum Element

Initialize:

```cpp
maxElement = 0
```

Traverse the array:

```cpp
maxElement = max(maxElement, nums[i]);
```

---

### Step 2: Find Minimum Element

Initialize:

```cpp
minElement = INT_MAX
```

Traverse the array:

```cpp
minElement = min(minElement, nums[i]);
```

---

### Step 3: Compute Difference

Calculate:

```cpp
subElement = maxElement - minElement;
```

---

### Step 4: Multiply by k

Return:

```cpp
subElement * k
```

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

```cpp
O(n)
```

The array is traversed to find the minimum and maximum elements.

---

### Space Complexity

```cpp
O(1)
```

Only a few extra variables are used.

---

## Notes

- The maximum value is obtained using the largest and smallest elements.
- Uses two linear scans to determine the extrema.
- Multiplication by `k` accounts for performing the operation exactly `k` times.
- Efficient constant-space solution.
- Handles large answers using `long long`.
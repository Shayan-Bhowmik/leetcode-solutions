# Maximize Total Value After K Operations

## Problem Statement

Given an integer array `nums` and an integer `k`, perform at most `k` operations to maximize the total value obtained.

For a subarray, its value is defined as:

```cpp
max(subarray) - min(subarray)
```

In each operation:
- Choose a valid subarray.
- Add its value to the answer.
- Shorten the chosen range according to the problem rules.

Return the maximum total value obtainable after performing the operations.

---

# Solution: Sparse Table + Priority Queue

## Solution Overview

This solution combines:

- **Sparse Table** for fast range minimum and maximum queries.
- **Max Heap (Priority Queue)** for always selecting the currently best interval.

Key ideas:
- A subarray value depends on:
  ```cpp
  maximum element - minimum element
  ```
- Sparse Table allows answering:
  ```cpp
  range maximum
  range minimum
  ```
  in `O(1)` time.
- A max heap stores intervals ordered by their current value.
- Repeatedly extract the interval with the highest value.
- Add its contribution to the answer.
- Shrink the interval and insert the updated interval back into the heap.

This greedy strategy ensures the highest available value is chosen first.

---

## Data Structure 1: Sparse Table

### Purpose

Efficiently compute:

```cpp
max(nums[l...r])
```

and

```cpp
min(nums[l...r])
```

for any range.

---

### Preprocessing

For every power of two:

```cpp
2^i
```

store:

```cpp
Min[i][j]
Max[i][j]
```

where:

```cpp
Min[i][j]
```

is the minimum value in:

```cpp
[j, j + 2^i)
```

and

```cpp
Max[i][j]
```

is the maximum value in the same interval.

---

### Range Query

For a range:

```cpp
[left, right)
```

choose:

```cpp
k = floor(log2(length))
```

and combine two overlapping blocks:

```cpp
max(Max[k][left],
    Max[k][right - (1 << k)])
```

```cpp
min(Min[k][left],
    Min[k][right - (1 << k)])
```

Return:

```cpp
maximum - minimum
```

---

## Data Structure 2: Priority Queue

Store:

```cpp
(value, left, right)
```

where:

- `value`
  = current subarray value
- `left`
  = interval start
- `right`
  = interval end

The heap always keeps the largest value on top.

---

## Algorithm

### Step 1: Build Sparse Table

Precompute all range minimum and maximum values.

---

### Step 2: Initialize Heap

For every starting index:

```cpp
i
```

insert:

```cpp
(LUT.query(i, n), i, n)
```

representing:

```cpp
[i, n)
```

---

### Step 3: Perform K Operations

While:

```cpp
k > 0
```

and the largest value is non-zero:

1. Extract the interval with maximum value.
2. Add its value to the result.
3. Shrink the interval:

```cpp
[l, r)
→
[l, r - 1)
```

4. Compute the new value.
5. Insert the updated interval back into the heap.

---

### Step 4: Return Answer

Return:

```cpp
res
```

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

---

### Sparse Table Construction

```cpp
O(n log n)
```

---

### Range Queries

```cpp
O(1)
```

per query.

---

### Heap Operations

Each operation performs:

```cpp
push + pop
```

which costs:

```cpp
O(log n)
```

For `k` operations:

```cpp
O(k log n)
```

---

### Total Complexity

```cpp
O(n log n + k log n)
```

---

### Space Complexity

Sparse Table:

```cpp
O(n log n)
```

Priority Queue:

```cpp
O(n)
```

Total:

```cpp
O(n log n)
```

---

## Notes

- Sparse Table enables constant-time range minimum and maximum queries.
- Priority Queue always selects the interval with the largest contribution.
- Greedy extraction maximizes the accumulated value.
- Range values are computed as:
  ```cpp
  max(subarray) - min(subarray)
  ```
- Efficient for large arrays and large values of `k`.
- Significantly faster than recomputing minima and maxima for every interval.
- Combines two classic competitive programming techniques:
  - Sparse Table
  - Max Heap (Priority Queue)
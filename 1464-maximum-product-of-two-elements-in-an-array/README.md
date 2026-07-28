# Maximum Product of Two Elements in an Array

## Problem Statement

Given an integer array:

```cpp
nums
```

choose two different indices:

```cpp
i
```

and

```cpp
j
```

such that the value of:

```cpp
(nums[i] - 1) * (nums[j] - 1)
```

is maximized.

Return the maximum possible value.

---

# Solution: Single Pass Maximum Tracking

## Solution Overview

This solution finds the two largest elements in the array using a single traversal.

Key ideas:
- Maintain the largest and second largest elements seen so far.
- Update these values while iterating through the array.
- After the traversal, compute:
  ```cpp
  (first - 1) * (second - 1)
  ```
- This produces the maximum possible product.

Since the array is scanned only once, the solution is both efficient and uses constant extra space.

---

## Algorithm

### Step 1: Initialize Variables

Maintain two variables:

```cpp
first = 0;
second = 0;
```

where:

- `first` stores the largest element.
- `second` stores the second largest element.

---

### Step 2: Traverse the Array

For every element:

```cpp
num
```

check whether it is larger than the current maximum.

If:

```cpp
num >= first
```

update both values:

```cpp
second = first;
first = num;
```

Otherwise, if:

```cpp
num > second
```

update:

```cpp
second = num;
```

---

### Step 3: Compute the Product

After finding the two largest elements, calculate:

```cpp
(first - 1) * (second - 1);
```

---

### Step 4: Return the Answer

Return the computed product.

---

## Why This Works

The expression:

```cpp
(nums[i] - 1) * (nums[j] - 1)
```

is maximized when the two largest elements of the array are chosen.

By maintaining the largest and second largest elements during a single traversal, the algorithm guarantees the optimal pair without sorting the array.

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

Each element is processed exactly once.

```cpp
O(n)
```

---

### Space Complexity

Only two integer variables are maintained.

```cpp
O(1)
```

---

## Notes

- Uses a single-pass greedy approach.
- Maintains the largest and second largest elements throughout the traversal.
- Avoids sorting, improving efficiency to linear time.
- Requires constant extra space.
- Computes the final answer using:
  ```cpp
  (first - 1) * (second - 1)
  ```
- This is the standard optimal solution for the problem.
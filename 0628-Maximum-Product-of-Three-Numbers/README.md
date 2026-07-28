# Maximum Product of Three Numbers

## Problem Statement

Given an integer array:

```cpp
nums
```

return the maximum product that can be obtained by multiplying any three numbers from the array.

---

# Solution: Single Pass Tracking of Largest and Smallest Numbers

## Solution Overview

This solution finds:
- The three largest numbers in the array.
- The two smallest numbers in the array.

The maximum product can come from one of two possibilities:
- The product of the three largest numbers.
- The product of the largest number and the two smallest (most negative) numbers.

After processing the array once, compute both products and return the larger one.

---

## Algorithm

### Step 1: Initialize Variables

Maintain:

```cpp
max1, max2, max3
```

to store the three largest numbers.

Maintain:

```cpp
min1, min2
```

to store the two smallest numbers.

Initially:

```cpp
max1 = max2 = max3 = INT_MIN;
min1 = min2 = INT_MAX;
```

---

### Step 2: Traverse the Array

For every element:

```cpp
num
```

update the three largest numbers.

If:

```cpp
num >= max1
```

shift the existing values:

```cpp
max3 = max2;
max2 = max1;
max1 = num;
```

Otherwise, update:

```cpp
max2
```

or

```cpp
max3
```

as needed.

---

### Step 3: Update the Smallest Numbers

During the same traversal, update the two smallest numbers.

If:

```cpp
num <= min1
```

shift the previous smallest value:

```cpp
min2 = min1;
min1 = num;
```

Otherwise, update:

```cpp
min2
```

when appropriate.

---

### Step 4: Compute the Two Possible Products

Compute:

```cpp
max1 * max2 * max3
```

which uses the three largest numbers.

Also compute:

```cpp
max1 * min1 * min2
```

which uses the largest number and the two smallest (possibly negative) numbers.

---

### Step 5: Return the Maximum Product

Return:

```cpp
max(max1 * max2 * max3,
    max1 * min1 * min2);
```

---

## Why This Works

There are only two possible ways to obtain the maximum product:

1. Using the three largest positive numbers.

Example:

```text
7, 8, 9
```

Product:

```text
7 × 8 × 9
```

2. Using the largest positive number with the two smallest negative numbers.

Example:

```text
-10, -8, 9
```

Product:

```text
(-10) × (-8) × 9 = 720
```

Since the product of two negative numbers is positive, this value may be larger than the product of the three largest numbers.

By tracking both the largest and smallest values in one traversal, the algorithm guarantees the correct answer.

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

Only five integer variables are maintained.

```cpp
O(1)
```

---

## Notes

- Uses a single-pass greedy approach.
- Maintains the three largest and two smallest numbers simultaneously.
- Considers both possible maximum-product combinations.
- Avoids sorting, reducing the time complexity to linear time.
- Requires constant extra space.
- This is the standard optimal solution for the problem.
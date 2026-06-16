# Next Greater Element II

## Problem Statement

Given a circular integer array `nums` (i.e., the next element of `nums[nums.length - 1]` is `nums[0]`), return the **next greater number** for every element in `nums`.

The next greater number of a number `x` is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number.

If it doesn't exist, return `-1` for that number.

---

# Solution: Monotonic Stack (Circular Array)

## Solution Overview

This solution uses a **monotonic decreasing stack** to efficiently find the next greater element for every index.

Key ideas:
- The array is circular, so elements near the end may find their next greater element at the beginning.
- Simulate two traversals of the array using:
  ```cpp
  2 * n
  ```
  iterations.
- Maintain a monotonic decreasing stack of indices.
- Remove all elements that are not greater than the current element.
- The top of the stack becomes the next greater element.

This avoids repeatedly scanning the array for each element.

---

## Algorithm

### Step 1: Initialize

Let:

```cpp
n = nums.size()
```

Create:

```cpp
vector<int> ans(n, -1);
```

and:

```cpp
stack<int> s;
```

---

### Step 2: Traverse Twice

Iterate from:

```cpp
i = 2*n - 1
```

to:

```cpp
0
```

Using:

```cpp
nums[i % n]
```

allows circular access.

---

### Step 3: Maintain Monotonic Stack

While:

```cpp
!s.empty()
```

and

```cpp
nums[s.top()] <= nums[i % n]
```

remove elements:

```cpp
s.pop();
```

These elements cannot be the next greater element.

---

### Step 4: Determine Next Greater Element

If the stack is empty:

```cpp
ans[i % n] = -1;
```

Otherwise:

```cpp
ans[i % n] = nums[s.top()];
```

The stack top is the first greater element encountered in circular order.

---

### Step 5: Push Current Index

Insert:

```cpp
i % n
```

into the stack:

```cpp
s.push(i % n);
```

---

### Step 6: Return Result

Return:

```cpp
ans
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

Each index is pushed and popped at most once.

Although the loop runs:

```cpp
2n
```

times, stack operations remain amortized linear.

---

### Space Complexity

```cpp
O(n)
```

For:

- Answer array
- Monotonic stack

---

## Notes

- Uses a monotonic decreasing stack.
- Simulates a circular array using:
  ```cpp
  i % n
  ```
- Two traversals ensure elements can find greater values at the beginning of the array.
- Each element is processed efficiently.
- Avoids the `O(n²)` brute-force approach.
- This is the standard optimal solution for the problem.
- Stack stores indices rather than values for easy access to array elements.
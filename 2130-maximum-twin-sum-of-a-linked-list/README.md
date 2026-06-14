# Maximum Twin Sum of a Linked List

## Problem Statement

In a linked list of size `n`, where `n` is even, the **twin** of the `i-th` node (0-indexed) is the `(n - 1 - i)-th` node.

For example:

- Node `0` is the twin of node `n - 1`
- Node `1` is the twin of node `n - 2`

The **twin sum** is defined as:

```cpp
node[i].val + node[n - 1 - i].val
```

Return the maximum twin sum of the linked list.

---

# Solution: Array Conversion + Two Pointers

## Solution Overview

This solution first stores all linked list values in an array and then uses the two-pointer technique to compute twin sums.

Key ideas:
- Convert the linked list into a vector.
- Twin nodes become symmetric elements in the array.
- Use two pointers:
  - One starting from the beginning.
  - One starting from the end.
- Compute every twin sum and keep track of the maximum.

This simplifies linked list access by leveraging array indexing.

---

## Algorithm

### Step 1: Store Values in an Array

Create:

```cpp
vector<int> nums;
```

Traverse the linked list:

```cpp
while(head)
```

and store:

```cpp
head->val
```

into the vector.

---

### Step 2: Initialize Two Pointers

Let:

```cpp
left = 0
```

and

```cpp
right = n - 1
```

where:

```cpp
n = nums.size()
```

---

### Step 3: Compute Twin Sums

While:

```cpp
left < right
```

1. Compute:

   ```cpp
   nums[left] + nums[right]
   ```

2. Update:

   ```cpp
   sum = max(sum, nums[left] + nums[right])
   ```

3. Move pointers:

   ```cpp
   left++
   right--
   ```

---

### Step 4: Return Result

Return:

```cpp
sum
```

which represents the maximum twin sum.

---

## Complexity Analysis

Let:

```cpp
n = number of nodes
```

### Time Complexity

- Linked list traversal: `O(n)`
- Twin sum computation: `O(n)`

Overall:

```cpp
O(n)
```

---

### Space Complexity

```cpp
O(n)
```

Extra space is used to store the linked list values in the vector.

---

## Notes

- Converting the linked list into an array makes twin node access straightforward.
- Twin nodes correspond to symmetric indices in the vector.
- Two-pointer traversal computes all twin sums efficiently.
- Simple and easy-to-understand solution.
- An optimized solution exists with:
  - Fast and slow pointers
  - Reversing the second half of the linked list
  - `O(1)` extra space.
- This approach prioritizes clarity and simplicity.
# Next Greater Element I

## Problem Statement

The **next greater element** of some element `x` in an array is the first greater element that is to the right of `x` in the same array.

You are given two distinct 0-indexed integer arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.

For each element in `nums1`, find its next greater element in `nums2`.

Return an array `ans` such that:

```cpp
ans[i]
```

is the next greater element of

```cpp
nums1[i]
```

in `nums2`, or `-1` if no such element exists.

---

# Solution: Monotonic Stack + Hash Map

## Solution Overview

This solution uses a **monotonic decreasing stack** to efficiently find the next greater element for every value in `nums2`.

Key ideas:
- Traverse `nums2` from right to left.
- Maintain a stack containing possible next greater elements.
- Remove all elements that are smaller than or equal to the current element.
- The top of the stack becomes the next greater element.
- Store the result in a hash map for fast lookup.
- Use the hash map to build the answer for `nums1`.

This avoids repeatedly scanning the array for every element.

---

## Algorithm

### Step 1: Initialize Data Structures

1. Create:
   - A hash map `m`
   - A stack `s`

The map stores:

```cpp
number → next greater element
```

---

### Step 2: Process nums2 from Right to Left

For every element:

```cpp
nums2[i]
```

#### Remove Smaller Elements

While:

```cpp
s.top() <= nums2[i]
```

remove elements from the stack.

These elements cannot be the next greater element for the current value.

---

#### Determine Next Greater Element

If the stack is empty:

```cpp
m[nums2[i]] = -1;
```

Otherwise:

```cpp
m[nums2[i]] = s.top();
```

The stack top is the first greater element on the right.

---

#### Push Current Element

Insert:

```cpp
nums2[i]
```

into the stack.

---

### Step 3: Build Answer for nums1

For every element in `nums1`:

```cpp
ans.push_back(m[nums1[i]]);
```

---

### Step 4: Return Result

Return the answer vector.

---

## Complexity Analysis

- **Time Complexity:** `O(n + m)`
  
  where:
  
  - `n = nums1.size()`
  - `m = nums2.size()`

Each element is pushed and popped from the stack at most once.

- **Space Complexity:** `O(m)`
  
  For the stack and hash map.

---

## Notes

- Uses a monotonic decreasing stack.
- Hash map provides constant-time lookup for elements in `nums1`.
- Each element is processed only once.
- Efficiently computes all next greater elements in a single traversal.
- Avoids the `O(n × m)` brute-force approach.
- This is the standard optimal solution for the problem.
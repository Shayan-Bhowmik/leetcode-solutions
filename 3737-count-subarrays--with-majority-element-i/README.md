# Count Majority Subarrays

## Problem Statement

You are given an integer array `nums` and an integer `target`.

A subarray is called a **majority subarray** if the number of occurrences of `target` in that subarray is **strictly greater than half** of its length.

Return the total number of majority subarrays.

---

# Solution: Brute Force Enumeration

## Solution Overview

This solution checks every possible subarray and counts how many times the `target` appears.

Key ideas:
- Enumerate all possible subarrays.
- Maintain the count of `target` while extending the subarray.
- Compute the current subarray length.
- If the number of occurrences of `target` is greater than half the subarray length, count it as a valid majority subarray.

This guarantees that every possible subarray is considered.

---

## Algorithm

### Step 1: Initialize Answer

Create:

```cpp
ans = 0;
```

to store the number of majority subarrays.

---

### Step 2: Choose Every Starting Index

For every index:

```cpp
i = 0 ... n - 1
```

initialize:

```cpp
targetCount = 0;
```

---

### Step 3: Extend the Subarray

For every ending index:

```cpp
j = i ... n - 1
```

If:

```cpp
nums[j] == target
```

increment:

```cpp
targetCount++;
```

---

### Step 4: Check Majority Condition

Compute the current subarray length:

```cpp
len = j - i + 1;
```

If:

```cpp
targetCount > len / 2
```

then the target is the majority element in the current subarray.

Increment:

```cpp
ans++;
```

---

### Step 5: Return Result

Return:

```cpp
ans;
```

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

```cpp
O(n²)
```

Every possible subarray is examined exactly once.

---

### Space Complexity

```cpp
O(1)
```

Only a few extra variables are used.

---

## Notes

- Enumerates all possible subarrays.
- Maintains the target frequency incrementally while extending each subarray.
- Checks the majority condition:
  ```cpp
  targetCount > length / 2
  ```
  for every subarray.
- Uses constant extra space.
- Straightforward brute-force solution.
- Suitable for small input sizes.
- More efficient solutions exist for larger constraints.
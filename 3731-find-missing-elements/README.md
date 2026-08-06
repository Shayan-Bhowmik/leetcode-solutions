# Find Missing Elements

## Problem Statement

You are given an integer array:

```cpp
nums
```

Return all the integers that are **missing** between the minimum and maximum values of the array.

The missing elements should be returned in increasing order.

---

# Solution: Hash Set + Range Traversal

## Solution Overview

This solution uses a **Hash Set** for fast lookups.

Key ideas:
- Store all elements of the array in an `unordered_set`.
- Find the minimum and maximum values in the array.
- Traverse every integer between the minimum and maximum.
- If a number is not present in the hash set, it is missing and is added to the answer.

The hash set allows checking whether a number exists in constant average time.

---

## Algorithm

### Step 1: Store All Elements

Create a hash set containing every element:

```cpp
unordered_set<int> copy_nums(nums.begin(), nums.end());
```

This enables efficient existence checks.

---

### Step 2: Sort the Array

Sort the array:

```cpp
sort(nums.begin(), nums.end());
```

After sorting:

```cpp
min = nums[0];
max = nums[n - 1];
```

represent the smallest and largest elements.

---

### Step 3: Traverse the Range

Iterate through every integer from:

```cpp
min
```

to

```cpp
max
```

For each value:

```cpp
i
```

check whether it exists in the hash set:

```cpp
if (!copy_nums.count(i))
```

If not, append it to the answer:

```cpp
ans.push_back(i);
```

---

### Step 4: Return the Result

Return:

```cpp
ans;
```

which contains all missing integers in sorted order.

---

## Why This Works

The smallest and largest values define the complete range of numbers that should exist.

By storing every array element in a hash set:

- Existing numbers are found in **O(1)** average time.
- Missing numbers are exactly those absent from the set while traversing the range.

Since the traversal is performed in increasing order, the resulting list is automatically sorted.

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

and

```cpp
R = maxValue - minValue + 1
```

### Time Complexity

Building the hash set:

```cpp
O(n)
```

Sorting the array:

```cpp
O(n log n)
```

Traversing the range:

```cpp
O(R)
```

Overall:

```cpp
O(n log n + R)
```

> **Note:** Sorting is only used to obtain the minimum and maximum values. Using `min_element()` and `max_element()` instead would improve the complexity to **O(n + R)**.

---

### Space Complexity

Hash set:

```cpp
O(n)
```

Answer vector:

```cpp
O(k)
```

where `k` is the number of missing integers.

Overall:

```cpp
O(n + k)
```

---

## Notes

- Uses a hash set for constant-time membership checks.
- Sorts the array to determine the minimum and maximum values.
- Traverses every integer in the inclusive range `[min, max]`.
- Adds every absent integer to the result.
- Returns the missing numbers in increasing order.
- **Optimization:** Sorting can be avoided by using `min_element()` and `max_element()`, reducing the time complexity to `O(n + R)`.
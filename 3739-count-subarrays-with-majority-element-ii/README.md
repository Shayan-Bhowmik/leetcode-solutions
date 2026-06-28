# Count Majority Subarrays

## Problem Statement

You are given an integer array `nums` and an integer `target`.

A subarray is called a **majority subarray** if the number of occurrences of `target` in that subarray is **strictly greater than half** of its length.

Return the total number of majority subarrays.

---

# Solution: Prefix Sum + Binary Indexed Tree (Fenwick Tree)

## Solution Overview

This solution transforms the majority condition into a prefix sum problem and efficiently counts valid subarrays using a **Binary Indexed Tree (Fenwick Tree)**.

Key ideas:
- Treat every occurrence of `target` as:
  ```cpp
  +1
  ```
- Treat every other element as:
  ```cpp
  -1
  ```
- A subarray has `target` as the majority element if its transformed sum is **positive**.
- Maintain prefix sums of the transformed array.
- Use a Fenwick Tree to count how many previous prefix sums are smaller than the current prefix sum.
- Each such prefix corresponds to a valid majority subarray.

This avoids checking every subarray explicitly.

---

## Key Observation

Transform the array as follows:

- If:

  ```cpp
  nums[i] == target
  ```

  assign:

  ```cpp
  +1
  ```

- Otherwise assign:

  ```cpp
  -1
  ```

For any subarray:

```cpp
sum > 0
```

is equivalent to:

```cpp
targetCount > subarrayLength / 2
```

Thus, the problem becomes counting subarrays with a positive sum.

---

## Algorithm

### Step 1: Initialize Fenwick Tree

Create a Binary Indexed Tree of size:

```cpp
2 * n + 2
```

An offset is used so that negative prefix sums can be stored as positive indices.

Initialize:

```cpp
prefix = n + 1;
```

Insert the initial prefix sum:

```cpp
bit.update(prefix, 1);
```

---

### Step 2: Traverse the Array

For every element:

#### If Current Element is Target

Increase the prefix sum:

```cpp
prefix++;
```

#### Otherwise

Decrease the prefix sum:

```cpp
prefix--;
```

---

### Step 3: Count Valid Prefix Sums

A subarray ending at the current position is valid if:

```cpp
currentPrefix > previousPrefix
```

The Fenwick Tree stores the frequencies of previous prefix sums.

Query:

```cpp
bit.query(prefix - 1);
```

This returns the number of previous prefix sums that are strictly smaller than the current prefix sum.

Add this count to:

```cpp
ans
```

---

### Step 4: Insert Current Prefix

Store the current prefix sum:

```cpp
bit.update(prefix, 1);
```

---

### Step 5: Return Answer

Return:

```cpp
ans;
```

---

## Binary Indexed Tree Operations

### Update

Adds a value at an index:

```cpp
update(idx, val)
```

Time Complexity:

```cpp
O(log n)
```

---

### Query

Returns the prefix sum up to an index:

```cpp
query(idx)
```

Time Complexity:

```cpp
O(log n)
```

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

Each element performs:

- One update
- One query

Each operation takes:

```cpp
O(log n)
```

Overall:

```cpp
O(n log n)
```

---

### Space Complexity

Fenwick Tree:

```cpp
O(n)
```

Overall:

```cpp
O(n)
```

---

## Notes

- Converts the majority condition into a positive prefix sum problem.
- Represents:
  - `target` as `+1`
  - non-target elements as `-1`.
- Uses an offset to safely store negative prefix sums in the Fenwick Tree.
- Fenwick Tree supports efficient prefix frequency queries.
- Counts valid subarrays without enumerating all possibilities.
- Improves upon the brute-force `O(n²)` solution.
- This is the standard optimized solution for counting majority subarrays.
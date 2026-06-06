# Left and Right Sum Differences

## Problem Statement

Given a 0-indexed integer array `nums`, find an integer array `answer` of the same length such that:

```cpp
answer[i] = |leftSum[i] - rightSum[i]|
```

where:

- `leftSum[i]` is the sum of elements to the left of index `i`.
- `rightSum[i]` is the sum of elements to the right of index `i`.

Return the array `answer`.

---

# Solution: Running Left and Right Sums

## Solution Overview

This solution computes the left and right sums efficiently using running totals.

Key ideas:
- First compute the total sum of all elements.
- Use `rightSum` to represent the sum of elements to the right of the current index.
- Use `leftSum` to represent the sum of elements to the left of the current index.
- For each position:
  - Update both sums.
  - Compute the absolute difference.
  - Store the result.

This avoids recalculating sums for every index.

---

## Algorithm

### Step 1: Compute Total Sum

1. Initialize:
   ```cpp
   leftSum = 0
   rightSum = 0
   ```
2. Traverse the array and compute:
   ```cpp
   rightSum += nums[i]
   ```

After this step:

```cpp
rightSum = sum of all elements
```

---

### Step 2: Process Each Index

For every index `i`:

#### Update Right Sum

Remove the current element from the right side:

```cpp
rightSum -= nums[i]
```

For the last element:

```cpp
rightSum = 0
```

---

#### Update Left Sum

Add the previous element to the left side:

```cpp
leftSum += nums[i - 1]
```

For the first element:

```cpp
leftSum = 0
```

---

#### Compute Difference

Calculate:

```cpp
abs(leftSum - rightSum)
```

Store it in the answer array.

---

### Step 3: Return Result

Return the constructed answer array.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  
  The array is traversed a constant number of times.

- **Space Complexity:** `O(n)`
  
  Required for the output array.

---

## Notes

- Uses running sums instead of recomputing left and right sums repeatedly.
- The first element always has:
  ```cpp
  leftSum = 0
  ```
- The last element always has:
  ```cpp
  rightSum = 0
  ```
- `abs()` ensures the difference is non-negative.
- Efficient linear-time solution.
- Avoids the `O(n²)` brute-force approach of computing sums separately for every index.
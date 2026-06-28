# Maximum Element After Decreasing and Rearranging

## Problem Statement

You are given an array of positive integers `arr`.

In one operation, you can:

- Decrease the value of any element to a smaller positive integer.

After performing any number of operations, rearrange the elements so that:

- The first element is equal to `1`.
- The absolute difference between any two adjacent elements is at most `1`.

Return the maximum possible value of the last element of the rearranged array.

---

# Solution: Sorting + Greedy Adjustment

## Solution Overview

This solution uses a **greedy strategy** after sorting the array.

Key ideas:
- Sort the array in ascending order.
- Force the smallest element to become `1`.
- Traverse the array from left to right.
- For every element, ensure it is at most one greater than the previous element.
- This maximizes every element while maintaining the required condition.

The last element obtained after this process is the maximum possible answer.

---

## Algorithm

### Step 1: Sort the Array

Sort the array in ascending order:

```cpp
sort(arr.begin(), arr.end());
```

---

### Step 2: Set the First Element

The first element must be:

```cpp
1
```

So assign:

```cpp
arr[0] = 1;
```

---

### Step 3: Greedily Adjust Remaining Elements

Traverse the array from:

```cpp
i = 1
```

to:

```cpp
arr.size() - 1
```

For each element, assign:

```cpp
arr[i] = min(arr[i], arr[i - 1] + 1);
```

This ensures:

- The element is not increased.
- The difference with the previous element is at most `1`.
- The current element is as large as possible.

---

### Step 4: Return Answer

The largest possible value is the last element:

```cpp
return arr.back();
```

---

## Complexity Analysis

Let:

```cpp
n = arr.size()
```

### Time Complexity

Sorting:

```cpp
O(n log n)
```

Greedy traversal:

```cpp
O(n)
```

Overall:

```cpp
O(n log n)
```

---

### Space Complexity

```cpp
O(1)
```

Ignoring the space used by the sorting algorithm.

---

## Notes

- Sorting allows the array to be processed in increasing order.
- The first element is always fixed to `1`.
- Each subsequent element is limited to at most one greater than its predecessor.
- The greedy adjustment maximizes every element while satisfying the constraints.
- The last element after processing is the maximum achievable value.
- This is the standard optimal solution for the problem.
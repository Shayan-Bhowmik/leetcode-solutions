# Largest Rectangle in Histogram

## Problem Statement

Given an array of integers `heights` representing the histogram's bar heights, where the width of each bar is `1`, return the area of the largest rectangle in the histogram.

---

# Solution: Monotonic Stack (Previous Smaller + Next Smaller)

## Solution Overview

This solution uses **monotonic stacks** to find:

- The nearest smaller element on the left.
- The nearest smaller element on the right.

Key ideas:
- For every bar, determine the maximum width over which it can extend.
- The width is bounded by the first smaller bar on both sides.
- Compute the area contributed by each bar as:
  ```cpp
  height × width
  ```
- Return the maximum area found.

This avoids checking every possible rectangle explicitly.

---

## Algorithm

### Step 1: Find Next Smaller Element

Create:

```cpp
right[i]
```

which stores the index of the first smaller element to the right.

Traverse from right to left:

1. Remove all bars that are greater than or equal to the current bar.
2. If no smaller element exists:
   ```cpp
   right[i] = n
   ```
3. Otherwise:
   ```cpp
   right[i] = s.top()
   ```
4. Push the current index onto the stack.

---

### Step 2: Find Previous Smaller Element

Create:

```cpp
left[i]
```

which stores the index of the first smaller element to the left.

Traverse from left to right:

1. Remove all bars that are greater than or equal to the current bar.
2. If no smaller element exists:
   ```cpp
   left[i] = -1
   ```
3. Otherwise:
   ```cpp
   left[i] = s.top()
   ```
4. Push the current index onto the stack.

---

### Step 3: Calculate Maximum Area

For every bar:

1. Compute width:

   ```cpp
   width = right[i] - left[i] - 1
   ```

2. Compute area:

   ```cpp
   curr_area = heights[i] * width
   ```

3. Update:

   ```cpp
   ans = max(ans, curr_area)
   ```

---

### Step 4: Return Answer

Return:

```cpp
ans
```

---

## Complexity Analysis

Let:

```cpp
n = heights.size()
```

### Time Complexity

- Next Smaller Element: `O(n)`
- Previous Smaller Element: `O(n)`
- Area Calculation: `O(n)`

Overall:

```cpp
O(n)
```

Each index is pushed and popped from the stack at most once.

---

### Space Complexity

```cpp
O(n)
```

Used by:

- `left` array
- `right` array
- stack

---

## Notes

- Uses monotonic increasing stacks.
- Finds the largest rectangle for every bar as the limiting height.
- Previous Smaller and Next Smaller elements define the rectangle boundaries.
- Efficient linear-time solution.
- Avoids the `O(n²)` brute-force approach.
- This is the standard optimal solution for the problem.
- The width formula:
  ```cpp
  right[i] - left[i] - 1
  ```
  gives the maximum span where `heights[i]` remains the minimum height.
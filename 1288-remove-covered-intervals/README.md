# Remove Covered Intervals

## Problem Statement

Given an array:

```cpp
intervals
```

where:

```cpp
intervals[i] = [li, ri]
```

represents the interval:

```cpp
[li, ri)
```

remove all intervals that are covered by another interval in the list.

An interval:

```cpp
[a, b)
```

is covered by an interval:

```cpp
[c, d)
```

if and only if:

```cpp
c <= a
```

and

```cpp
b <= d
```

Return the number of remaining intervals after removing all covered intervals.

---

# Solution: Sorting + Greedy Traversal

## Solution Overview

This solution first sorts the intervals so that potential covering intervals always appear before the intervals they may cover.

Key ideas:
- Sort intervals by:
  - Increasing start point.
  - Decreasing end point when the start points are equal.
- Traverse the sorted intervals once.
- Maintain the largest ending point seen so far.
- If the current interval extends beyond the largest end, it is not covered.
- Otherwise, it is covered by a previously processed interval.

This allows all covered intervals to be identified in a single pass.

---

## Algorithm

### Step 1: Sort the Intervals

Sort using the following comparator:

- Smaller starting point first.
- If two intervals have the same starting point, place the one with the larger ending point first.

```cpp
sort(intervals.begin(), intervals.end(),
    [](vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    });
```

This guarantees that a larger interval appears before any interval it may cover.

---

### Step 2: Initialize Variables

Create:

```cpp
count = 0;
```

to count the remaining intervals.

Maintain:

```cpp
maxEnd = 0;
```

which stores the largest ending point encountered so far.

---

### Step 3: Traverse the Intervals

For every interval:

```cpp
[start, end]
```

check whether:

```cpp
end > maxEnd
```

---

### Step 4: Update Answer

If:

```cpp
end > maxEnd
```

then the interval is **not covered**.

Increment:

```cpp
count++;
```

Update:

```cpp
maxEnd = end;
```

Otherwise, the interval is covered by a previous interval and is ignored.

---

### Step 5: Return Result

Return:

```cpp
count;
```

---

## Complexity Analysis

Let:

```cpp
n = intervals.size()
```

### Time Complexity

Sorting:

```cpp
O(n log n)
```

Single traversal:

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

- Sorting by increasing start and decreasing end is essential.
- Placing longer intervals first ensures covered intervals appear later in the traversal.
- `maxEnd` keeps track of the farthest ending point seen so far.
- An interval is covered if its ending point does not exceed `maxEnd`.
- Only one linear scan is needed after sorting.
- This is the standard optimal solution for the problem.
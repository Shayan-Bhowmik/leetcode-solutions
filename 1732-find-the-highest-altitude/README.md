# Find the Highest Altitude

## Problem Statement

There is a biker going on a road trip. The road trip consists of `n + 1` points at different altitudes.

You are given an integer array `gain` of length `n` where:

```cpp
gain[i]
```

is the net gain in altitude between points `i` and `i + 1`.

The biker starts the trip at altitude:

```cpp
0
```

Return the highest altitude reached during the trip.

---

# Solution: Running Prefix Sum

## Solution Overview

This solution tracks the biker's altitude throughout the trip using a running sum.

Key ideas:
- Start at altitude `0`.
- Add each altitude gain to the current altitude.
- Continuously track the highest altitude encountered.
- The running altitude is effectively a prefix sum of the `gain` array.

This avoids storing all intermediate altitudes.

---

## Algorithm

### Step 1: Initialize Variables

Create:

```cpp
netGain = 0
```

to store the current altitude.

Create:

```cpp
highGain = 0
```

to store the maximum altitude reached.

---

### Step 2: Traverse the Gain Array

For every element:

```cpp
gain[i]
```

update the current altitude:

```cpp
netGain += gain[i];
```

---

### Step 3: Update Maximum Altitude

After updating the altitude:

```cpp
highGain = max(highGain, netGain);
```

This keeps track of the highest altitude reached so far.

---

### Step 4: Return Result

Return:

```cpp
highGain
```

as the highest altitude reached during the trip.

---

## Complexity Analysis

Let:

```cpp
n = gain.size()
```

### Time Complexity

```cpp
O(n)
```

The array is traversed once.

---

### Space Complexity

```cpp
O(1)
```

Only a few variables are used.

---

## Notes

- The biker starts at altitude:
  ```cpp
  0
  ```
- Running altitude is computed using a prefix sum.
- No extra array is needed to store intermediate altitudes.
- Maximum altitude is updated during traversal.
- Efficient linear-time solution.
- This is the standard optimal solution for the problem.
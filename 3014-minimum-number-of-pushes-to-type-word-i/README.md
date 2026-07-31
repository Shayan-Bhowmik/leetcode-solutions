# Minimum Number of Pushes to Type Word I

## Problem Statement

You are given a string:

```cpp
word
```

You need to assign its distinct characters to the keys of a telephone keypad.

Each key can contain at most **8 characters**.

The cost of typing a character depends on its position on the assigned key:

- First character on a key requires **1 push**.
- Second character requires **2 pushes**.
- Third character requires **3 pushes**, and so on.

Return the **minimum number of pushes** required to type the entire word.

---

# Solution: Greedy Assignment

## Solution Overview

To minimize the total number of pushes, characters should be assigned to the keypad in the order of increasing push cost.

Since every key can hold **8 characters**:
- The first 8 characters require **1 push** each.
- The next 8 characters require **2 pushes** each.
- The following 8 characters require **3 pushes** each.
- And so on.

As the problem guarantees that all characters in `word` are distinct, we only need to compute the push cost based on each character's position.

---

## Algorithm

### Step 1: Initialize the Answer

Create a variable:

```cpp
ans = 0;
```

to store the total number of pushes.

---

### Step 2: Traverse the Characters

For every character at index:

```cpp
i
```

its push cost is:

```cpp
i / 8 + 1
```

where:

- Indices `0–7` require `1` push.
- Indices `8–15` require `2` pushes.
- Indices `16–23` require `3` pushes.
- And so on.

Add this value to the answer:

```cpp
ans += i / 8 + 1;
```

---

### Step 3: Return the Answer

Return:

```cpp
ans;
```

---

## Why This Works

To achieve the minimum number of pushes:

- Assign the first 8 characters to the first push level.
- Assign the next 8 characters to the second push level.
- Continue this process until all characters are assigned.

Since every character appears exactly once and all characters are distinct, this greedy assignment is always optimal.

---

## Complexity Analysis

Let:

```cpp
n = word.length()
```

### Time Complexity

Each character is processed exactly once.

```cpp
O(n)
```

---

### Space Complexity

Only one integer variable is used.

```cpp
O(1)
```

---

## Notes

- Uses a greedy strategy for assigning characters to keypad positions.
- Every group of 8 characters increases the required pushes by 1.
- Computes the push cost directly using:
  ```cpp
  i / 8 + 1
  ```
- Avoids explicit keypad simulation.
- Requires constant extra space.
- This is the standard optimal solution for the problem.
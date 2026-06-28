# Find the Maximum Number of Elements in Subset

## Problem Statement

You are given an integer array `nums`.

Select a subset of elements that can be arranged in the following form:

```text
[x, x, x², x⁴, x⁸, ...]
```

where:

- Every element (except possibly the last) appears exactly twice.
- Each subsequent value is the square of the previous value.
- The last element appears exactly once.

The special value `1` is handled separately since:

```text
1² = 1
```

Return the maximum possible length of such a subset.

---

# Solution: Frequency Map + Greedy Chain Construction

## Solution Overview

This solution counts the frequency of every number and greedily constructs the longest valid squaring chain.

Key ideas:
- Count the frequency of every number.
- Handle the value `1` separately because squaring `1` always produces `1`.
- For every other possible starting value:
  - Build a chain by repeatedly squaring the current value.
  - Every intermediate value must appear at least twice.
  - The last value contributes one element if it exists.
- Keep track of the maximum chain length.

This efficiently finds the longest valid subset.

---

## Algorithm

### Step 1: Count Frequencies

Create:

```cpp
unordered_map<int, int> freq;
```

Store the frequency of every element.

---

### Step 2: Handle Value 1

Since:

```cpp
1² = 1
```

all ones belong to the same chain.

The maximum valid length is the largest odd number not exceeding the number of ones:

```cpp
(freq[1] - 1) | 1
```

Store this as the initial answer.

Remove:

```cpp
1
```

from the frequency map.

---

### Step 3: Process Every Remaining Number

For every distinct value:

```cpp
x
```

initialize:

```cpp
n = 0;
```

representing the current chain length.

---

### Step 4: Skip Non-Starting Values

If:

```cpp
x
```

is itself the square of another number that appears at least twice:

```cpp
sq = sqrt(x);
```

and

```cpp
sq * sq == x
```

with

```cpp
freq[sq] > 1
```

skip this value.

It will already be included in a longer chain.

---

### Step 5: Extend the Chain

While:

- the current value exists,
- it appears at least twice,

increment:

```cpp
n += 2;
```

and square the value:

```cpp
x *= x;
```

Continue until the chain cannot be extended further.

---

### Step 6: Add the Final Element

If the final value still exists:

```cpp
freq.count(x)
```

it contributes one additional element.

Compute:

```cpp
n + ((freq.count(x) << 1) - 1)
```

which evaluates to:

- `n + 1` if the value exists.
- `n - 1` otherwise.

Update the maximum answer.

---

### Step 7: Return Result

Return:

```cpp
res;
```

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

Building the frequency map:

```cpp
O(n)
```

Each distinct number is processed once.

Since repeated squaring grows extremely quickly, every chain has only a few levels.

Overall:

```cpp
O(n)
```

---

### Space Complexity

```cpp
O(n)
```

For the frequency map.

---

## Notes

- Uses a frequency map for constant-time lookups.
- Handles the value `1` separately because it squares to itself.
- Greedily builds chains by repeated squaring.
- Intermediate values must appear at least twice.
- The final value contributes only one element.
- Skips numbers that belong to an already explored chain.
- Efficient linear-time solution.
- This is the standard optimal solution for the problem.
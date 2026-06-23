# Count ZigZag Arrays

## Problem Statement

You are given three integers:

```cpp
n, l, r
```

A **ZigZag array** of length `n` satisfies:

1. Every element lies in the range:

   ```cpp
   [l, r]
   ```

2. No two adjacent elements are equal.

3. No three consecutive elements form a strictly increasing sequence.

4. No three consecutive elements form a strictly decreasing sequence.

Return the total number of valid ZigZag arrays.

Since the answer may be large, return it modulo:

```cpp
10^9 + 7
```

---

# Solution: Dynamic Programming with Prefix and Suffix Sums

## Solution Overview

This solution tracks arrays based on the direction of their last comparison.

Key ideas:
- Let:
  - `down[i]` = number of valid arrays ending at value `i` whose last step was decreasing.
  - `up[i]` = number of valid arrays ending at value `i` whose last step was increasing.
- A decreasing step can only follow an increasing step.
- An increasing step can only follow a decreasing step.
- Prefix sums and suffix sums allow transitions to be computed efficiently.

This avoids checking all possible previous values individually.

---

## Dynamic Programming State

For each value:

```cpp
i ∈ [1, m]
```

where:

```cpp
m = r - l + 1
```

store:

```cpp
down[i]
```

and

```cpp
up[i]
```

---

### Meaning of States

#### down[i]

Number of valid arrays ending at value:

```cpp
i
```

whose last comparison is:

```cpp
previous > i
```

---

#### up[i]

Number of valid arrays ending at value:

```cpp
i
```

whose last comparison is:

```cpp
previous < i
```

---

## Base Case

If:

```cpp
n == 1
```

every value in the range is valid.

Return:

```cpp
m
```

---

For arrays of length `2`:

### Decreasing Pair

For value:

```cpp
i
```

there are:

```cpp
i - 1
```

smaller values before it.

So:

```cpp
down[i] = i - 1
```

---

### Increasing Pair

For value:

```cpp
i
```

there are:

```cpp
m - i
```

larger values before it.

So:

```cpp
up[i] = m - i
```

---

## Transition

For longer arrays:

### Prefix Sum of Increasing States

Build:

```cpp
prefUp[i]
```

where:

```cpp
prefUp[i]
=
prefUp[i-1] + up[i]
```

---

### Suffix Sum of Decreasing States

Build:

```cpp
suffDown[i]
```

where:

```cpp
suffDown[i]
=
suffDown[i+1] + down[i]
```

---

### Compute New Down States

To end with a decreasing step at:

```cpp
z
```

the previous value must be smaller than `z`.

Thus:

```cpp
nextDown[z]
=
prefUp[z-1]
```

---

### Compute New Up States

To end with an increasing step at:

```cpp
z
```

the previous value must be larger than `z`.

Thus:

```cpp
nextUp[z]
=
suffDown[z+1]
```

---

### Update DP

After processing all values:

```cpp
swap(down, nextDown);
swap(up, nextUp);
```

---

## Final Answer

After building arrays of length:

```cpp
n
```

sum all valid states:

```cpp
ans += down[i] + up[i]
```

for every:

```cpp
i
```

Return:

```cpp
ans % mod
```

---

## Complexity Analysis

Let:

```cpp
m = r - l + 1
```

---

### Time Complexity

For each of the:

```cpp
n - 2
```

levels:

- Prefix sum: `O(m)`
- Suffix sum: `O(m)`
- State transitions: `O(m)`

Total:

```cpp
O(n × m)
```

---

### Space Complexity

Arrays stored:

```cpp
down
up
nextDown
nextUp
prefUp
suffDown
```

Total:

```cpp
O(m)
```

---

## Notes

- Adjacent elements are never equal because transitions only occur between strictly smaller and strictly larger values.
- Alternating between `up` and `down` states prevents three consecutive increasing or decreasing elements.
- Prefix sums efficiently aggregate all valid smaller values.
- Suffix sums efficiently aggregate all valid larger values.
- Avoids the naive `O(n × m²)` DP.
- Achieves an optimized:
  ```cpp
  O(n × m)
  ```
  solution.
- All calculations are performed modulo:
  ```cpp
  10^9 + 7
  ```
  to handle large answers.
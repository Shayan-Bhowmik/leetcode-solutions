# Total Waviness of Numbers in a Range

## Problem Statement

Given two integers `num1` and `num2`, return the **total waviness** of all numbers in the inclusive range `[num1, num2]`.

A digit contributes to the waviness of a number if it is either:

- Strictly greater than both adjacent digits (a local maximum), or
- Strictly smaller than both adjacent digits (a local minimum).

Only digits that have both a left and a right neighbor can contribute to waviness.

Return the sum of waviness values for all numbers in the given range.

---

# Solution: Digit DP

## Solution Overview

This solution uses **Digit Dynamic Programming (Digit DP)** to efficiently compute the total waviness for all numbers up to a given limit.

Key ideas:
- Instead of checking every number individually, count waviness while constructing numbers digit by digit.
- Maintain the previous two digits to determine whether the middle digit forms a peak or valley.
- Use memoization to avoid recomputing states.
- Compute:
  - Total numbers represented by a state.
  - Total waviness contributed by those numbers.
- Use range query technique:
  ```cpp
  Answer(num2) - Answer(num1 - 1)
  ```

This avoids iterating through every number in the range.

---

## Dynamic Programming State

The DP state is:

```cpp
solveDP(pos, tight, started, prev1, prev2)
```

where:

- `pos`
  - Current digit position being processed.
- `tight`
  - Whether the current prefix matches the upper bound.
- `started`
  - Whether a non-leading-zero digit has been chosen.
- `prev1`
  - Most recently chosen digit.
- `prev2`
  - Digit before `prev1`.

The DP returns:

```cpp
{
    totalCount,
    totalWave
}
```

where:

- `totalCount`
  - Number of valid numbers formed.
- `totalWave`
  - Total waviness contributed by those numbers.

---

## Algorithm

### Step 1: Process Digits from Left to Right

For every position:

1. Determine the maximum digit allowed:
   ```cpp
   limit = tight ? currentDigit : 9;
   ```

2. Try every possible digit:
   ```cpp
   digit = 0 ... limit
   ```

---

### Step 2: Handle Leading Zeros

If the number has not started yet:

```cpp
started == 0 && digit == 0
```

Continue without contributing any waviness.

---

### Step 3: Start Building a Number

When the first non-zero digit is chosen:

```cpp
started = 1
```

Store the first digit as:

```cpp
prev1 = digit
prev2 = 10
```

(`10` is used as a sentinel value.)

---

### Step 4: Detect Peaks and Valleys

Once at least three digits are available:

```cpp
prev2 != 10
```

Check whether the middle digit forms:

**Peak**

```cpp
prev1 > prev2 && prev1 > digit
```

**Valley**

```cpp
prev1 < prev2 && prev1 < digit
```

If either condition is true:

```cpp
add = 1
```

---

### Step 5: Accumulate Results

For every transition:

```cpp
totalCount += next.first;
```

```cpp
totalWave += next.second
           + add * next.first;
```

This propagates waviness contributions across all valid numbers.

---

### Step 6: Range Query

Define:

```cpp
getAnswer(x)
```

which computes total waviness for all numbers in:

```cpp
[1, x]
```

Then:

```cpp
totalWaviness(num1, num2)
=
getAnswer(num2)
-
getAnswer(num1 - 1)
```

---

## Complexity Analysis

### Time Complexity

- **O(D × 2 × 2 × 11 × 11 × 10)**

where:

- `D ≤ 19` for a 64-bit integer.

This simplifies to:

```cpp
O(1)
```

for practical constraints.

---

### Space Complexity

- **O(D × 2 × 2 × 11 × 11)**

Used by the memoization tables.

---

## Notes

- Uses Digit DP to avoid iterating through every number.
- Stores both count and waviness contribution in each state.
- Handles leading zeros correctly.
- Uses `prev1` and `prev2` to detect local maxima and minima.
- Supports very large ranges efficiently.
- Range queries are handled using:
  ```cpp
  f(R) - f(L - 1)
  ```
- Significantly faster than the brute-force solution for large inputs.
- This is the standard optimized approach for digit-based counting problems.
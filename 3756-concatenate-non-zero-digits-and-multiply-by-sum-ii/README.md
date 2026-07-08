# Sum and Multiply II

## Problem Statement

You are given a string:

```cpp
s
```

consisting of digits and a 2D integer array:

```cpp
queries
```

where:

```cpp
queries[i] = [li, ri]
```

For each query:

1. Extract the substring:

   ```cpp
   s[li..ri]
   ```

2. Remove all occurrences of the digit:

   ```cpp
   '0'
   ```

   while preserving the order of the remaining digits.

3. Let:

   - `sum` be the sum of the remaining digits.
   - `number` be the integer formed by the remaining digits.

Return an array where the answer for each query is:

```cpp
(number × sum) mod (10^9 + 7)
```

---

# Solution: Prefix Sums + Prefix Number Construction

## Solution Overview

This solution preprocesses the string so that every query can be answered efficiently.

Key ideas:
- Compute prefix sums of digits.
- Compute prefix counts of non-zero digits.
- Build the number formed by non-zero digits using modular arithmetic.
- Precompute powers of `10` modulo:
  ```cpp
  10^9 + 7
  ```
- For every query:
  - Compute the digit sum.
  - Reconstruct the non-zero number.
  - Multiply the two values modulo `10^9 + 7`.

This avoids rebuilding the number for every query.

---

## Preprocessing

### Step 1: Compute Powers of 10

Create:

```cpp
power10[i]
```

where:

```cpp
power10[i]
=
10^i mod MOD
```

This is used while reconstructing numbers for queries.

---

### Step 2: Prefix Digit Sum

Create:

```cpp
prefixSum[i]
```

which stores:

```cpp
sum of digits
```

from:

```cpp
0
```

to:

```cpp
i-1
```

---

### Step 3: Prefix Non-Zero Count

Create:

```cpp
prefixNonZero[i]
```

which stores the number of non-zero digits up to index:

```cpp
i-1
```

---

### Step 4: Prefix Number

Maintain:

```cpp
prefixNumber[i]
```

representing the number formed by all non-zero digits seen so far.

Whenever a non-zero digit appears:

```cpp
prefixNumber =
prefixNumber * 10 + digit
```

All calculations are performed modulo:

```cpp
10^9 + 7
```

---

## Processing Each Query

For every query:

```cpp
[left, right]
```

---

### Step 1: Compute Digit Sum

Using prefix sums:

```cpp
digitSum =
prefixSum[right + 1]
-
prefixSum[left]
```

---

### Step 2: Count Non-Zero Digits

Compute:

```cpp
nonZeroCount =
prefixNonZero[right + 1]
-
prefixNonZero[left]
```

---

### Step 3: Reconstruct the Number

The required number is obtained by removing the contribution of the prefix before:

```cpp
left
```

using:

```cpp
number =
(
prefixNumber[right + 1]
-
prefixNumber[left]
×
10^(nonZeroCount)
)
mod MOD
```

The implementation adds:

```cpp
MOD
```

before taking modulo to avoid negative values.

---

### Step 4: Compute Answer

Return:

```cpp
(number × digitSum) mod MOD
```

---

## Complexity Analysis

Let:

```cpp
n = s.length()
```

and

```cpp
q = queries.size()
```

### Preprocessing

Power array:

```cpp
O(n)
```

Prefix arrays:

```cpp
O(n)
```

---

### Query Processing

Each query performs only constant-time operations.

```cpp
O(1)
```

---

### Overall Time Complexity

```cpp
O(n + q)
```

---

### Space Complexity

Power array:

```cpp
O(n)
```

Prefix arrays:

```cpp
O(n)
```

Overall:

```cpp
O(n)
```

---

## Notes

- Uses prefix sums to compute digit sums in constant time.
- Maintains prefix counts of non-zero digits.
- Constructs numbers using modular arithmetic to prevent overflow.
- Precomputes powers of `10` for efficient substring reconstruction.
- Answers every query in `O(1)` after preprocessing.
- All computations are performed modulo:
  ```cpp
  10^9 + 7
  ```
- This is the standard optimal solution for the problem.
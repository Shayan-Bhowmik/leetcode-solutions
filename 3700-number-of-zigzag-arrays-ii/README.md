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

# Solution: Matrix Exponentiation on DP States

## Solution Overview

The previous dynamic programming solution performs transitions between:

```cpp
up states
```

and

```cpp
down states
```

for every array length.

When `n` becomes very large, iterating through all lengths is too expensive.

This solution converts the DP transitions into a **matrix multiplication problem** and uses **fast matrix exponentiation** to compute the answer efficiently.

Key ideas:
- Represent every DP state as a node.
- Build a transition matrix.
- Raise the matrix to the power:

  ```cpp
  n - 2
  ```

- Apply the resulting transitions to the base states.
- Sum all resulting states.

---

## State Definition

Let:

```cpp
m = r - l + 1
```

Possible values are:

```cpp
1 ... m
```

For each value we maintain two states:

### Down State

```cpp
down[x]
```

The last comparison is decreasing.

---

### Up State

```cpp
up[x]
```

The last comparison is increasing.

---

Total states:

```cpp
2 * m
```

---

## State Indexing

### Down State ID

```cpp
downId(x) = x - 1
```

---

### Up State ID

```cpp
upId(x) = m + x - 1
```

---

## Transition Matrix

Create:

```cpp
T[states][states]
```

where:

```cpp
states = 2 * m
```

---

### Transition: Up → Down

If:

```cpp
y < x
```

then a decreasing move is possible.

Add:

```cpp
T[upId(y)][downId(x)] = 1
```

---

### Transition: Down → Up

If:

```cpp
y > x
```

then an increasing move is possible.

Add:

```cpp
T[downId(y)][upId(x)] = 1
```

---

## Base Vector

For arrays of length:

```cpp
2
```

initialize:

### Down States

```cpp
base[downId(x)] = x - 1
```

because there are:

```cpp
x - 1
```

smaller values that can precede `x`.

---

### Up States

```cpp
base[upId(x)] = m - x
```

because there are:

```cpp
m - x
```

larger values that can precede `x`.

---

## Matrix Exponentiation

To extend arrays from length:

```cpp
2
```

to length:

```cpp
n
```

we need:

```cpp
n - 2
```

transition steps.

Compute:

```cpp
P = T^(n - 2)
```

using binary exponentiation.

---

## Matrix Multiplication

For matrices:

```cpp
A × B
```

compute:

```cpp
C[i][j]
=
Σ A[i][k] * B[k][j]
```

modulo:

```cpp
10^9 + 7
```

The implementation skips zero entries for efficiency.

---

## Fast Exponentiation

Initialize:

```cpp
ans = Identity Matrix
```

While:

```cpp
exp > 0
```

- If the current bit is set:

  ```cpp
  ans = ans * base
  ```

- Square the matrix:

  ```cpp
  base = base * base
  ```

- Move to the next bit:

  ```cpp
  exp >>= 1
  ```

This computes:

```cpp
T^(n-2)
```

in logarithmic time.

---

## Compute Final States

Apply:

```cpp
finalState = P × base
```

For every state:

```cpp
finalState[i]
=
Σ P[i][j] * base[j]
```

---

## Compute Answer

Sum all reachable states:

```cpp
ans += finalState[i]
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

and

```cpp
S = 2m
```

be the number of states.

---

### Matrix Construction

```cpp
O(S²)
```

---

### Matrix Multiplication

```cpp
O(S³)
```

---

### Matrix Exponentiation

```cpp
O(S³ log n)
```

---

### Space Complexity

Transition matrix:

```cpp
O(S²)
```

Result matrix:

```cpp
O(S²)
```

Overall:

```cpp
O(S²)
```

---

## Notes

- Converts DP transitions into a graph of states.
- Uses matrix exponentiation to handle very large values of `n`.
- Binary exponentiation reduces repeated transition computation.
- Supports logarithmic dependence on `n`.
- All calculations are performed modulo:
  ```cpp
  10^9 + 7
  ```
- Represents:
  - increasing states (`up`)
  - decreasing states (`down`)
- This is the optimized solution for large-length ZigZag array counting.
- Matrix exponentiation is a standard technique for accelerating linear DP transitions.
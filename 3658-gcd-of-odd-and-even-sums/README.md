# GCD of Odd and Even Sums

## Problem Statement

You are given an integer:

```cpp
n
```

Consider:

- The sum of the first `n` odd numbers.
- The sum of the first `n` even numbers.

Return the **Greatest Common Divisor (GCD)** of these two sums.

---

# Solution: Mathematical Formula + Euclidean Algorithm

## Solution Overview

Instead of generating the odd and even numbers individually, this solution uses known mathematical formulas.

Key ideas:
- The sum of the first `n` odd numbers is:
  ```cpp
  n²
  ```
- The sum of the first `n` even numbers is:
  ```cpp
  n(n + 1)
  ```
- Compute both sums directly.
- Return their greatest common divisor using the built-in:
  ```cpp
  gcd()
  ```

This avoids unnecessary iteration and provides an efficient solution.

---

## Mathematical Formula

### Sum of First `n` Odd Numbers

The sequence is:

```text
1, 3, 5, 7, ...
```

Its sum is:

```cpp
n²
```

Example:

```text
1 + 3 + 5 + 7 + 9 = 25 = 5²
```

---

### Sum of First `n` Even Numbers

The sequence is:

```text
2, 4, 6, 8, ...
```

Its sum is:

```cpp
n(n + 1)
```

Example:

```text
2 + 4 + 6 + 8 = 20 = 4 × 5
```

---

## Algorithm

### Step 1: Compute Odd Sum

Using the formula:

```cpp
oddSum = n * n;
```

---

### Step 2: Compute Even Sum

Using the formula:

```cpp
evenSum = n * (n + 1);
```

---

### Step 3: Compute GCD

Return:

```cpp
gcd(oddSum, evenSum);
```

using the built-in Euclidean Algorithm.

---

## Complexity Analysis

### Time Complexity

Computing both sums:

```cpp
O(1)
```

Computing the GCD:

```cpp
O(log n)
```

Overall:

```cpp
O(log n)
```

---

### Space Complexity

```cpp
O(1)
```

---

## Notes

- Uses mathematical formulas instead of explicitly generating numbers.
- The sum of the first `n` odd numbers is:
  ```cpp
  n²
  ```
- The sum of the first `n` even numbers is:
  ```cpp
  n(n + 1)
  ```
- The built-in `gcd()` function efficiently computes the greatest common divisor using the Euclidean Algorithm.
- Requires constant extra space.
- This is the standard optimal solution for the problem.
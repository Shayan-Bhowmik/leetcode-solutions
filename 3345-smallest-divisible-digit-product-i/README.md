# Smallest Divisible Digit Product I

## Problem Statement

You are given two integers:

```cpp
n
```

and

```cpp
t
```

Find the smallest integer greater than or equal to:

```cpp
n
```

such that the **product of its digits** is divisible by:

```cpp
t
```

Return that integer.

---

# Solution: Brute Force Search

## Solution Overview

This solution checks every integer starting from:

```cpp
n
```

until it finds one whose digit product is divisible by:

```cpp
t
```

For each number:
- Compute the product of its digits.
- Check whether the product is divisible by `t`.
- If yes, return the current number.
- Otherwise, increment the number and continue.

Since the first valid number is returned immediately, the algorithm guarantees the correct answer.

---

## Algorithm

### Step 1: Start from `n`

Begin checking numbers from:

```cpp
n
```

using an infinite loop:

```cpp
while (true)
```

---

### Step 2: Compute the Product of Digits

Copy the current number:

```cpp
x = n;
```

Initialize:

```cpp
prod = 1;
```

Extract each digit using:

```cpp
x % 10
```

Multiply it into the product:

```cpp
prod *= (x % 10);
```

Remove the last digit:

```cpp
x /= 10;
```

Continue until all digits are processed.

---

### Step 3: Check Divisibility

If:

```cpp
prod % t == 0
```

the current number satisfies the condition.

Return:

```cpp
n;
```

---

### Step 4: Try the Next Number

Otherwise:

```cpp
n++;
```

Repeat the process.

---

## Why This Works

The algorithm checks every integer in increasing order starting from `n`.

For each number, it correctly computes the product of its digits and verifies whether it is divisible by `t`.

Since numbers are examined sequentially, the **first valid number found is guaranteed to be the smallest**.

---

## Complexity Analysis

Let:

```cpp
d = number of digits
```

and let:

```cpp
k
```

be the number of integers checked before finding the answer.

### Time Complexity

Computing the digit product for one number:

```cpp
O(d)
```

Checking `k` numbers:

```cpp
O(k × d)
```

---

### Space Complexity

Only a few integer variables are used.

```cpp
O(1)
```

---

## Notes

- Uses a straightforward brute-force search.
- Computes the product of digits using repeated modulo and division operations.
- Checks numbers in increasing order, ensuring the first valid one is the smallest.
- Requires constant extra space.
- Suitable because the constraints for this version of the problem are small.
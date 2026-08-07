# Smallest Divisible Digit Product II

## Problem Statement

You are given:

```cpp
string num
```

representing a positive integer and an integer:

```cpp
t
```

Find the **smallest integer greater than or equal to** `num` such that:

- It contains **no digit `0`**.
- The **product of its digits** is divisible by `t`.

Return the resulting number as a string.

If no such number exists, return:

```cpp
"-1"
```

---

# Solution: Greedy + Dynamic Programming + Prime Factorization

## Solution Overview

Since every digit from **1 to 9** only contributes the prime factors:

```text
2, 3, 5, 7
```

the problem becomes one of satisfying the required prime exponents of `t`.

The algorithm works in four major stages:

1. Factorize `t`.
2. Precompute the minimum number of digits needed to satisfy any remaining powers of `2` and `3`.
3. Try modifying the given number while keeping it as small as possible.
4. If impossible, construct the smallest valid longer number.

---

## Step 1: Prime Factorization

Factorize:

```cpp
t
```

into

```text
2^a × 3^b × 5^c × 7^d
```

Store:

```cpp
req2
req3
req5
req7
```

If another prime factor remains:

```cpp
temp > 1
```

return

```cpp
"-1"
```

because no digit from `1` to `9` can contribute primes larger than `7`.

---

## Step 2: Digit Contributions

Every digit contributes fixed prime factors.

| Digit | 2 | 3 | 5 | 7 |
|------:|--:|--:|--:|--:|
|1|0|0|0|0|
|2|1|0|0|0|
|3|0|1|0|0|
|4|2|0|0|0|
|5|0|0|1|0|
|6|1|1|0|0|
|7|0|0|0|1|
|8|3|0|0|0|
|9|0|2|0|0|

These values are stored in:

```cpp
F2[]
F3[]
F5[]
F7[]
```

---

## Step 3: DP for Powers of 2 and 3

The hardest part is satisfying the remaining powers of:

```text
2
```

and

```text
3
```

The DP state is:

```cpp
dp[i][j]
```

which represents the **minimum number of digits** needed to produce at least:

- `i` factors of `2`
- `j` factors of `3`

Transitions use the six useful digits:

```text
2
3
4
6
8
9
```

because they contribute factors of `2` and `3`.

After computing the DP, suffix minimization ensures:

```cpp
dp[i][j]
```

also works for larger exponents.

---

## Step 4: Check Whether `num` Already Works

If `num` contains no zero:

- Remove the contribution of every digit.
- Reduce the required prime exponents.

If every requirement becomes zero:

```cpp
return num;
```

---

## Step 5: Modify the Number

If the current number is not valid:

Traverse from right to left.

For every position:

- Increase the current digit.
- Compute the remaining required prime exponents.
- Determine whether the remaining suffix has enough positions to satisfy them.

The feasibility condition is:

```cpp
remaining7 +
remaining5 +
dp[remaining2][remaining3]
<= suffixLength
```

If possible:

- Fix the current digit.
- Greedily fill the remaining suffix with the smallest digits that keep the solution feasible.

This guarantees the smallest possible number greater than the original.

---

## Step 6: Build a Longer Number

If no valid number of the same length exists:

Determine the minimum required length:

```cpp
minimumLength =
req7 +
req5 +
dp[req2][req3]
```

The final length is:

```cpp
max(originalLength + 1,
    minimumLength)
```

Then greedily construct the lexicographically smallest valid number digit by digit.

---

## Why the Greedy Construction Works

While filling each position:

Try digits:

```text
1 → 9
```

For every candidate digit:

- Reduce the remaining required prime exponents.
- Check whether the remaining positions are sufficient.

If yes:

- Choose that digit immediately.

Because digits are considered in increasing order, the first feasible choice always produces the lexicographically smallest answer.

---

## Why Dynamic Programming Works

The DP answers the question:

> "How many digits are minimally required to satisfy the remaining powers of 2 and 3?"

Without DP, every greedy decision would require exploring exponentially many suffixes.

The DP compresses this information into constant-time feasibility checks.

---

## Complexity Analysis

Let:

```cpp
n = num.length()
```

### Time Complexity

Prime factorization:

```cpp
O(log t)
```

DP construction:

```cpp
O(60 × 40 × 6)
```

which is constant.

Checking the original number:

```cpp
O(n)
```

Greedy replacement:

```cpp
O(9n)
```

Constructing the final answer:

```cpp
O(9n)
```

Overall:

```cpp
O(n + log t)
```

---

### Space Complexity

DP table:

```cpp
O(60 × 40)
```

Frequency arrays:

```cpp
O(1)
```

Output string:

```cpp
O(n)
```

Overall:

```cpp
O(n)
```

---

## Notes

- Factorizes `t` into powers of **2, 3, 5, and 7**.
- Returns `"-1"` immediately if `t` contains any other prime factor.
- Uses precomputed digit contributions for every digit from `1` to `9`.
- Employs Dynamic Programming to determine the minimum digits required to satisfy remaining powers of `2` and `3`.
- Greedily modifies the given number from right to left to obtain the smallest valid number of the same length.
- If impossible, constructs the smallest valid longer number.
- Combines **prime factorization, dynamic programming, and greedy construction** to achieve an efficient solution.
- This is the standard optimal solution for the problem.
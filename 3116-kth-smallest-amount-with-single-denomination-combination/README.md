# K-th Smallest Amount With Single Denomination Combination

## Problem Statement

You are given an array:

```cpp
coins
```

where each value represents a coin denomination.

You can use **any positive number of coins of one denomination**, so a number is obtainable if it is divisible by at least one coin denomination.

You need to find the:

```text
k-th smallest positive integer
```

that is divisible by at least one value in `coins`.

---

# Solution: Inclusion-Exclusion + Binary Search

## Solution Overview

Suppose:

```text
coins = [2, 3]
```

The positive integers divisible by at least one coin are:

```text
2, 3, 4, 6, 8, 9, 10, 12, ...
```

The answer is the `k`-th number in this sequence.

The problem is that simply adding:

```text
mid / 2 + mid / 3
```

double-counts numbers divisible by both `2` and `3`.

For example:

```text
6
```

is counted twice.

So we use the **Inclusion-Exclusion Principle**.

Then we use **Binary Search** to find the smallest value `mid` for which at least `k` valid numbers exist.

---

# Step 1: Remove Redundant Coins

First, the coins are sorted:

```cpp
ranges::sort(coins);
```

Then:

```cpp
vector<int> A;

for (auto& c : coins)
    if (ranges::none_of(A, [&](int x) {
        return !(c % x);
    }))
        A.push_back(c);
```

The purpose is to remove denominations that are multiples of smaller denominations.

For example:

```text
coins = [2, 4, 8]
```

Every number divisible by `4` is already divisible by `2`.

Similarly, every number divisible by `8` is already divisible by `2`.

So we only need:

```text
A = [2]
```

This reduces the number of subsets that inclusion-exclusion needs to consider.

---

# Step 2: Binary Search

We need to find the smallest number `mid` such that:

```text
count(mid) >= k
```

where:

```text
count(mid)
```

is the number of positive integers `<= mid` divisible by at least one coin.

The search range is:

```cpp
ll low = k;
ll high = 1ll * A[0] * k;
```

### Why `low = k`?

The k-th positive integer cannot be smaller than `k`.

### Why `high = A[0] * k`?

Every multiple of the smallest coin:

```text
A[0]
```

is valid.

Therefore the `k`-th valid number cannot be greater than:

```text
A[0] * k
```

---

# Step 3: Count Valid Numbers

The key function is:

```cpp
auto check = [&](ll mid)
```

It determines whether there are at least `k` valid numbers up to `mid`.

For each subset of denominations, we calculate the LCM of those denominations.

If a number is divisible by all coins in a subset, it is divisible by:

```text
LCM(coins in subset)
```

Therefore:

```cpp
mid / LCM
```

is the number of integers `<= mid` divisible by all denominations in that subset.

---

# Inclusion-Exclusion

Suppose:

```text
coins = [2, 3, 5]
```

The count of numbers divisible by at least one denomination is:

```text
floor(mid/2)
+ floor(mid/3)
+ floor(mid/5)

- floor(mid/lcm(2,3))
- floor(mid/lcm(2,5))
- floor(mid/lcm(3,5))

+ floor(mid/lcm(2,3,5))
```

This follows the inclusion-exclusion principle.

---

# Sign of Each Subset

For a subset containing:

```text
i
```

coins:

- If `i` is odd → add the count.
- If `i` is even → subtract the count.

The code:

```cpp
((i & 1) << 1) - 1
```

implements exactly this.

### If `i` is odd

```cpp
i & 1 = 1
```

so:

```text
(1 << 1) - 1
= 2 - 1
= +1
```

### If `i` is even

```cpp
i & 1 = 0
```

so:

```text
(0 << 1) - 1
= -1
```

Therefore:

```cpp
tot += (mid / x) * sign;
```

correctly applies inclusion-exclusion.

---

# Step 4: Generate Every Subset

The code:

```cpp
for (int i = 1; i <= n; i++) {
    int q = (1 << i) - 1;

    while (q < 1 << n) {
        ...
    }
}
```

generates every subset containing exactly `i` elements.

For example, if:

```text
n = 3
```

the subsets are:

```text
{0}
{1}
{2}

{0,1}
{0,2}
{1,2}

{0,1,2}
```

The bitmask `q` represents which denominations are selected.

---

# Understanding the Bitmask

Suppose:

```text
A = [2, 3, 5]
```

and:

```text
q = 101₂
```

The bits indicate:

```text
bit 0 → 2 selected
bit 1 → 3 not selected
bit 2 → 5 selected
```

So this subset is:

```text
{2, 5}
```

Its LCM is:

```text
LCM(2,5) = 10
```

Therefore:

```cpp
mid / 10
```

numbers are divisible by both.

---

# Step 5: Calculate the LCM

For every selected denomination:

```cpp
if ((q >> j) & 1)
    x = lcm(x, A[j]);
```

Initially:

```cpp
x = 1;
```

and the LCM is built incrementally.

For example:

```text
A = [2, 3, 5]
subset = {2,3,5}
```

gives:

```text
x = lcm(1,2)
  = 2

x = lcm(2,3)
  = 6

x = lcm(6,5)
  = 30
```

So:

```text
mid / 30
```

numbers are divisible by all three.

---

# Step 6: Check Whether We Have Enough Numbers

After applying inclusion-exclusion:

```cpp
return tot >= k;
```

If:

```text
tot >= k
```

then the answer is at most `mid`.

So binary search moves left.

Otherwise:

```text
tot < k
```

and we need a larger number.

---

# Step 7: Binary Search for the First Valid Value

The final expression:

```cpp
ranges::lower_bound(
    views::iota(low, high + 1),
    true,
    {},
    [&](ll mid) {
        return check(mid);
    }
)
```

finds the **first `mid` for which `check(mid)` is true**.

In other words:

```text
smallest mid such that count(mid) >= k
```

which is exactly the k-th valid number.

---

# Example

Suppose:

```text
coins = [2, 3]
k = 5
```

The valid numbers are:

```text
2, 3, 4, 6, 8, 9, ...
```

We need:

```text
answer = 8
```

For a candidate:

```text
mid = 8
```

Count numbers divisible by `2`:

```text
8 / 2 = 4
```

Count numbers divisible by `3`:

```text
8 / 3 = 2
```

Numbers divisible by both:

```text
LCM(2,3) = 6

8 / 6 = 1
```

Therefore:

```text
count = 4 + 2 - 1
      = 5
```

Since:

```text
5 >= k
```

`8` is a valid candidate.

Binary search finds it as the smallest such candidate.

---

# Why Remove Redundant Coins?

Consider:

```text
coins = [2, 4, 8, 16]
```

Every number divisible by `4`, `8`, or `16` is already divisible by `2`.

So all of these denominations describe the same set of valid numbers as:

```text
coins = [2]
```

Removing redundant denominations dramatically reduces the number of subsets.

Since inclusion-exclusion considers subsets, reducing:

```text
n
```

is very important.

---

# Complexity Analysis

Let:

```cpp
n = number of remaining denominations
```

after removing redundant coins.

There are:

```text
2^n - 1
```

non-empty subsets.

For each subset, the code calculates an LCM across up to `n` denominations.

Therefore, the inclusion-exclusion check is roughly:

```text
O(n × 2^n)
```

in the straightforward analysis.

The binary search performs approximately:

```text
O(log(high))
```

checks.

Therefore:

```text
O(n × 2^n × log(high))
```

approximately.

Because the number of useful coin denominations is small under the problem constraints, this is feasible.

---

### Space Complexity

The reduced denomination array uses:

```text
O(n)
```

space.

The subset generation itself uses constant extra space.

So:

```text
O(n)
```

additional space.

---

# Notes

- Uses **Binary Search + Inclusion-Exclusion + LCM**.
- First removes coin denominations that are multiples of smaller denominations.
- `check(mid)` counts how many valid integers are `<= mid`.
- Inclusion-exclusion prevents numbers divisible by multiple coins from being counted multiple times.
- For a subset:
  ```cpp
  mid / LCM(subset)
  ```
  gives the number divisible by every coin in that subset.
- Odd-sized subsets are added.
- Even-sized subsets are subtracted.
- Binary search finds the smallest `mid` with at least `k` valid numbers.
- Time complexity is approximately **O(n × 2ⁿ × log(high))**.
- Space complexity is **O(n)**.
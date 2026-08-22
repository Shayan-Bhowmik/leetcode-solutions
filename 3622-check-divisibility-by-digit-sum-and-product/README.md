# Check Divisibility by Digit Sum + Digit Product

## Problem Statement

You are given a positive integer:

```cpp
n
```

Calculate:

1. The **sum of its digits**.
2. The **product of its digits**.
3. Add these two values together.
4. Check whether `n` is divisible by this sum.

Return:

```cpp
true
```

if:

```text
n % (digitSum + digitProduct) == 0
```

otherwise return:

```cpp
false
```

---

# Solution: Digit Extraction

## Solution Overview

We can extract the digits of `n` one by one using:

```cpp
n % 10
```

and then remove the last digit using:

```cpp
n / 10
```

For example:

```text
n = 123
```

### Extract `3`

```text
123 % 10 = 3
```

Then:

```text
123 / 10 = 12
```

### Extract `2`

```text
12 % 10 = 2
```

Then:

```text
12 / 10 = 1
```

### Extract `1`

```text
1 % 10 = 1
```

Then:

```text
1 / 10 = 0
```

Now all digits have been processed.

---

# Step 1: Store a Copy of `n`

```cpp
int use_n = n;
```

We need to repeatedly divide the number by `10`, so we use a copy.

This keeps the original:

```cpp
n
```

unchanged for the final divisibility check.

---

# Step 2: Initialize Sum and Product

```cpp
int sum = 0;
long long prod = 1;
```

We start with:

```text
sum = 0
```

because we are adding digits.

We start with:

```text
prod = 1
```

because `1` is the multiplicative identity.

---

# Step 3: Extract Every Digit

```cpp
while(use_n > 0) {
    digit = use_n % 10;

    sum += digit;
    prod *= digit;

    use_n = use_n / 10;
}
```

For every digit:

```cpp
use_n % 10
```

extracts the last digit.

Then:

```cpp
use_n /= 10;
```

removes that digit.

---

# Example

Consider:

```text
n = 123
```

### Digit Sum

```text
1 + 2 + 3 = 6
```

### Digit Product

```text
1 × 2 × 3 = 6
```

Therefore:

```text
sum + prod = 6 + 6 = 12
```

Now check:

```text
123 % 12
```

which is not `0`.

Therefore:

```text
answer = false
```

---

# Step 4: Calculate the Divisor

After processing all digits:

```cpp
int ans = sum + prod;
```

So:

```text
ans = digitSum + digitProduct
```

---

# Step 5: Check Divisibility

Finally:

```cpp
if(n % ans == 0) {
    return true;
}
```

If:

```text
n % (sum + product) == 0
```

then `n` is divisible by the required value.

Otherwise:

```cpp
return false;
```

---

# Example 2

Consider:

```text
n = 15
```

Digit sum:

```text
1 + 5 = 6
```

Digit product:

```text
1 × 5 = 5
```

Therefore:

```text
sum + product = 11
```

Check:

```text
15 % 11 != 0
```

So:

```text
false
```

---

# Example 3

Consider:

```text
n = 22
```

Digit sum:

```text
2 + 2 = 4
```

Digit product:

```text
2 × 2 = 4
```

Therefore:

```text
4 + 4 = 8
```

Since:

```text
22 % 8 != 0
```

the answer is:

```text
false
```

---

# Important Detail: Why `prod` Is `long long`

You used:

```cpp
long long prod = 1;
```

This is a good choice.

The product of digits can become larger than what we want to store in a small integer type for sufficiently large `n`.

So:

```cpp
long long
```

provides a safer range.

---

# Complexity Analysis

Let:

```text
d = number of digits in n
```

We process every digit exactly once.

### Time Complexity

```text
O(d)
```

Since:

```text
d = O(log₁₀ n)
```

we can also write:

```text
O(log n)
```

---

### Space Complexity

Only a few variables are used:

```text
O(1)
```

---

## Notes

- Uses **digit extraction** with `% 10` and `/ 10`.
- `sum` stores the digit sum.
- `prod` stores the digit product.
- The required divisor is:
  ```cpp
  sum + prod
  ```
- Finally check:
  ```cpp
  n % (sum + prod) == 0
  ```
- Time complexity: **O(log n)**.
- Space complexity: **O(1)**.
- Your solution is correct for LeetCode 3622.
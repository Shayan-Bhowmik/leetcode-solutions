# Maximum Product of Two Digits

## Problem Statement

Given a positive integer:

```cpp
n
```

find the two largest digits present in the number and return their product.

---

# Solution: Single Pass Digit Traversal

## Solution Overview

This solution scans the digits of the number exactly once while maintaining the two largest digits encountered.

Key ideas:
- Extract each digit using the modulo operator.
- Keep track of the largest and second largest digits.
- Update these values whenever a larger digit is found.
- Return the product of the two largest digits.

Since each digit is processed only once, the solution is efficient and requires constant extra space.

---

## Algorithm

### Step 1: Initialize Variables

Maintain two variables:

```cpp
first = 0;
second = 0;
```

where:

- `first` stores the largest digit.
- `second` stores the second largest digit.

---

### Step 2: Traverse All Digits

While the number is greater than zero:

```cpp
while (n > 0)
```

extract the last digit:

```cpp
d = n % 10;
```

---

### Step 3: Update the Largest Digits

If the current digit is greater than the largest digit seen so far:

```cpp
if (d > first)
```

move the current largest digit to `second`:

```cpp
second = first;
first = d;
```

Otherwise, if the digit is larger than the second largest:

```cpp
else if (d > second)
```

update:

```cpp
second = d;
```

---

### Step 4: Remove the Last Digit

Continue processing by removing the last digit:

```cpp
n /= 10;
```

---

### Step 5: Return the Result

The required answer is:

```cpp
first * second;
```

---

## Why This Works

At every step:

- `first` always stores the largest digit encountered.
- `second` always stores the second largest digit encountered.

Whenever a new maximum digit appears, the previous maximum automatically becomes the second largest.

Thus, after processing all digits, the product of `first` and `second` is the maximum possible product of any two digits in the number.

---

## Complexity Analysis

Let:

```cpp
d = number of digits in n
```

### Time Complexity

Each digit is processed exactly once.

```cpp
O(d)
```

---

### Space Complexity

Only two integer variables are maintained.

```cpp
O(1)
```

---

## Notes

- Traverses the digits of the number only once.
- Uses modulo (`%`) to extract the last digit.
- Maintains the largest and second largest digits throughout the traversal.
- Requires constant extra space.
- Runs in linear time with respect to the number of digits.
- This is the standard optimal solution for the problem.
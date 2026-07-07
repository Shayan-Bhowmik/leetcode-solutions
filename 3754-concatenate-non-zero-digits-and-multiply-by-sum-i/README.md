# Sum and Multiply

## Problem Statement

You are given an integer:

```cpp
n
```

Construct a new number by removing all digits equal to:

```cpp
0
```

from its decimal representation while preserving the order of the remaining digits.

Let:

- `sum` be the sum of the remaining digits.
- `number` be the integer formed by the remaining digits.

Return:

```cpp
number × sum
```

If all digits are zero, return:

```cpp
0
```

---

# Solution: String Processing

## Solution Overview

This solution processes the decimal representation of the given integer.

Key ideas:
- Convert the integer into a string.
- Traverse each digit once.
- Ignore all zero digits.
- Compute the sum of all non-zero digits.
- Build the new number by concatenating the remaining digits.
- Multiply the constructed number with the digit sum.

This directly follows the problem statement.

---

## Algorithm

### Step 1: Convert Number to String

Convert:

```cpp
n
```

into its string representation:

```cpp
string num_string = to_string(n);
```

---

### Step 2: Initialize Variables

Create:

```cpp
sum = 0;
```

to store the sum of non-zero digits.

Create:

```cpp
string str = "";
```

to build the new number.

---

### Step 3: Process Each Digit

Traverse every character in:

```cpp
num_string
```

If the digit is not:

```cpp
'0'
```

then:

- Add its numeric value to:

  ```cpp
  sum
  ```

- Append the digit to:

  ```cpp
  str
  ```

Otherwise, ignore the digit.

---

### Step 4: Handle Special Case

If:

```cpp
str.empty()
```

then every digit was zero.

Return:

```cpp
0
```

---

### Step 5: Construct the New Number

Convert:

```cpp
str
```

into an integer:

```cpp
long long number = stoll(str);
```

---

### Step 6: Return Answer

Compute:

```cpp
number * sum
```

and return the result.

---

## Complexity Analysis

Let:

```cpp
d = number of digits in n
```

### Time Complexity

Each digit is processed once.

```cpp
O(d)
```

---

### Space Complexity

The constructed string stores at most:

```cpp
d
```

digits.

Overall:

```cpp
O(d)
```

---

## Notes

- Uses string manipulation to simplify digit processing.
- Ignores every occurrence of the digit:
  ```cpp
  0
  ```
- Preserves the original order of the remaining digits.
- Computes the digit sum and reconstructed number simultaneously.
- Returns:
  ```cpp
  0
  ```
  when all digits are zero.
- Efficient linear-time solution.
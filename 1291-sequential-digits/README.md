# Sequential Digits

## Problem Statement

An integer has **sequential digits** if every digit is exactly one greater than the previous digit.

For example:

```text
123
4567
6789
```

are sequential digit numbers.

Given two integers:

```cpp
low
```

and

```cpp
high
```

return a sorted list of all sequential digit numbers in the inclusive range:

```cpp
[low, high]
```

---

# Solution: Generate All Sequential Numbers

## Solution Overview

This solution generates every possible sequential digit number instead of checking every number in the range.

Key ideas:
- Choose every possible starting digit from `1` to `8`.
- Continuously append the next consecutive digit.
- Whenever the generated number lies within the given range, add it to the answer.
- Finally, sort the generated numbers before returning them.

Since there are only a limited number of sequential digit numbers, this approach is very efficient.

---

## Algorithm

### Step 1: Initialize Answer

Create an empty vector:

```cpp
vector<int> ans;
```

to store all valid sequential numbers.

---

### Step 2: Choose Starting Digit

Traverse every possible starting digit:

```cpp
start = 1 ... 8
```

Initialize:

```cpp
num = start;
```

---

### Step 3: Build Sequential Numbers

Append consecutive digits one by one:

```cpp
num = num * 10 + next;
```

where:

```cpp
next = start + 1 ... 9
```

This generates numbers such as:

```text
12
123
1234
12345
...
```

---

### Step 4: Check the Range

Whenever:

```cpp
low <= num <= high
```

store the number:

```cpp
ans.push_back(num);
```

---

### Step 5: Sort the Result

Since numbers are generated from different starting digits, sort the answer:

```cpp
sort(ans.begin(), ans.end());
```

---

### Step 6: Return Answer

Return:

```cpp
ans;
```

---

## Complexity Analysis

There are only **36** possible sequential digit numbers.

### Time Complexity

Generating all candidates:

```cpp
O(1)
```

Sorting at most 36 numbers:

```cpp
O(1)
```

Overall:

```cpp
O(1)
```

---

### Space Complexity

The answer stores at most 36 numbers.

```cpp
O(1)
```

---

## Notes

- Generates sequential digit numbers directly instead of checking every integer in the range.
- Starts from every possible leading digit between `1` and `8`.
- Consecutive digits are appended until `9` is reached.
- Only numbers within the given range are added to the answer.
- The final list is sorted before returning.
- Since the total number of sequential digit numbers is fixed, both the time and space complexity are effectively constant.
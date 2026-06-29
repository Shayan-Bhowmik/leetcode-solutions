# Number of Strings That Appear as Substrings in Word

## Problem Statement

Given an array of strings `patterns` and a string `word`, return the number of strings in `patterns` that appear as a substring of `word`.

A substring is a contiguous sequence of characters within a string.

---

# Solution: Substring Search

## Solution Overview

This solution checks each string in `patterns` to determine whether it appears as a substring of `word`.

Key ideas:
- Traverse every pattern in the array.
- Use the built-in string function:
  ```cpp
  contains()
  ```
  to check if the pattern exists inside `word`.
- Count every pattern that is found.
- Return the total count.

This directly follows the problem statement.

---

## Algorithm

### Step 1: Initialize Counter

Create:

```cpp
count = 0;
```

to store the number of matching patterns.

---

### Step 2: Traverse All Patterns

For every string:

```cpp
p
```

in:

```cpp
patterns
```

check whether:

```cpp
word.contains(p)
```

returns `true`.

---

### Step 3: Update Answer

If the pattern exists as a substring:

```cpp
count++;
```

---

### Step 4: Return Result

Return:

```cpp
count;
```

---

## Complexity Analysis

Let:

```cpp
n = patterns.size()
```

Let:

```cpp
m = word.length()
```

Let:

```cpp
L
```

be the average length of a pattern.

### Time Complexity

Each pattern performs one substring search.

Overall:

```cpp
O(n × m)
```

(using the average complexity of the built-in substring search).

---

### Space Complexity

```cpp
O(1)
```

Only a counter variable is used.

---

## Notes

- Uses the built-in:
  ```cpp
  string::contains()
  ```
  function for substring checking (available in C++23).
- Each pattern is checked independently.
- A pattern contributes to the answer if it appears anywhere in `word`.
- Simple and easy-to-understand solution.
- This is an efficient solution for the given constraints.
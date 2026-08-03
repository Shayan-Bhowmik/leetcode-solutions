# Count Valid Prefixes

## Problem Statement

You are given a binary string:

```cpp
s
```

A prefix of the string is considered **valid** if the absolute difference between the number of `'0'`s and `'1'`s in that prefix is at most `1`.

Return the total number of valid prefixes.

---

# Solution: Prefix Counting

## Solution Overview

This solution scans the string from left to right while maintaining the count of:

- `'0'` characters
- `'1'` characters

For every prefix, it checks whether the difference between these counts is at most `1`. If so, the prefix is valid and contributes to the answer.

Since each character is processed exactly once, the solution is efficient.

---

## Algorithm

### Step 1: Initialize Variables

Maintain three variables:

```cpp
count_zero = 0;
count_one = 0;
ans = 0;
```

where:

- `count_zero` stores the number of `'0'`s seen so far.
- `count_one` stores the number of `'1'`s seen so far.
- `ans` stores the number of valid prefixes.

---

### Step 2: Traverse the String

For every character:

```cpp
c
```

- If it is:

```cpp
'0'
```

increment:

```cpp
count_zero++;
```

- Otherwise, increment:

```cpp
count_one++;
```

---

### Step 3: Check Prefix Validity

For the current prefix, compute:

```cpp
abs(count_zero - count_one)
```

If:

```cpp
abs(count_zero - count_one) <= 1
```

the prefix is valid.

Increment:

```cpp
ans++;
```

---

### Step 4: Return the Answer

After processing all prefixes, return:

```cpp
ans;
```

---

## Why This Works

Every iteration extends the current prefix by one character.

The algorithm always knows:

- how many `'0'`s have appeared,
- how many `'1'`s have appeared.

Therefore, it can immediately determine whether the current prefix satisfies:

```cpp
|count_zero - count_one| <= 1
```

Every prefix is checked exactly once.

---

## Complexity Analysis

Let:

```cpp
n = s.length()
```

### Time Complexity

Each character is processed once.

```cpp
O(n)
```

---

### Space Complexity

Only three integer variables are maintained.

```cpp
O(1)
```

---

## Notes

- Uses prefix counting to maintain the number of `'0'`s and `'1'`s.
- Checks every prefix independently during a single traversal.
- A prefix is valid if the absolute difference between the counts of `'0'`s and `'1'`s is at most `1`.
- Requires constant extra space.
- Runs in linear time.
- This is the standard optimal solution for the problem.
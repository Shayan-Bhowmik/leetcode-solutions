# Find the K-th Character in Processed String

## Problem Statement

You are given a string `s` consisting of lowercase English letters and special operation characters:

- `'*'`
- `'#'`
- `'%'`

The string is processed from left to right according to the following rules:

- Lowercase letter:
  - Append the character to the result string.
- `'*'`:
  - Remove the last character of the result string if it exists.
- `'#'`:
  - Duplicate the current result string and append it to itself.
- `'%'`:
  - Reverse the current result string.

Given an index `k`, return the character at position `k` in the final processed string.

If `k` is outside the bounds of the final string, return:

```cpp
'.'
```

---

# Solution: Reverse Simulation Without Building the String

## Solution Overview

Building the final string directly can cause **Memory Limit Exceeded (MLE)** because the `'#'` operation can repeatedly double the string size.

This solution avoids constructing the final string.

Key ideas:
- First compute only the final length.
- Process the operations in reverse.
- Track where the required index `k` originated.
- Undo each operation one by one.
- Once a character insertion is reached, determine whether it corresponds to the target position.

This allows finding the answer while using constant extra memory.

---

## Algorithm

### Step 1: Compute Final Length

Traverse the string from left to right.

Maintain:

```cpp
len
```

representing the current processed string length.

#### Letter

```cpp
len++
```

#### '*'

```cpp
if(len > 0)
    len--;
```

#### '#'

```cpp
len *= 2;
```

#### '%'

Length remains unchanged.

---

### Step 2: Check Bounds

If:

```cpp
k >= len
```

return:

```cpp
'.'
```

because the position does not exist.

---

### Step 3: Traverse Operations in Reverse

Process characters from:

```cpp
s.size() - 1
```

to:

```cpp
0
```

Undo each operation.

---

### Case 1: '#'

Originally:

```cpp
oldString + oldString
```

Current length:

```cpp
len
```

Original length:

```cpp
oldLen = len / 2
```

If:

```cpp
k >= oldLen
```

then the character lies in the second copy:

```cpp
k -= oldLen;
```

Update:

```cpp
len = oldLen;
```

---

### Case 2: '%'

The string was reversed.

Undo the reversal:

```cpp
k = len - 1 - k;
```

---

### Case 3: '*'

Originally one character existed before deletion.

Undo deletion:

```cpp
len++;
```

If:

```cpp
k == len - 1
```

the queried position corresponds to the deleted character.

Return:

```cpp
'.'
```

---

### Case 4: Letter

A character was appended.

Undo append:

```cpp
len--;
```

If:

```cpp
k == len
```

the current letter is exactly the target character.

Return:

```cpp
c
```

---

### Step 4: Return Answer

If no character is found:

```cpp
return '.';
```

---

## Complexity Analysis

Let:

```cpp
n = s.length()
```

### Time Complexity

First pass:

```cpp
O(n)
```

Reverse pass:

```cpp
O(n)
```

Overall:

```cpp
O(n)
```

---

### Space Complexity

```cpp
O(1)
```

Only a few variables are maintained.

---

## Notes

- Avoids constructing the processed string.
- Handles extremely large virtual string lengths efficiently.
- Reverse simulation traces the origin of index `k`.
- `'#'` is handled by mapping positions back to the original half.
- `'%'` is handled by reversing the index.
- `'*'` is handled by restoring the deleted position conceptually.
- This is the optimal solution for large constraints.
- Prevents both Memory Limit Exceeded (MLE) and Time Limit Exceeded (TLE).
# Map Word Weights

## Problem Statement

You are given:

- An array of strings `words`
- An array `weights` of size `26`, where:
  ```cpp
  weights[i]
  ```
  represents the weight of the character:

  ```cpp
  'a' + i
  ```

For each word:

1. Compute the sum of the weights of all its characters.
2. Let:

   ```cpp
   sum % 26
   ```

3. Map the result to a lowercase character using:

   ```cpp
   'z' - (sum % 26)
   ```

Return the resulting string formed by processing all words in order.

---

# Solution: Character Weight Aggregation

## Solution Overview

This solution processes each word independently and computes its total character weight.

Key ideas:
- For every character in a word, add its corresponding weight.
- Compute:
  ```cpp
  sum % 26
  ```
- Convert the result into a lowercase letter using:
  ```cpp
  'z' - (sum % 26)
  ```
- Append the generated character to the answer string.

The final answer contains one character for each word.

---

## Algorithm

### Step 1: Initialize Answer String

Create:

```cpp
string ans;
```

---

### Step 2: Process Every Word

For each word:

```cpp
word
```

initialize:

```cpp
sum = 0;
```

---

### Step 3: Compute Word Weight

For every character:

```cpp
ch
```

add:

```cpp
weights[ch - 'a']
```

to:

```cpp
sum
```

This gives the total weight of the word.

---

### Step 4: Generate Output Character

Compute:

```cpp
sum % 26
```

Convert into a character:

```cpp
'z' - (sum % 26)
```

Append it to:

```cpp
ans
```

---

### Step 5: Return Result

Return:

```cpp
ans
```

---

## Complexity Analysis

Let:

```cpp
n = words.size()
```

and

```cpp
L = total number of characters across all words
```

### Time Complexity

Every character is processed once:

```cpp
O(L)
```

---

### Space Complexity

Ignoring the output string:

```cpp
O(1)
```

Output storage:

```cpp
O(n)
```

---

## Notes

- Uses direct indexing:
  ```cpp
  ch - 'a'
  ```
  to access character weights.
- Each word contributes exactly one character to the result.
- The modulo operation keeps values within:
  ```cpp
  [0, 25]
  ```
- Character mapping is performed using:
  ```cpp
  'z' - (sum % 26)
  ```
- Efficient linear-time solution.
- Processes each character exactly once.
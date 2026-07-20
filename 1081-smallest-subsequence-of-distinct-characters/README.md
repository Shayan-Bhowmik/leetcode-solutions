# Smallest Subsequence of Distinct Characters

## Problem Statement

Given a string:

```cpp
s
```

return the **lexicographically smallest subsequence** of `s` that contains every distinct character exactly once.

A subsequence is obtained by deleting zero or more characters without changing the relative order of the remaining characters.

---

# Solution: Monotonic Stack + Greedy

## Solution Overview

This solution uses a **greedy approach** with a **monotonic stack** to build the smallest possible subsequence.

Key ideas:
- Count how many times each character appears.
- Maintain a stack representing the current subsequence.
- Keep track of characters already included.
- Before inserting a character, remove larger characters from the stack if they appear again later.
- This guarantees the resulting subsequence is lexicographically smallest while containing each distinct character exactly once.

---

## Algorithm

### Step 1: Count Character Frequencies

Create a frequency array:

```cpp
freq[26]
```

Store how many times each character appears in the string.

---

### Step 2: Maintain Visited Characters

Create a boolean array:

```cpp
visited[26]
```

where:

```cpp
visited[c]
```

indicates whether the character is already present in the current subsequence.

---

### Step 3: Traverse the String

For every character:

```cpp
c
```

decrease its remaining frequency:

```cpp
freq[c - 'a']--;
```

If the character is already in the subsequence:

```cpp
continue;
```

---

### Step 4: Maintain Lexicographical Order

While all of the following conditions hold:

- The stack is not empty.
- The current character is smaller than the top of the stack.
- The top character appears again later in the string.

```cpp
while (!st.empty() &&
       c < st.back() &&
       freq[st.back() - 'a'] > 0)
```

remove the top character:

```cpp
visited[st.back() - 'a'] = false;
st.pop_back();
```

This allows a smaller character to appear earlier in the answer.

---

### Step 5: Insert Current Character

Push the current character onto the stack:

```cpp
st.push_back(c);
```

Mark it as visited:

```cpp
visited[c - 'a'] = true;
```

---

### Step 6: Return Answer

The stack now contains the required subsequence.

Return:

```cpp
st;
```

---

## Why the Greedy Choice Works

Suppose the stack currently ends with:

```text
d
```

and the current character is:

```text
b
```

If:

- `b` is smaller than `d`, and
- `d` appears again later,

then placing `b` first always produces a lexicographically smaller answer.

Since `d` can be added later, removing it does not prevent it from appearing in the final subsequence.

This greedy decision is repeated for every character, producing the smallest valid subsequence.

---

## Complexity Analysis

Let:

```cpp
n = s.length()
```

### Time Complexity

Each character is pushed onto the stack at most once and popped at most once.

Overall:

```cpp
O(n)
```

---

### Space Complexity

Frequency array:

```cpp
O(26)
```

Visited array:

```cpp
O(26)
```

Stack:

```cpp
O(26)
```

Overall:

```cpp
O(1)
```

since the alphabet size is fixed (26 lowercase English letters).

---

## Notes

- Uses a greedy algorithm with a monotonic stack.
- Ensures every distinct character appears exactly once.
- Removes larger characters only if they appear again later.
- Maintains a `visited` array to avoid duplicate characters in the subsequence.
- Every character is pushed and popped at most once, resulting in linear time complexity.
- This is the standard optimal solution for the problem.
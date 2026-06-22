# Maximum Number of Balloons

## Problem Statement

Given a string `text`, return the maximum number of instances of the word:

```text
"balloon"
```

that can be formed using the characters in `text`.

Each character in `text` can be used at most once.

---

# Solution: Character Frequency Counting

## Solution Overview

This solution counts the frequency of every character in the string and determines how many complete copies of the word:

```text
"balloon"
```

can be formed.

Key ideas:
- Count the occurrences of each character.
- The word `"balloon"` requires:
  - `1` `'b'`
  - `1` `'a'`
  - `2` `'l'`
  - `2` `'o'`
  - `1` `'n'`
- The limiting character determines the maximum number of balloons that can be formed.

---

## Algorithm

### Step 1: Count Character Frequencies

Create a hash map:

```cpp
unordered_map<char, int> freq;
```

Traverse the string:

```cpp
for(char c : text)
```

and update:

```cpp
freq[c]++;
```

---

### Step 2: Compute Available Copies

For the word:

```text
balloon
```

the required frequencies are:

```cpp
b → 1
a → 1
l → 2
o → 2
n → 1
```

Compute:

```cpp
freq['b']
```

```cpp
freq['a']
```

```cpp
freq['l'] / 2
```

```cpp
freq['o'] / 2
```

```cpp
freq['n']
```

---

### Step 3: Find the Limiting Character

The maximum number of complete balloons is:

```cpp
min({
    freq['b'],
    freq['a'],
    freq['l'] / 2,
    freq['o'] / 2,
    freq['n']
})
```

---

### Step 4: Return Result

Return the minimum value obtained.

---

## Complexity Analysis

Let:

```cpp
n = text.length()
```

### Time Complexity

```cpp
O(n)
```

The string is traversed once.

---

### Space Complexity

```cpp
O(1)
```

The hash map stores frequencies for at most 26 lowercase English letters.

---

## Notes

- Frequency counting is sufficient because character order does not matter.
- Characters `'l'` and `'o'` are required twice in each occurrence of `"balloon"`.
- Dividing their frequencies by `2` gives the number of complete pairs available.
- The character with the smallest usable frequency limits the answer.
- Efficient linear-time solution.
- This is the standard optimal solution for the problem.
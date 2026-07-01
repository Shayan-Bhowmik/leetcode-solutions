# Number of Substrings Containing All Three Characters

## Problem Statement

Given a string `s` consisting only of the characters:

```text
'a', 'b', and 'c'
```

Return the number of substrings containing at least one occurrence of each of these characters.

---

# Solution: Sliding Window + Two Pointers

## Solution Overview

This solution uses the **sliding window** technique to efficiently count all valid substrings.

Key ideas:
- Maintain a window using two pointers:
  - `left`
  - `right`
- Keep track of the frequency of `'a'`, `'b'`, and `'c'` inside the current window.
- Whenever the window contains all three characters:
  - Every larger substring ending after the current right pointer is also valid.
  - Count all such substrings at once.
- Shrink the window from the left to continue finding additional valid windows.

This avoids checking every possible substring individually.

---

## Algorithm

### Step 1: Initialize Variables

Create:

```cpp
left = 0;
count = 0;
```

Create a frequency array:

```cpp
vector<int> freq(3, 0);
```

where:

- `freq[0]` → count of `'a'`
- `freq[1]` → count of `'b'`
- `freq[2]` → count of `'c'`

---

### Step 2: Expand the Window

Traverse the string using the right pointer:

```cpp
i = 0 ... n - 1
```

Include the current character:

```cpp
freq[s[i] - 'a']++;
```

---

### Step 3: Check if Window is Valid

While the window contains at least one:

- `'a'`
- `'b'`
- `'c'`

that is,

```cpp
freq[0] && freq[1] && freq[2]
```

the current window is valid.

---

### Step 4: Count Valid Substrings

If the current window ends at index:

```cpp
i
```

then every substring ending at:

```cpp
i, i+1, ..., n-1
```

is also valid.

Therefore, add:

```cpp
n - i
```

to the answer:

```cpp
count += (n - i);
```

---

### Step 5: Shrink the Window

Remove the leftmost character:

```cpp
freq[s[left] - 'a']--;
```

Move:

```cpp
left++;
```

Continue shrinking while the window remains valid.

---

### Step 6: Return Answer

Return:

```cpp
count;
```

---

## Complexity Analysis

Let:

```cpp
n = s.length()
```

### Time Complexity

```cpp
O(n)
```

Each character enters and leaves the sliding window at most once.

---

### Space Complexity

```cpp
O(1)
```

Only a fixed-size frequency array of length `3` is used.

---

## Notes

- Uses the sliding window technique with two pointers.
- Maintains character frequencies for `'a'`, `'b'`, and `'c'`.
- Counts multiple valid substrings in a single step using:
  ```cpp
  n - i
  ```
  instead of checking each substring individually.
- Each index is processed at most twice, resulting in linear time complexity.
- This is the standard optimal solution for the problem.
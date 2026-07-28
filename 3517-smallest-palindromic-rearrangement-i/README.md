# Smallest Palindromic Rearrangement

## Problem Statement

You are given a string:

```cpp
s
```

It is guaranteed that the characters of the string can be rearranged to form a palindrome.

Return the **lexicographically smallest palindrome** that can be formed using all the characters of the string.

---

# Solution: Frequency Counting + Greedy Construction

## Solution Overview

This solution constructs the palindrome directly using the frequency of each character.

Key ideas:
- Count the occurrences of every character.
- Place half of each character in the left half of the palindrome.
- If a character has an odd frequency, place one occurrence in the middle.
- Form the right half by reversing the left half.
- Concatenate the three parts to obtain the lexicographically smallest palindrome.

Since characters are processed in alphabetical order, the resulting palindrome is the smallest possible.

---

## Algorithm

### Step 1: Count Character Frequencies

Create a frequency array:

```cpp
cnt[26]
```

Traverse the string and count the occurrence of every character.

---

### Step 2: Build the Left Half

Process characters from:

```cpp
'a'
```

to

```cpp
'z'
```

For every character, append:

```cpp
cnt[i] / 2
```

copies to the left half.

```cpp
left.append(cnt[i] / 2, char('a' + i));
```

Using alphabetical order ensures the smallest lexicographical arrangement.

---

### Step 3: Determine the Middle Character

If a character appears an odd number of times:

```cpp
cnt[i] % 2 == 1
```

store it as the middle character:

```cpp
mid = char('a' + i);
```

Since the input guarantees that a palindrome can be formed, at most one character will have an odd frequency.

---

### Step 4: Build the Right Half

Create the right half by reversing the left half:

```cpp
right = left;
reverse(right.begin(), right.end());
```

This guarantees the resulting string is a palindrome.

---

### Step 5: Return the Result

Concatenate all three parts:

```cpp
left + mid + right
```

and return the resulting palindrome.

---

## Why This Works

A palindrome is symmetric around its center.

- Half of each character's occurrences are placed on the left.
- The remaining half automatically appear on the right in reverse order.
- If there is an odd-frequency character, it occupies the center.

Processing characters from `'a'` to `'z'` ensures that the left half is lexicographically smallest, which also makes the entire palindrome lexicographically smallest.

---

## Complexity Analysis

Let:

```cpp
n = s.length()
```

### Time Complexity

Counting frequencies:

```cpp
O(n)
```

Building the palindrome:

```cpp
O(n)
```

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

Output strings:

```cpp
O(n)
```

Overall:

```cpp
O(n)
```

---

## Notes

- Uses frequency counting to determine the occurrence of each character.
- Constructs the left half greedily in alphabetical order.
- Places the odd-frequency character, if any, in the middle.
- Forms the right half by reversing the left half.
- Produces the lexicographically smallest valid palindrome.
- Runs in linear time and is the standard optimal solution for the problem.
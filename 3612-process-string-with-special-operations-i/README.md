# Process String with Special Operations I

## Problem Statement

You are given a string `s` consisting of lowercase English letters and special characters.

Process the string from left to right according to the following rules:

- Lowercase letters:
  - Append the character to the result string.
- `'*'`:
  - Remove the last character of the result string if it exists.
- `'#'`:
  - Duplicate the current result string and append it to itself.
- `'%'`:
  - Reverse the current result string.

Return the final processed string.

---

# Solution: String Simulation

## Solution Overview

This solution directly simulates the operations described in the problem statement.

Key ideas:
- Maintain a string `result`.
- Process each character one by one.
- Perform the corresponding operation based on the character type.
- Update the result string immediately after each operation.

This straightforward approach follows the rules exactly as given.

---

## Algorithm

### Step 1: Initialize Result String

Create:

```cpp
string result;
```

This stores the current processed string.

---

### Step 2: Traverse the Input String

For each character:

```cpp
s[i]
```

perform one of the following operations.

---

### Case 1: Character is '*'

If:

```cpp
s[i] == '*'
```

#### Empty Result

If:

```cpp
result.size() == 0
```

do nothing.

#### Non-Empty Result

Remove the last character:

```cpp
result.erase(result.size() - 1, 1);
```

---

### Case 2: Character is '#'

If:

```cpp
s[i] == '#'
```

Duplicate the current string:

```cpp
result.append(result);
```

Example:

```text
abc
```

becomes:

```text
abcabc
```

---

### Case 3: Character is '%'

If:

```cpp
s[i] == '%'
```

Reverse the current string:

```cpp
reverse(result.begin(), result.end());
```

---

### Case 4: Lowercase Letter

Otherwise:

```cpp
result.push_back(s[i]);
```

Append the character to the end of the string.

---

### Step 3: Return Answer

Return:

```cpp
result
```

after processing all characters.

---

## Complexity Analysis

Let:

```cpp
n = s.length()
```

and let:

```cpp
m = final result length
```

### Time Complexity

- Character append: `O(1)`
- Delete last character: `O(1)`
- Reverse operation: `O(m)`
- Duplication operation: `O(m)`

Worst-case:

```cpp
O(m)
```

per expensive operation.

Overall complexity depends on the growth of the result string.

---

### Space Complexity

```cpp
O(m)
```

where:

```cpp
m
```

is the size of the final processed string.

---

## Notes

- Directly simulates all operations.
- Handles deletion safely when the result is empty.
- `#` doubles the current string.
- `%` reverses the current string in-place.
- Lowercase letters are appended normally.
- Easy-to-understand implementation.
- Follows the problem rules exactly.
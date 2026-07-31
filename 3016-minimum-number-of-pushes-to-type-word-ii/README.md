# Minimum Number of Pushes to Type Word II

## Problem Statement

You are given a string:

```cpp
word
```

You may assign the lowercase English letters to the keys of a telephone keypad.

Each key can contain at most **8 distinct characters**.

The cost of typing a character depends on its position on the assigned key:

- Characters assigned to the first position require **1 push**.
- Characters assigned to the second position require **2 pushes**.
- Characters assigned to the third position require **3 pushes**, and so on.

Unlike **Word I**, characters may appear multiple times in the string.

Return the **minimum number of pushes** required to type the entire word.

---

# Solution: Frequency Counting + Greedy Assignment

## Solution Overview

To minimize the total number of pushes, the characters that appear most frequently should be assigned to the positions requiring the fewest key presses.

Key ideas:
- Count the frequency of every character.
- Sort the frequencies in descending order.
- Assign the highest frequencies to the cheapest push positions.
- Every group of **8 characters** increases the push count by one.
- Multiply each character's frequency by its assigned push cost and accumulate the answer.

This greedy strategy guarantees the minimum total number of pushes.

---

## Algorithm

### Step 1: Count Character Frequencies

Create a frequency array:

```cpp
freq[26]
```

Traverse the string:

```cpp
word
```

and count the occurrence of every character.

---

### Step 2: Sort Frequencies

Sort the frequency array in descending order:

```cpp
sort(freq.begin(), freq.end(), greater<int>());
```

This places the most frequently occurring characters first.

---

### Step 3: Assign Push Costs

Traverse the sorted frequency array.

If:

```cpp
freq[i] == 0
```

stop, since no more characters exist.

Otherwise, the push cost of the current character is:

```cpp
i / 8 + 1
```

Multiply the frequency by its push cost:

```cpp
ans += freq[i] * (i / 8 + 1);
```

---

### Step 4: Return the Answer

Return:

```cpp
ans;
```

---

## Why the Greedy Approach Works

Characters that occur more frequently contribute more to the total number of key presses.

Assigning these characters to the smallest push costs minimizes the overall total.

For example, if one character appears 100 times and another appears once, assigning the first character to a 1-push position always results in fewer total presses than assigning it to a higher-cost position.

Sorting the frequencies ensures this optimal assignment.

---

## Complexity Analysis

Let:

```cpp
n = word.length()
```

### Time Complexity

Counting frequencies:

```cpp
O(n)
```

Sorting the 26 frequencies:

```cpp
O(26 log 26)
```

Traversing the sorted array:

```cpp
O(26)
```

Overall:

```cpp
O(n)
```

since the alphabet size is fixed.

---

### Space Complexity

Frequency array:

```cpp
O(26)
```

Overall:

```cpp
O(1)
```

---

## Notes

- Uses frequency counting to determine how often each character appears.
- Sorts character frequencies in descending order.
- Assigns the most frequent characters to the lowest push-cost positions.
- Every group of 8 assigned characters increases the push cost by 1.
- Requires only constant extra space because the alphabet size is fixed.
- This is the standard optimal greedy solution for the problem.
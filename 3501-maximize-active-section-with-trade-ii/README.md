# Maximize Active Sections After Trade II

## Problem Statement

You are given:

```cpp
string s
```

representing active (`'1'`) and inactive (`'0'`) sections, and a list of queries.

Each query specifies a substring:

```cpp
[l, r]
```

For every query, determine the maximum number of active sections that can be obtained after performing **one trade** within the specified range.

Return the answer for every query.

---

# Solution: Zero Group Preprocessing + Sparse Table + Range Maximum Query

## Solution Overview

This solution preprocesses the string into **consecutive groups of zeros** and builds a **Sparse Table** to answer maximum merge-length queries efficiently.

Key ideas:
- Count the total number of active sections once.
- Divide all consecutive `'0'` characters into groups.
- Compute the merge length of every pair of adjacent zero groups.
- Build a Sparse Table over these merge lengths.
- For each query, evaluate all possible cases using constant-time range maximum queries.

This preprocessing enables each query to be answered efficiently.

---

## Algorithm

### Step 1: Count Active Sections

Compute the total number of active sections:

```cpp
ones = count(s.begin(), s.end(), '1');
```

This serves as the base answer for every query.

---

### Step 2: Identify Zero Groups

Traverse the string.

Each maximal consecutive block of `'0'` is stored as:

```cpp
Group
{
    start,
    length
}
```

Also maintain:

```cpp
zeroGroupIndex[i]
```

which stores the zero-group containing position `i`.

If position `i` is not inside a zero group:

```cpp
zeroGroupIndex[i] = -1;
```

---

### Step 3: Compute Merge Lengths

For every pair of adjacent zero groups compute:

```cpp
length[i] + length[i+1]
```

Store these values in an array.

These represent the maximum gain obtainable by merging adjacent zero groups.

---

### Step 4: Build Sparse Table

Construct a Sparse Table over the merge-length array.

Each table entry stores:

```cpp
maximum merge length
```

for a power-of-two interval.

This allows answering range maximum queries in:

```cpp
O(1)
```

time.

---

### Step 5: Process Each Query

For every query:

```cpp
[l, r]
```

identify:

- Left partial zero group.
- Right partial zero group.
- Complete zero groups lying entirely inside the query.

Compute the best possible gain using several cases:

- Merge two partial zero groups.
- Merge complete adjacent zero groups.
- Merge a partial group with a neighboring complete group.
- Handle cases where the query begins or ends inside a zero group.

Whenever complete zero groups are involved, use the Sparse Table to obtain the maximum merge length.

---

### Step 6: Store the Answer

For every query:

```cpp
answer = ones + maximumGain;
```

Store the result in the output array.

Return all answers.

---

## Why Sparse Table?

The merge lengths never change after preprocessing.

Since queries only ask for the **maximum value in a range**, a Sparse Table is ideal because:

- Preprocessing:

```cpp
O(m log m)
```

where `m` is the number of adjacent zero-group pairs.

- Query:

```cpp
O(1)
```

This makes the solution efficient even for a large number of queries.

---

## Complexity Analysis

Let:

```cpp
n = s.length()
```

and

```cpp
g = number of zero groups
```

### Time Complexity

Building zero groups:

```cpp
O(n)
```

Building merge-length array:

```cpp
O(g)
```

Building Sparse Table:

```cpp
O(g log g)
```

Each query:

```cpp
O(1)
```

Overall:

```cpp
O(n + g log g + q)
```

where:

```cpp
q = queries.size()
```

---

### Space Complexity

Zero groups:

```cpp
O(g)
```

Group index array:

```cpp
O(n)
```

Merge-length array:

```cpp
O(g)
```

Sparse Table:

```cpp
O(g log g)
```

Answer array:

```cpp
O(q)
```

Overall:

```cpp
O(n + g log g + q)
```

---

## Notes

- Preprocesses consecutive zero sections into groups.
- Maps every position to its corresponding zero group.
- Computes merge lengths for adjacent zero groups.
- Uses a Sparse Table to answer range maximum queries in constant time.
- Handles partial and complete zero groups separately for each query.
- Achieves efficient query processing after preprocessing.
- This is the standard optimal solution for the problem.
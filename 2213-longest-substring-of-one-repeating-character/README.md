# Longest Substring of One Repeating Character

## Problem Statement

You are given:

```cpp
string s
```

along with a series of updates:

```cpp
queryCharacters
queryIndices
```

For every query:

- Change `s[queryIndices[i]]` to `queryCharacters[i]`.
- After the update, find the length of the **longest substring consisting of the same character**.

Return the answer after every query.

---

# Solution: Segment Tree

## Solution Overview

Because the string is modified many times, checking the entire string after every update would be inefficient.

A **Segment Tree** allows us to:

- Update one character in `O(log n)`.
- Maintain the longest repeating substring for the entire string.
- Get the answer from the root of the tree in `O(1)` after each update.

Each segment-tree node stores enough information to combine two neighboring segments.

---

# Node Information

Each node stores:

```cpp
struct Node {
    char leftChar;
    char rightChar;
    int length;
    int prefix;
    int suffix;
    int best;
};
```

These values describe the segment represented by that node.

---

## 1. `leftChar`

```cpp
leftChar
```

The character at the **leftmost position** of the segment.

---

## 2. `rightChar`

```cpp
rightChar
```

The character at the **rightmost position** of the segment.

These are needed when merging two neighboring segments.

---

## 3. `length`

```cpp
length
```

The total length of the segment.

For example:

```text
"aaabb"
```

has:

```text
length = 5
```

---

## 4. `prefix`

```cpp
prefix
```

Length of the longest sequence of identical characters starting from the **left side**.

For:

```text
"aaabb"
```

we have:

```text
prefix = 3
```

because the string starts with:

```text
aaa
```

---

## 5. `suffix`

```cpp
suffix
```

Length of the longest sequence of identical characters ending at the **right side**.

For:

```text
"aaabb"
```

we have:

```text
suffix = 2
```

because it ends with:

```text
bb
```

---

## 6. `best`

```cpp
best
```

The longest substring containing the same character anywhere inside the segment.

For:

```text
"aaabb"
```

we have:

```text
best = 3
```

---

# Leaf Node

When a segment contains only one character:

```cpp
tree[node] = {
    s[start],
    s[start],
    1,
    1,
    1,
    1
};
```

For example:

```text
"a"
```

has:

```text
leftChar  = 'a'
rightChar = 'a'
length    = 1
prefix    = 1
suffix    = 1
best      = 1
```

---

# Merging Two Nodes

Suppose we have:

```text
Left Segment | Right Segment
```

The function:

```cpp
mergeNodes(left, right)
```

combines their information.

---

## Step 1: Basic Information

The resulting segment starts where the left segment starts:

```cpp
res.leftChar = left.leftChar;
```

and ends where the right segment ends:

```cpp
res.rightChar = right.rightChar;
```

The lengths are added:

```cpp
res.length = left.length + right.length;
```

---

# Step 2: Calculate Prefix

Initially:

```cpp
res.prefix = left.prefix;
```

Normally, the prefix comes entirely from the left segment.

However, suppose:

```text
left  = "aaa"
right = "aab"
```

The left segment consists entirely of `'a'`:

```cpp
left.prefix == left.length
```

and the boundary characters match:

```cpp
left.rightChar == right.leftChar
```

Then the prefix can extend into the right segment:

```cpp
res.prefix = left.length + right.prefix;
```

---

# Step 3: Calculate Suffix

Similarly:

```cpp
res.suffix = right.suffix;
```

Normally, the suffix comes from the right segment.

If:

```cpp
left.rightChar == right.leftChar
```

and the entire right segment is part of the suffix:

```cpp
right.suffix == right.length
```

then the suffix can extend into the left segment:

```cpp
res.suffix = right.length + left.suffix;
```

---

# Step 4: Calculate `best`

The longest repeating substring can be:

1. Entirely inside the left segment.
2. Entirely inside the right segment.
3. Crossing the boundary between the two segments.

Therefore:

```cpp
res.best = max(left.best, right.best);
```

If the boundary characters are equal:

```cpp
left.rightChar == right.leftChar
```

we can combine:

```cpp
left.suffix + right.prefix
```

So:

```cpp
res.best = max(
    res.best,
    left.suffix + right.prefix
);
```

---

# Example of Merging

Suppose:

```text
Left  = "aab"
Right = "bbcc"
```

The relevant information is:

```text
Left suffix = 1
Right prefix = 2
```

because:

```text
Left  → "aab"
             b
Right → "bbcc"
          bb
```

The boundary characters are both `'b'`.

Therefore, the repeating sequence crossing the boundary has length:

```text
1 + 2 = 3
```

giving:

```text
"bbb"
```

So:

```cpp
best = max(left.best, right.best, 3);
```

---

# Building the Segment Tree

The initial string is converted into a segment tree using:

```cpp
build(1, 0, n - 1, s);
```

The tree recursively divides the string into smaller segments.

Eventually, every individual character becomes a leaf.

Then parent nodes are created by:

```cpp
mergeNodes(leftChild, rightChild);
```

The root:

```cpp
tree[1]
```

represents the entire string.

Therefore:

```cpp
tree[1].best
```

is always the answer for the complete string.

---

# Handling an Update

For every query:

```cpp
queryIndices[i]
```

the character at that position changes to:

```cpp
queryCharacters[i]
```

The update starts from the root:

```cpp
update(
    1,
    0,
    n - 1,
    queryIndices[i],
    queryCharacters[i]
);
```

The segment tree follows the path to that specific index.

At the leaf, the character is changed:

```cpp
tree[node] = {
    ch, ch, 1, 1, 1, 1
};
```

Then all affected parent nodes are recalculated using:

```cpp
mergeNodes(...)
```

Thus the root immediately contains the updated answer.

---

# Why Segment Tree Is Needed

Suppose:

```text
n = 100000
```

and there are:

```text
100000
```

updates.

If we scanned the entire string after every update:

```text
O(n × q)
```

would be approximately:

```text
O(10^10)
```

which is too slow.

With a segment tree:

- Each update takes `O(log n)`.
- The answer is available at the root.

This gives a much more efficient solution.

---

# Complexity Analysis

Let:

```cpp
n = s.length()
q = queryIndices.size()
```

### Building the Tree

Each position is processed once:

```text
O(n)
```

### Each Update

A single character update travels from the root to a leaf:

```text
O(log n)
```

There are `q` updates:

```text
O(q log n)
```

### Total Time Complexity

```text
O(n + q log n)
```

---

### Space Complexity

The segment tree contains approximately:

```text
4n
```

nodes.

Therefore:

```text
O(n)
```

space.

---

# Notes

- Uses a **Segment Tree** to efficiently handle character updates.
- Each node stores:
  - leftmost character
  - rightmost character
  - segment length
  - longest equal-character prefix
  - longest equal-character suffix
  - longest equal-character substring
- The key operation is `mergeNodes()`.
- When two neighboring segments have the same boundary character, their suffix and prefix can be combined.
- `tree[1].best` always represents the answer for the entire current string.
- Building the tree takes **O(n)**.
- Each update takes **O(log n)**.
- Overall complexity is **O(n + q log n)** with **O(n)** space.
- This is the standard optimal approach for LeetCode 2213.
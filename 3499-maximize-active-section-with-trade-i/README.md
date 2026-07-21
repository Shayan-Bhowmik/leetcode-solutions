# Maximize Active Section After One Trade

## Problem Statement

You are given a binary string:

```cpp
s
```

where:

- `'1'` represents an active section.
- `'0'` represents an inactive section.

You may perform **at most one trade** to maximize the total number of active sections.

Return the maximum number of active sections possible after the trade.

---

# Solution: Greedy Run-Length Processing

## Solution Overview

This solution processes the string as consecutive **runs** of identical characters instead of examining each character individually.

Key ideas:
- Count the total number of active (`'1'`) sections.
- Record the lengths of consecutive runs of `'0'`.
- For every zero-run, determine the best inactive sections that can be activated by combining it with the immediately preceding zero-run.
- Track the maximum gain obtainable from a single trade.
- Add this maximum gain to the original number of active sections.

Since every character is visited exactly once, the algorithm is highly efficient.

---

## Algorithm

### Step 1: Initialize Variables

Maintain:

```cpp
ans
```

to store the number of currently active sections.

Maintain:

```cpp
pre
```

to store the length of the previous zero-run.

Maintain:

```cpp
mx
```

to store the maximum additional active sections obtainable.

---

### Step 2: Traverse Consecutive Runs

Iterate through the string.

For each run:

```cpp
s[i...j-1]
```

compute its length:

```cpp
len = j - i;
```

---

### Step 3: Process Active Runs

If the current run consists of:

```cpp
'1'
```

add its length to the total active count:

```cpp
ans += len;
```

---

### Step 4: Process Inactive Runs

If the run consists of:

```cpp
'0'
```

update the maximum possible gain:

```cpp
mx = max(mx, pre + len);
```

Then remember the current zero-run for future processing:

```cpp
pre = len;
```

---

### Step 5: Continue Until the End

Repeat the above steps for every consecutive run in the string.

---

### Step 6: Return the Result

The final answer is:

```cpp
ans + mx;
```

which represents the original active sections plus the best improvement from one trade.

---

## Why the Greedy Approach Works

The string is naturally divided into consecutive runs of identical characters.

Instead of examining individual positions, the algorithm operates on these runs.

Every run of inactive sections represents a potential improvement. By tracking the previous inactive run and combining it with the current one, the algorithm efficiently computes the maximum gain achievable with a single trade.

Since each run is processed once, the optimal gain is obtained in linear time.

---

## Complexity Analysis

Let:

```cpp
n = s.length()
```

### Time Complexity

Each character is visited exactly once while forming runs.

```cpp
O(n)
```

---

### Space Complexity

Only a few integer variables are maintained.

```cpp
O(1)
```

---

## Notes

- Uses run-length processing to group consecutive identical characters.
- Counts the total number of active (`'1'`) sections in a single traversal.
- Evaluates every inactive (`'0'`) run as a potential gain.
- Maintains the maximum improvement obtainable from one trade.
- Requires constant extra space.
- Runs in linear time, making it an efficient solution for large inputs.
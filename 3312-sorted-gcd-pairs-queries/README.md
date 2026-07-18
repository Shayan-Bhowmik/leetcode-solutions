# Sorted GCD Pair Queries

## Problem Statement

You are given an integer array:

```cpp
nums
```

For every unordered pair of indices:

```cpp
(i, j)
```

where:

```cpp
i < j
```

compute the GCD of the corresponding pair of numbers.

Sort all these GCD values in non-decreasing order.

For each query:

```cpp
queries[k]
```

return the GCD value located at that zero-based position in the sorted list.

---

# Solution: Frequency Counting + Inclusion-Exclusion + Prefix Sum + Binary Search

## Solution Overview

Instead of explicitly generating all pairs (which would take `O(n²)` time), this solution counts how many pairs have each possible GCD.

Key ideas:
- Count the frequency of every value.
- For every possible GCD:
  - Count how many numbers are divisible by it.
  - Compute how many pairs can be formed.
  - Use Inclusion-Exclusion to remove pairs already counted for larger GCDs.
- Build a prefix sum over GCD values.
- For every query, use Binary Search to determine the corresponding GCD.

This avoids constructing the enormous sorted list of GCDs.

---

## Algorithm

### Step 1: Count Frequencies

Find the maximum element:

```cpp
mx
```

Create:

```cpp
freq[mx + 1]
```

where:

```cpp
freq[x]
```

stores how many times the value:

```cpp
x
```

appears.

---

### Step 2: Count Pairs for Every GCD

Create:

```cpp
cntG[g]
```

which stores the number of pairs having GCD exactly:

```cpp
g
```

Process GCD values from:

```cpp
mx
```

down to:

```cpp
1
```

---

### Step 3: Count Multiples

For every multiple of:

```cpp
g
```

count how many numbers are divisible by:

```cpp
g
```

```cpp
cnt += freq[multiple];
```

If:

```cpp
cnt
```

numbers are divisible by:

```cpp
g
```

then the total number of unordered pairs is:

```cpp
cnt * (cnt - 1) / 2
```

---

### Step 4: Apply Inclusion-Exclusion

The above count includes pairs whose GCD is a multiple of:

```cpp
g
```

Subtract all previously computed larger GCD counts:

```cpp
cntG[g] -= cntG[multiple];
```

Finally:

```cpp
cntG[g] += cnt * (cnt - 1) / 2;
```

Now:

```cpp
cntG[g]
```

contains the number of pairs whose GCD is **exactly**:

```cpp
g
```

---

### Step 5: Build Prefix Sum

Convert:

```cpp
cntG
```

into a prefix sum:

```cpp
cntG[i] += cntG[i - 1];
```

After this:

```cpp
cntG[g]
```

stores the number of pairs having GCD **less than or equal to**:

```cpp
g
```

---

### Step 6: Answer Queries

For every query:

```cpp
q
```

find the first GCD whose cumulative pair count exceeds:

```cpp
q
```

using:

```cpp
upper_bound(cntG.begin(), cntG.end(), q)
```

The returned index is the required GCD value.

Store it in the answer array.

---

### Step 7: Return Result

Return:

```cpp
ans;
```

---

## Why Inclusion-Exclusion Works

Suppose we are computing:

```cpp
cntG[2]
```

The pair count initially includes pairs whose GCD is:

```text
2
4
6
8
...
```

Subtracting the already computed counts for:

```text
4
6
8
...
```

leaves only the pairs whose GCD is exactly:

```cpp
2
```

Processing GCDs in decreasing order guarantees all larger multiples have already been computed.

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

and

```cpp
M = maximum element in nums
```

### Time Complexity

Frequency counting:

```cpp
O(n)
```

Counting multiples using the harmonic series:

```cpp
O(M log M)
```

Prefix sum:

```cpp
O(M)
```

Each query:

```cpp
O(log M)
```

Overall:

```cpp
O(n + M log M + q log M)
```

where:

```cpp
q = queries.size()
```

---

### Space Complexity

Frequency array:

```cpp
O(M)
```

Pair-count array:

```cpp
O(M)
```

Answer array:

```cpp
O(q)
```

Overall:

```cpp
O(M + q)
```

---

## Notes

- Avoids generating all `O(n²)` GCD pairs explicitly.
- Counts pairs for every possible GCD using frequency counting.
- Uses Inclusion-Exclusion to isolate pairs having **exactly** a given GCD.
- Builds a prefix sum so that Binary Search can answer queries efficiently.
- Each query is answered in `O(log M)` time.
- This is the standard optimal solution for the problem.
# Largest Integer That Appears Only Once in Subarrays

## Problem Statement

You are given an integer array:

```cpp
nums
```

and an integer:

```cpp
k
```

Consider every contiguous subarray of length `k`.

Find the **largest integer that appears in exactly one of these subarrays**.

If no such integer exists, return:

```cpp
-1
```

---

# Solution: Hash Map + Hash Set

## Solution Overview

The important detail is that we need to count **how many subarrays contain each number**, not how many times the number occurs inside all subarrays.

Therefore, for every subarray of length `k`:

1. Use a `set` to store the distinct numbers in that subarray.
2. Increase the frequency of each distinct number by `1`.
3. After processing all subarrays, find the largest number whose frequency is exactly `1`.

---

## Step 1: Find Every Length-`k` Subarray

There are:

```cpp
n - k + 1
```

subarrays of length `k`.

The outer loop:

```cpp
for (int i = 0; i <= n - k; i++)
```

generates each starting position.

The current subarray is:

```text
nums[i ... i+k-1]
```

---

## Step 2: Remove Duplicates Within a Subarray

Create:

```cpp
unordered_set<int> seen;
```

For every element in the current subarray:

```cpp
for (int j = i; j < i + k; j++) {
    seen.insert(nums[j]);
}
```

The set ensures that each number is counted **only once for this particular subarray**.

This is important.

For example:

```text
subarray = [5, 5, 7]
```

We want:

```text
5 → appears in this subarray
7 → appears in this subarray
```

not:

```text
5 → counted twice
```

So the set contains:

```text
{5, 7}
```

---

# Step 3: Count the Number of Subarrays Containing Each Value

For every distinct value in:

```cpp
seen
```

we increment:

```cpp
freq[x]++;
```

Therefore:

```cpp
freq[x]
```

means:

> The number of length-`k` subarrays that contain `x`.

It does **not** mean the total number of occurrences of `x` in the array.

---

# Step 4: Find the Largest Unique Value

After processing every subarray:

```cpp
for (auto [num, count] : freq)
```

we check:

```cpp
if (count == 1)
```

This means the number appears in exactly one length-`k` subarray.

Then:

```cpp
ans = max(ans, num);
```

keeps the largest such value.

If no number satisfies the condition, `ans` remains:

```cpp
-1
```

---

# Example

Consider:

```text
nums = [1, 2, 3, 2, 4]
k = 2
```

The length-2 subarrays are:

```text
[1,2]
[2,3]
[3,2]
[2,4]
```

Distinct values in each:

```text
[1,2] → {1,2}
[2,3] → {2,3}
[3,2] → {3,2}
[2,4] → {2,4}
```

Now count the number of subarrays containing each value:

```text
1 → 1
2 → 4
3 → 2
4 → 1
```

Values appearing in exactly one subarray:

```text
1, 4
```

Therefore:

```text
answer = 4
```

---

# Why the `unordered_set` Is Necessary

Suppose:

```text
nums = [5, 5, 5]
k = 3
```

There is only one subarray:

```text
[5,5,5]
```

Even though `5` appears three times inside it, it appears in only **one subarray**.

Using:

```cpp
seen
```

ensures we perform:

```cpp
freq[5]++;
```

only once for that subarray.

---

# Complexity Analysis

Let:

```cpp
n = nums.size()
```

There are:

```text
n - k + 1
```

subarrays.

For every subarray, we process `k` elements.

### Time Complexity

```text
O((n-k+1) × k)
```

which is:

```text
O(nk)
```

on average.

The hash-set and hash-map operations are `O(1)` average.

---

### Space Complexity

The `seen` set can contain up to:

```text
O(k)
```

distinct elements.

The frequency map can contain up to:

```text
O(n)
```

distinct values.

Therefore:

```text
O(n + k)
```

overall, which simplifies to:

```text
O(n)
```

---

## Notes

- Uses a **Hash Map + Hash Set**.
- `seen` ensures each number is counted only once per length-`k` subarray.
- `freq[x]` represents the number of length-`k` subarrays containing `x`.
- A number is valid only when:
  ```cpp
  freq[x] == 1
  ```
- Among all valid numbers, the largest one is returned.
- If no valid number exists, the answer is `-1`.
- Time complexity: **O(nk)** average.
- Space complexity: **O(n)**.
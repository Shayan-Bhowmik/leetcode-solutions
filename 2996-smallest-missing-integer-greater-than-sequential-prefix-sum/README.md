# Smallest Missing Integer Greater Than Sequential Prefix Sum

## Problem Statement

You are given an array:

```cpp
nums
```

The task is to:

1. Find the **longest sequential prefix** of the array.
2. A sequential prefix is a prefix where every next element is exactly `1` greater than the previous element.
3. Calculate the sum of all elements in this sequential prefix.
4. If this sum already exists in the array, keep increasing it until you find a value that does not exist.
5. Return that value.

---

# Solution: Sequential Prefix + Hash Set

## Solution Overview

The solution has two main parts:

- Find the longest sequential prefix and calculate its sum.
- Use an `unordered_set` to quickly check whether the resulting sum already exists.

The important observation is that we only care about the **prefix starting at `nums[0]`**.

---

## Step 1: Calculate the Sequential Prefix Sum

Start with:

```cpp
int sum = nums[0];
```

Then traverse the array from index `1`.

For every element, check:

```cpp
nums[i] == nums[i - 1] + 1
```

If true, the sequence continues:

```cpp
sum += nums[i];
```

Otherwise, the sequential prefix ends:

```cpp
break;
```

### Example

Suppose:

```text
nums = [3, 4, 5, 6, 10, 11]
```

The sequential prefix is:

```text
3, 4, 5, 6
```

because:

```text
3 → 4 → 5 → 6
```

but:

```text
6 → 10
```

is not consecutive.

Therefore:

```text
sum = 3 + 4 + 5 + 6
    = 18
```

---

# Step 2: Store All Numbers in a Hash Set

Create:

```cpp
unordered_set<int> dup_nums(nums.begin(), nums.end());
```

This allows us to check whether a number exists in the array in **O(1) average time**.

---

# Step 3: Find the Smallest Missing Value

Now check whether:

```cpp
sum
```

already exists.

```cpp
while (dup_nums.count(sum)) {
    sum++;
}
```

If it exists, increment it.

Continue until:

```cpp
sum
```

is not present in the array.

---

# Step 4: Return the Answer

Return:

```cpp
sum;
```

---

## Why This Works

The problem specifically asks us to first calculate the sum of the **longest sequential prefix**.

Once that sum is obtained, the answer must be:

```text
sum
```

or the first number greater than `sum` that is not already present in the array.

The hash set makes this search efficient.

---

## Example

Consider:

```text
nums = [1, 2, 3, 2, 5]
```

The longest sequential prefix is:

```text
1, 2, 3
```

Its sum is:

```text
1 + 2 + 3 = 6
```

Check the array:

```text
6
```

is not present.

Therefore:

```text
answer = 6
```

---

## Another Example

Suppose:

```text
nums = [2, 3, 4, 5, 9, 10]
```

Sequential prefix:

```text
2, 3, 4, 5
```

Sum:

```text
2 + 3 + 4 + 5 = 14
```

If `14` exists in the array, the algorithm checks:

```text
15
16
17
...
```

until it finds a value not present.

---

# Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

Finding the sequential prefix:

```cpp
O(n)
```

Building the hash set:

```cpp
O(n)
```

Searching for the missing value:

```cpp
O(k)
```

where `k` is the number of consecutive values starting from `sum` that already exist.

Overall average complexity:

```cpp
O(n + k)
```

---

### Space Complexity

The hash set stores all array elements:

```cpp
O(n)
```

So:

```text
O(n)
```

---

## Notes

- The sequential part is checked **only from the beginning of the array**.
- The moment:
  ```cpp
  nums[i] != nums[i-1] + 1
  ```
  occurs, the prefix ends.
- The sum of this prefix becomes the initial candidate answer.
- An `unordered_set` provides fast membership checking.
- If the candidate already exists, increment it until a missing value is found.
- Time complexity is **O(n)** on average, apart from the small additional search for consecutive existing values.
- Space complexity is **O(n)**.
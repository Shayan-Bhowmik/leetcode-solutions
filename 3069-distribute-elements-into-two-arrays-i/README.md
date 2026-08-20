# Distribute Elements Into Two Arrays I

## Problem Statement

You are given an integer array:

```cpp
nums
```

You need to construct two arrays:

```cpp
arr1
arr2
```

The rules are:

1. Put `nums[0]` into `arr1`.
2. Put `nums[1]` into `arr2`.
3. For every remaining element `nums[i]`:
   - If the last element of `arr1` is greater than the last element of `arr2`, put `nums[i]` into `arr1`.
   - Otherwise, put it into `arr2`.
4. Finally, concatenate `arr2` to the end of `arr1`.

Return the resulting array.

---

# Solution: Simulation

## Solution Overview

This problem doesn't require a complicated algorithm.

We simply simulate the rules given in the problem.

The important thing to notice is that we only need the **last element** of each array to decide where the next number goes.

That's why:

```cpp
arr1.back()
```

and:

```cpp
arr2.back()
```

are sufficient.

---

# Step 1: Handle Small Arrays

```cpp
if (nums.size() < 2) {
    return nums;
}
```

If there are fewer than two elements, there is no need to create two arrays.

---

# Step 2: Initialize the Two Arrays

The first element goes to `arr1`:

```cpp
arr1.push_back(nums[0]);
```

The second element goes to `arr2`:

```cpp
arr2.push_back(nums[1]);
```

For example:

```text
nums = [5, 4, 3, 8, 2]
```

Initially:

```text
arr1 = [5]
arr2 = [4]
```

---

# Step 3: Process the Remaining Elements

Start from index `2`:

```cpp
for (int i = 2; i < nums.size(); i++)
```

For every element, compare:

```cpp
arr1.back()
```

with:

```cpp
arr2.back()
```

---

## If `arr1.back()` Is Larger

```cpp
if (arr1.back() > arr2.back()) {
    arr1.push_back(nums[i]);
}
```

The current element is added to `arr1`.

Example:

```text
arr1 = [5]
arr2 = [4]
nums[i] = 3
```

Since:

```text
5 > 4
```

we get:

```text
arr1 = [5, 3]
arr2 = [4]
```

---

## Otherwise

```cpp
else {
    arr2.push_back(nums[i]);
}
```

If:

```text
arr1.back() <= arr2.back()
```

the element goes into `arr2`.

For example:

```text
arr1 = [5]
arr2 = [6]
nums[i] = 3
```

Since:

```text
5 <= 6
```

we get:

```text
arr1 = [5]
arr2 = [6, 3]
```

---

# Step 4: Concatenate the Arrays

After all elements have been distributed:

```cpp
arr1.insert(
    arr1.end(),
    arr2.begin(),
    arr2.end()
);
```

This appends all elements of `arr2` to the end of `arr1`.

So:

```text
arr1 = [5, 3]
arr2 = [4, 8, 2]
```

becomes:

```text
[5, 3, 4, 8, 2]
```

---

# Example

Consider:

```text
nums = [2, 1, 3, 3]
```

### Initially

```text
arr1 = [2]
arr2 = [1]
```

### Process `3`

Compare:

```text
2 > 1
```

So:

```text
arr1 = [2, 3]
arr2 = [1]
```

### Process next `3`

Compare:

```text
3 > 1
```

So:

```text
arr1 = [2, 3, 3]
arr2 = [1]
```

Finally concatenate:

```text
arr1 + arr2
```

Result:

```text
[2, 3, 3, 1]
```

---

# Why `back()` Is Used

The rule says to compare the **last elements** of the two arrays.

Instead of doing:

```cpp
arr1[arr1.size() - 1]
```

we use:

```cpp
arr1.back()
```

which directly gives the last element.

Similarly:

```cpp
arr2.back()
```

gives the last element of `arr2`.

---

# Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

We process every element once:

```text
O(n)
```

The final `insert` also copies the elements of `arr2`:

```text
O(n)
```

Therefore, overall:

```text
O(n)
```

---

### Space Complexity

We store the elements in:

```cpp
arr1
arr2
```

Together they contain all `n` elements.

Therefore:

```text
O(n)
```

---

## Notes

- This is a **direct simulation** problem.
- The first element goes to `arr1`.
- The second element goes to `arr2`.
- For every remaining element:
  ```cpp
  arr1.back() > arr2.back()
  ```
  determines where it goes.
- `back()` gives the last element of each array.
- Finally, `arr2` is appended to `arr1`.
- Time complexity: **O(n)**.
- Space complexity: **O(n)**.
- No sorting, hashing, or dynamic programming is required.
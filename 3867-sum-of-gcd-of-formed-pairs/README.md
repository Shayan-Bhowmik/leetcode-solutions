# GCD Sum of Symmetric Pairs

## Problem Statement

You are given an integer array:

```cpp
nums
```

Construct a new array where each element is defined as:

```cpp
prefixGcd[i] = gcd(nums[i], maximum element seen so far)
```

After constructing the array:

- Sort it in non-decreasing order.
- Pair the smallest element with the largest, the second smallest with the second largest, and so on.
- Compute the GCD of every pair.
- Return the sum of these GCD values.

---

# Solution: Prefix Processing + Sorting + Two Pointers

## Solution Overview

This solution computes a transformed array using prefix information, sorts it, and then forms symmetric pairs.

Key ideas:
- Traverse the array while maintaining the maximum value seen so far.
- Compute the GCD of the current element with the current maximum.
- Store these values in a new array.
- Sort the transformed array.
- Use two pointers to pair the smallest and largest values.
- Compute the GCD of each pair and accumulate the answer.

---

## Algorithm

### Step 1: Initialize Variables

Create:

```cpp
prefixGcd
```

to store the transformed values.

Maintain:

```cpp
maxGcd = 0;
```

which stores the maximum element encountered so far.

---

### Step 2: Construct the Prefix GCD Array

Traverse every element:

```cpp
nums[i]
```

Update:

```cpp
maxGcd = max(maxGcd, nums[i]);
```

Compute:

```cpp
prefixGcd[i] = gcd(nums[i], maxGcd);
```

This stores the transformed value for each position.

---

### Step 3: Sort the Array

Sort:

```cpp
prefixGcd
```

in ascending order.

```cpp
sort(prefixGcd.begin(), prefixGcd.end());
```

---

### Step 4: Pair Symmetric Elements

Initialize two pointers:

```cpp
left = 0;
right = n - 1;
```

While:

```cpp
left < right
```

compute:

```cpp
gcd(prefixGcd[left], prefixGcd[right]);
```

Add the result to:

```cpp
sum
```

Move both pointers:

```cpp
left++;
right--;
```

---

### Step 5: Return Answer

Return:

```cpp
sum;
```

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

Constructing the transformed array:

```cpp
O(n)
```

Sorting:

```cpp
O(n log n)
```

Two-pointer traversal:

```cpp
O(n)
```

Overall:

```cpp
O(n log n)
```

---

### Space Complexity

Transformed array:

```cpp
O(n)
```

Overall:

```cpp
O(n)
```

---

## Notes

- Maintains the maximum element seen so far while traversing the array.
- Computes the GCD of each element with the current maximum.
- Sorts the transformed values before pairing.
- Uses the two-pointer technique to efficiently form symmetric pairs.
- Computes the GCD for each pair and accumulates the final answer.
- This approach runs in `O(n log n)` time due to sorting.
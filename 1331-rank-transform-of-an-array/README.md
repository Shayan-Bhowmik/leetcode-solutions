# Rank Transform of an Array

## Problem Statement

Given an array of integers `arr`, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

- Rank is an integer starting from `1`.
- The larger the element, the larger the rank.
- If two elements are equal, their rank must be the same.
- Ranks should be as small as possible.

Return the rank-transformed array.

---

# Solution: Sorting + Hash Map

## Solution Overview

This solution assigns ranks to each distinct element after sorting the array.

Key ideas:
- Create a copy of the original array.
- Sort the copied array.
- Assign ranks only to unique elements.
- Store the assigned rank of each value in a hash map.
- Traverse the original array and replace every element with its corresponding rank.

This ensures equal values receive the same rank while maintaining the smallest possible ranks.

---

## Algorithm

### Step 1: Copy the Array

Create a copy of the original array:

```cpp
vector<int> ans = arr;
```

This preserves the original order while allowing the copy to be sorted.

---

### Step 2: Sort the Copy

Sort the copied array:

```cpp
sort(ans.begin(), ans.end());
```

Now all values are arranged in increasing order.

---

### Step 3: Assign Ranks to Unique Values

Create a hash map:

```cpp
unordered_map<int, int> rank;
```

Initialize:

```cpp
currentRank = 1;
```

Traverse the sorted array.

- The first element is assigned rank:

```cpp
1
```

- Whenever a new distinct value is encountered:

```cpp
ans[i] != ans[i - 1]
```

increment the rank:

```cpp
currentRank++;
```

Store the mapping:

```cpp
rank[ans[i]] = currentRank;
```

Duplicate values are skipped since they share the same rank.

---

### Step 4: Transform the Original Array

Traverse the original array.

Replace each element with:

```cpp
rank[arr[i]];
```

---

### Step 5: Return Result

Return the transformed array:

```cpp
arr;
```

---

## Complexity Analysis

Let:

```cpp
n = arr.size()
```

### Time Complexity

Copying the array:

```cpp
O(n)
```

Sorting:

```cpp
O(n log n)
```

Assigning ranks:

```cpp
O(n)
```

Transforming the original array:

```cpp
O(n)
```

Overall:

```cpp
O(n log n)
```

---

### Space Complexity

Copied array:

```cpp
O(n)
```

Hash map:

```cpp
O(n)
```

Overall:

```cpp
O(n)
```

---

## Notes

- Uses sorting to process elements in ascending order.
- Assigns ranks only to distinct values.
- Equal elements receive the same rank.
- A hash map enables constant-time lookup while transforming the original array.
- Ranks start from `1` and increase only when a new unique value is encountered.
- This is the standard optimal solution for the problem.
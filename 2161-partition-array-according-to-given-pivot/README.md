# Partition Array According to Given Pivot

## Problem Statement

Given a 0-indexed integer array `nums` and an integer `pivot`, rearrange `nums` such that:

- Every element less than `pivot` appears before every element greater than `pivot`.
- Every element equal to `pivot` appears between the elements less than and greater than `pivot`.
- The relative order of the elements less than `pivot` is maintained.
- The relative order of the elements greater than `pivot` is maintained.

Return the resulting array.

---

# Solution: Three Separate Arrays

## Solution Overview

This solution partitions the array into three groups:

- Elements less than `pivot`
- Elements equal to `pivot`
- Elements greater than `pivot`

Key ideas:
- Traverse the array once.
- Store elements in separate vectors based on their relationship with `pivot`.
- Concatenate the vectors in the required order.
- Since elements are added sequentially, their relative ordering is preserved.

This directly satisfies all problem requirements.

---

## Algorithm

### Step 1: Create Three Vectors

Initialize:

```cpp
v1 = {}
```

for elements less than `pivot`.

```cpp
v2 = {}
```

for elements greater than `pivot`.

```cpp
v3 = {}
```

for elements equal to `pivot`.

---

### Step 2: Partition Elements

Traverse the array.

For each element:

#### Less Than Pivot

```cpp
nums[i] < pivot
```

Insert into:

```cpp
v1
```

#### Equal To Pivot

```cpp
nums[i] == pivot
```

Insert into:

```cpp
v3
```

#### Greater Than Pivot

```cpp
nums[i] > pivot
```

Insert into:

```cpp
v2
```

---

### Step 3: Combine Results

Append:

```cpp
v3
```

to:

```cpp
v1
```

Then append:

```cpp
v2
```

to:

```cpp
v1
```

Result:

```cpp
[ elements < pivot ]
[ elements = pivot ]
[ elements > pivot ]
```

---

### Step 4: Return Answer

Return:

```cpp
v1
```

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

### Time Complexity

- Traversal: `O(n)`
- Merging vectors: `O(n)`

Overall:

```cpp
O(n)
```

---

### Space Complexity

```cpp
O(n)
```

Three auxiliary vectors store all elements.

---

## Notes

- Preserves the relative ordering of elements.
- Uses three separate containers for clarity.
- Requires additional linear space.
- Simple and intuitive partitioning approach.
- Avoids complex in-place rearrangement logic.
- This is a common stable partition solution for the problem.
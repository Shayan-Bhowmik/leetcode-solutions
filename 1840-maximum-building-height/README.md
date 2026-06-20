# Maximum Building Height

## Problem Statement

You want to build `n` buildings in a line.

Some buildings have height restrictions given by:

```cpp
restrictions[i] = [idi, maxHeighti]
```

meaning building `idi` must have a height less than or equal to `maxHeighti`.

Additionally:

- Building `1` must have height `0`.
- The height difference between adjacent buildings can be at most `1`.

Return the maximum possible height of the tallest building.

---

# Solution: Constraint Propagation + Peak Calculation

## Solution Overview

This solution first propagates all height constraints so that every restriction becomes feasible under the adjacency rule.

Key ideas:
- Add the mandatory restriction:
  ```cpp
  building 1 = height 0
  ```
- Sort restrictions by building index.
- Perform:
  - Left-to-right propagation.
  - Right-to-left propagation.
- After propagation, every restriction satisfies all neighboring constraints.
- For each pair of adjacent restrictions, compute the highest peak achievable between them.
- Also consider the segment after the last restriction.

This yields the maximum possible building height.

---

## Algorithm

### Step 1: Add Mandatory Restriction

Insert:

```cpp
{1, 0}
```

into the restrictions list.

This represents:

```cpp
height(1) = 0
```

---

### Step 2: Sort Restrictions

Sort by building index:

```cpp
sort(restrictions.begin(), restrictions.end());
```

---

### Step 3: Left-to-Right Propagation

For every restriction:

```cpp
i = 1 ... m-1
```

update:

```cpp
restrictions[i][1]
=
min(
    restrictions[i][1],
    restrictions[i-1][1]
    +
    (restrictions[i][0] - restrictions[i-1][0])
)
```

This enforces:

```cpp
|height difference| ≤ 1
```

from the left side.

---

### Step 4: Right-to-Left Propagation

Traverse backwards:

```cpp
i = m-2 ... 0
```

update:

```cpp
restrictions[i][1]
=
min(
    restrictions[i][1],
    restrictions[i+1][1]
    +
    (restrictions[i+1][0] - restrictions[i][0])
)
```

This enforces all constraints from the right side.

---

### Step 5: Compute Maximum Peak Between Restrictions

For two neighboring restrictions:

```cpp
(p1, h1)
```

and

```cpp
(p2, h2)
```

let:

```cpp
dist = p2 - p1
```

The highest achievable peak between them is:

```cpp
(dist + h1 + h2) / 2
```

Compute:

```cpp
peak =
(dist + h1 + h2) / 2
```

Update:

```cpp
ans = max(ans, peak)
```

for every adjacent pair.

---

### Step 6: Handle Buildings After Last Restriction

After the final restriction:

```cpp
(lastPos, lastHeight)
```

the height can continue increasing by at most `1` per building.

Maximum possible height becomes:

```cpp
lastHeight + (n - lastPos)
```

Update:

```cpp
ans =
max(
    ans,
    lastHeight + (n - lastPos)
)
```

---

### Step 7: Return Answer

Return:

```cpp
ans
```

---

## Complexity Analysis

Let:

```cpp
m = restrictions.size()
```

### Time Complexity

Sorting:

```cpp
O(m log m)
```

Left-to-right pass:

```cpp
O(m)
```

Right-to-left pass:

```cpp
O(m)
```

Peak computation:

```cpp
O(m)
```

Overall:

```cpp
O(m log m)
```

---

### Space Complexity

```cpp
O(1)
```

Ignoring the space used by the input restriction array.

---

## Notes

- Building `1` is always fixed at height `0`.
- Constraint propagation makes all restrictions mutually consistent.
- The tallest building can occur between two restrictions, not necessarily at a restricted building.
- The peak formula:
  ```cpp
  (distance + h1 + h2) / 2
  ```
  computes the highest feasible meeting point.
- The final unrestricted segment must also be considered.
- This is the standard optimal solution for the problem.
- Efficiently handles very large values of `n`.
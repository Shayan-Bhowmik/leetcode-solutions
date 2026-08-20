# Cinema Seat Allocation

## Problem Statement

You are given:

```cpp
n
```

representing the number of rows in a cinema.

Each row has **10 seats**, numbered:

```text
1 2 3 4 5 6 7 8 9 10
```

Some seats are already reserved.

A family of **4 people** can sit together in one of these three possible blocks:

```text
2 3 4 5
4 5 6 7
6 7 8 9
```

Notice that seats `1` and `10` are never used by a family.

For every row:

- If the row is completely free, it can accommodate **2 families**.
- If reservations interfere with the possible blocks, the row may accommodate **1 or 0 families**.

Return the maximum number of families that can be seated.

---

# Solution: Sorting + Flags

## Solution Overview

The key observation is:

> Every row can initially accommodate 2 families.

So start with:

```cpp
int ans = n * 2;
```

Then only rows that contain reserved seats need to be examined.

The code sorts:

```cpp
reservedSeats
```

by row number.

This allows us to process all reservations belonging to the same row together.

---

# Step 1: Assume Every Row Has 2 Families

Initially:

```cpp
int ans = n * 2;
```

Why?

A completely empty row can fit:

```text
[2 3 4 5]      [6 7 8 9]
```

So:

```text
2 families per row
```

Therefore:

```text
n rows × 2 families = 2n
```

is the maximum possible answer before considering reservations.

---

# Step 2: Sort the Reservations

```cpp
sort(reservedSeats.begin(), reservedSeats.end());
```

The reservations become grouped by row.

For example:

```text
[1,2]
[1,5]
[1,8]
[3,4]
[3,7]
```

Rows `1` and `3` can be processed independently.

---

# Step 3: Track the Three Possible Blocks

For every row, the code uses:

```cpp
int flag25 = 1;
int flag47 = 1;
int flag69 = 1;
```

These represent the three possible family blocks.

### `flag25`

Represents:

```text
seats 2-5
```

Initially:

```cpp
flag25 = 1;
```

meaning the block is available.

If a reserved seat is between `2` and `5`:

```cpp
if (seat >= 2 && seat <= 5)
    flag25 = 0;
```

the block becomes unavailable.

---

### `flag47`

Represents:

```text
seats 4-7
```

It is blocked if a reserved seat occurs in:

```text
4, 5, 6, 7
```

The code detects these through the two surrounding ranges:

```cpp
if (seat >= 4 && seat <= 5)
    flag47 = 0;
```

and:

```cpp
if (seat >= 6 && seat <= 7)
    flag47 = 0;
```

Together they represent:

```text
4-7
```

---

### `flag69`

Represents:

```text
seats 6-9
```

If a reserved seat lies between:

```text
6 and 9
```

then:

```cpp
flag69 = 0;
```

---

# Step 4: Process One Row at a Time

The variable:

```cpp
curr
```

stores the current row:

```cpp
int curr = reservedSeats[i][0];
```

Then:

```cpp
while(i < reservedSeats.size() &&
      reservedSeats[i][0] == curr)
```

processes all reserved seats belonging to that row.

This is important because the three family blocks are determined independently for each row.

---

# Step 5: Determine How Many Families Are Lost

After processing a row, there are three possibilities.

---

## Case 1: All Three Blocks Are Blocked

```cpp
if(flag69 == 0 &&
   flag25 == 0 &&
   flag47 == 0)
```

The row cannot accommodate any family.

A row originally contributed:

```text
2 families
```

So we subtract:

```cpp
ans--;
ans--;
```

which is equivalent to:

```cpp
ans -= 2;
```

---

## Case 2: At Least One Block Is Blocked

```cpp
else if(flag69 == 0 ||
        flag47 == 0 ||
        flag25 == 0)
```

The row can still accommodate one family, but not two.

So we remove one family:

```cpp
ans--;
```

---

## Case 3: No Relevant Block Is Blocked

If all three flags remain `1`, then the row can still accommodate:

```text
2 families
```

so nothing is subtracted.

---

# Example

Suppose a row has reservations:

```text
[1, 2]
```

Seat `2` blocks:

```text
2-5
```

So:

```text
flag25 = 0
flag47 = 1
flag69 = 1
```

We can still place one family:

```text
6 7 8 9
```

Therefore, this row loses one possible family.

---

## Another Example

Suppose the row has:

```text
reserved = [4, 7]
```

Then:

```text
2-5 → blocked
4-7 → blocked
6-9 → blocked
```

So:

```text
flag25 = 0
flag47 = 0
flag69 = 0
```

No family can be placed.

The row loses both possible families.

---

# Why the Three Blocks Work

The possible placements are:

```text
2 3 4 5
```

or:

```text
4 5 6 7
```

or:

```text
6 7 8 9
```

If both the left and right blocks are available:

```text
[2 3 4 5]   [6 7 8 9]
```

we can seat two families.

If one of them is blocked, we may still use the other.

The middle block:

```text
[4 5 6 7]
```

is useful when one side is blocked but the remaining seats allow a family through the middle.

---

# Complexity Analysis

Let:

```cpp
m = reservedSeats.size()
```

### Sorting

```cpp
sort(reservedSeats.begin(), reservedSeats.end());
```

takes:

```text
O(m log m)
```

### Processing Reservations

Each reservation is processed once:

```text
O(m)
```

### Total Time Complexity

```text
O(m log m)
```

---

### Space Complexity

Apart from the input array, the algorithm uses only a constant number of variables:

```text
O(1)
```

---

# Notes

- Start with:
  ```cpp
  2 * n
  ```
  because every empty row can fit two families.
- Only rows containing reservations need to be examined.
- Sort reservations so all seats belonging to the same row are processed together.
- Track the three possible family blocks:
  ```text
  2-5
  4-7
  6-9
  ```
- If all three are blocked → subtract `2`.
- If at least one is blocked → subtract `1`.
- If none are blocked → subtract nothing.
- Time complexity: **O(m log m)**.
- Space complexity: **O(1)** excluding the input.
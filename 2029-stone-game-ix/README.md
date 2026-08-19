# Stone Game IX

## Problem Statement

You are given an array:

```cpp
stones
```

Alice and Bob take turns removing exactly one stone.

The game follows these rules:

- The value of the removed stone is added to a running sum.
- If the running sum becomes divisible by `3`, the player who made that move **loses immediately**.
- If all stones are removed without anyone losing, the result is a draw.
- Alice plays first.
- Both players play optimally.

Return:

```cpp
true
```

if Alice can win, otherwise return:

```cpp
false
```

---

# Solution: Counting Remainders

## Solution Overview

The actual values of the stones do not matter.

Only their remainders when divided by `3` matter:

```text
0, 1, 2
```

So we count how many stones belong to each remainder class.

```cpp
f[0] = number of stones % 3 == 0
f[1] = number of stones % 3 == 1
f[2] = number of stones % 3 == 2
```

The game then becomes a strategy based only on these three counts.

---

# Step 1: Count the Remainders

For every stone:

```cpp
f[s % 3]++;
```

For example:

```text
stones = [2, 3, 5, 6, 8]
```

Their remainders are:

```text
2, 0, 2, 0, 2
```

Therefore:

```text
f[0] = 2
f[1] = 0
f[2] = 3
```

---

# Why Remainder 0 Is Special

A stone whose remainder is `0` does not change the current sum modulo `3`.

For example:

```text
current sum % 3 = 1
```

Adding a remainder-`0` stone gives:

```text
1 + 0 = 1 (mod 3)
```

So these stones essentially allow the game to continue without changing the modulo state.

The important moves are therefore stones with remainder:

```text
1
```

and:

```text
2
```

because:

```text
1 + 2 = 0 (mod 3)
```

and:

```text
2 + 1 = 0 (mod 3)
```

A player who is forced to make the sum become `0 mod 3` loses.

---

# Case 1: Number of Remainder-0 Stones Is Even

The code checks:

```cpp
if (~f[0] & 1)
```

This is equivalent to:

```cpp
if (f[0] % 2 == 0)
```

So when the number of `0`-remainder stones is even, Alice can win exactly when:

```cpp
min(f[1], f[2]) >= 1
```

In other words, there must be at least:

```text
one remainder-1 stone
```

and:

```text
one remainder-2 stone
```

Therefore:

```cpp
return min(f[1], f[2]) >= 1;
```

---

# Case 2: Number of Remainder-0 Stones Is Odd

When:

```cpp
f[0] % 2 == 1
```

the winning condition becomes:

```cpp
abs(f[1] - f[2]) >= 3
```

So Alice wins if the counts of remainder-1 and remainder-2 stones differ by at least `3`.

For example:

```text
f[1] = 5
f[2] = 2
```

Then:

```text
|5 - 2| = 3
```

so Alice can force a win.

---

# The Core Idea

The game alternates between needing a stone with remainder:

```text
1
```

and:

```text
2
```

because these remainders change the current sum modulo `3`.

If the current sum is:

```text
1
```

taking another `1` gives:

```text
1 + 1 = 2
```

while taking a `2` gives:

```text
1 + 2 = 0
```

which immediately loses.

Similarly, when the current sum is `2`, taking remainder `1` would produce:

```text
2 + 1 = 0
```

and lose.

Thus, players are effectively forced to alternate between remainder classes.

The number of `0`-remainder stones determines whether this alternating structure favors Alice or Bob.

---

# Understanding the Code

The first part:

```cpp
int f[3] = {0, 0, 0};

for (auto& s : stones)
    f[s % 3]++;
```

counts the three remainder classes.

Then:

```cpp
if (~f[0] & 1)
```

checks whether `f[0]` is even.

The bitwise trick:

```cpp
~f[0] & 1
```

works because:

- If `f[0]` is even, its least significant bit is `0`.
- `~f[0]` therefore has least significant bit `1`.

So this is simply an unusual way of writing:

```cpp
if (f[0] % 2 == 0)
```

Finally:

```cpp
return abs(f[1] - f[2]) >= 3;
```

handles the odd `f[0]` case.

---

# Complexity Analysis

Let:

```cpp
n = stones.size()
```

### Time Complexity

We traverse the array once:

```text
O(n)
```

### Space Complexity

Only three counters are used:

```text
O(1)
```

---

## Notes

- The actual stone values are irrelevant; only `stone % 3` matters.
- `f[0]`, `f[1]`, and `f[2]` count stones by remainder.
- Remainder `0` stones do not change the current sum modulo `3`.
- The game essentially depends on how Alice and Bob alternate between remainder `1` and remainder `2` stones.
- The compact condition:
  ```cpp
  ~f[0] & 1
  ```
  means `f[0]` is even.
- The solution runs in **O(n)** time and **O(1)** space.
- This is the standard optimal counting solution for LeetCode 2029.
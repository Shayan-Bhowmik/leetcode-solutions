# Find the Number of Subsequences With Equal GCD

## Problem Statement

You are given an integer array:

```cpp
nums
```

Construct two subsequences from the array such that:

- Each element can be assigned to:
  - the first subsequence,
  - the second subsequence, or
  - neither subsequence.
- Both subsequences must have the **same GCD**.

Return the number of valid pairs of subsequences modulo:

```cpp
10^9 + 7
```

---

# Solution: Dynamic Programming on GCD States

## Solution Overview

This solution uses **Dynamic Programming** where each state stores the GCDs of the two subsequences built so far.

Key ideas:
- Process the array one element at a time.
- Every element has three choices:
  - Ignore it.
  - Add it to the first subsequence.
  - Add it to the second subsequence.
- Maintain the current GCD of both subsequences.
- At the end, count all states where both subsequences have the same non-zero GCD.

Since every number is at most `200`, there are only a limited number of possible GCD values, making the DP efficient.

---

## Dynamic Programming State

Define:

```cpp
dp[g1][g2]
```

where:

- `g1` = current GCD of the first subsequence.
- `g2` = current GCD of the second subsequence.

The value stores the number of ways to reach this state.

Initially:

```cpp
dp[0][0] = 1;
```

where GCD `0` represents an empty subsequence.

---

## Algorithm

### Step 1: Initialize DP

Create:

```cpp
dp[201][201]
```

Initialize all values to:

```cpp
0
```

Set:

```cpp
dp[0][0] = 1;
```

---

### Step 2: Process Every Number

For every element:

```cpp
x
```

create a copy:

```cpp
ndp = dp;
```

This copy automatically handles the option of **not selecting** the current element.

---

### Step 3: Add to First Subsequence

For every state:

```cpp
(g1, g2)
```

compute the new GCD:

```cpp
ng1 =
(g1 == 0)
?
x
:
gcd(g1, x);
```

Update:

```cpp
ndp[ng1][g2]
+=
dp[g1][g2];
```

---

### Step 4: Add to Second Subsequence

Similarly compute:

```cpp
ng2 =
(g2 == 0)
?
x
:
gcd(g2, x);
```

Update:

```cpp
ndp[g1][ng2]
+=
dp[g1][g2];
```

All updates are performed modulo:

```cpp
10^9 + 7
```

---

### Step 5: Move to Next Iteration

After processing the current element:

```cpp
dp = move(ndp);
```

---

### Step 6: Compute Answer

Traverse all possible GCD values:

```cpp
g = 1 ... 200
```

Whenever:

```cpp
g1 == g2
```

add:

```cpp
dp[g][g]
```

to the answer.

Return:

```cpp
ans % MOD;
```

---

## Why GCD is Updated This Way

Suppose the current GCD is:

```cpp
g
```

and we insert a new element:

```cpp
x
```

The new GCD becomes:

```cpp
gcd(g, x)
```

If the subsequence is empty:

```cpp
g == 0
```

then its GCD becomes:

```cpp
x
```

This transition correctly maintains the GCD after every insertion.

---

## Complexity Analysis

Let:

```cpp
n = nums.size()
```

Maximum possible GCD:

```cpp
MAX = 200
```

### Time Complexity

For every element:

```cpp
201 × 201
```

states are processed.

Overall:

```cpp
O(n × MAX²)
```

Since:

```cpp
MAX = 200
```

this becomes:

```cpp
O(n × 200²)
```

---

### Space Complexity

DP table:

```cpp
201 × 201
```

Overall:

```cpp
O(MAX²)
```

---

## Notes

- Uses Dynamic Programming on GCD states.
- GCD value `0` represents an empty subsequence.
- Every element has three choices:
  - Ignore it.
  - Add it to the first subsequence.
  - Add it to the second subsequence.
- The DP stores the current GCDs of both subsequences.
- At the end, only states with equal non-zero GCDs contribute to the answer.
- All computations are performed modulo:
  ```cpp
  10^9 + 7
  ```
- This is the standard optimal solution for the problem.
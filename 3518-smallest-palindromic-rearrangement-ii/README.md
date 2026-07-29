# K-th Smallest Palindromic Rearrangement

## Problem Statement

You are given:

```cpp
string s
```

which is guaranteed to be rearrangeable into a palindrome, and an integer:

```cpp
k
```

Return the **k-th lexicographically smallest palindromic rearrangement** of `s`.

If fewer than `k` distinct palindromic rearrangements exist, return:

```cpp
""
```

---

# Solution: Greedy Construction + Combinatorics

## Solution Overview

This solution constructs the palindrome one character at a time using **combinatorial counting**.

Key ideas:
- Only the left half of the palindrome needs to be constructed.
- Count the frequency of every character appearing in the left half.
- At every position, try placing characters from `'a'` to `'z'`.
- Use combinations to count how many palindromes can be formed after fixing a character.
- If the number of possible palindromes is less than `k`, skip those arrangements.
- Otherwise, fix that character and continue.
- Finally, mirror the left half to obtain the complete palindrome.

The solution avoids generating every permutation explicitly.

---

## Algorithm

### Step 1: Precompute Binomial Coefficients

Generate Pascal's Triangle:

```cpp
C[n][k]
```

using:

```cpp
Pascal();
```

This allows fast computation of combinations for small values.

---

### Step 2: Compute Half Frequencies

Only the first half of the palindrome determines the entire arrangement.

For every character in the left half:

```cpp
freq[c]++;
```

Store these frequencies.

---

### Step 3: Count Total Palindromes

Compute the number of distinct left-half permutations using:

```cpp
perm(freq, n / 2)
```

which evaluates the multinomial coefficient.

If:

```cpp
k > total
```

return:

```cpp
""
```

since the requested palindrome does not exist.

---

### Step 4: Build the Left Half Greedily

For every position in the left half:

Try every character from:

```cpp
'a'
```

to

```cpp
'z'
```

temporarily decrease its frequency:

```cpp
freq[c]--;
```

Count the number of valid completions:

```cpp
cnt = perm(freq, remainingLength);
```

If:

```cpp
cnt >= k
```

keep the character.

Otherwise:

```cpp
k -= cnt;
```

restore the frequency and try the next character.

Repeat until the left half is complete.

---

### Step 5: Construct the Full Palindrome

Create the right half by reversing the left half:

```cpp
right = left;
reverse(right.begin(), right.end());
```

If the string length is odd:

```cpp
left.push_back(middleCharacter);
```

Finally:

```cpp
left += right;
```

Return the resulting palindrome.

---

## Computing the Number of Permutations

Suppose there are:

```cpp
sz
```

remaining positions and character frequencies:

```cpp
f₁, f₂, ..., fₖ
```

The number of distinct permutations is the multinomial coefficient:

```text
sz!
--------------------
f₁! × f₂! × ... × fₖ!
```

The implementation computes this efficiently using repeated binomial coefficients:

```cpp
comb(sz, f)
```

which avoids directly computing large factorials.

---

## Why the Greedy Choice Works

At every position, characters are considered in lexicographical order.

For each candidate character:

- Count how many valid palindromes begin with that choice.
- If that count is at least `k`, the desired palindrome starts with this character.
- Otherwise, skip all those palindromes by subtracting their count from `k`.

Repeating this process constructs exactly the **k-th lexicographically smallest** palindrome without enumerating all possibilities.

---

## Complexity Analysis

Let:

```cpp
n = s.length()
```

### Time Complexity

Building Pascal's Triangle:

```cpp
O(1)
```

(since its size is fixed).

Constructing the palindrome:

```cpp
O(26 × n)
```

Each permutation count processes at most 26 characters.

Overall:

```cpp
O(26 × n)
```

---

### Space Complexity

Frequency array:

```cpp
O(26)
```

Pascal table:

```cpp
O(1)
```

Output string:

```cpp
O(n)
```

Overall:

```cpp
O(n)
```

---

## Notes

- Uses combinatorial counting instead of generating all palindromes.
- Precomputes binomial coefficients using Pascal's Triangle.
- Computes permutation counts using multinomial coefficients.
- Greedily constructs the left half in lexicographical order.
- Mirrors the left half to form the complete palindrome.
- Returns an empty string if fewer than `k` palindromic rearrangements exist.
- This is the standard optimal solution for the problem.
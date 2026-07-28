# Find the Number of Unique XOR Triplets II

## Problem Statement

You are given an integer array:

```cpp
nums
```

Return the number of distinct values that can be obtained by taking the XOR of every possible triplet of elements from the array.

The answer should count only the unique XOR values that can be formed.

---

# Solution: Fast Walsh-Hadamard Transform (FWHT)

## Solution Overview

This solution uses the **Fast Walsh-Hadamard Transform (FWHT)** to efficiently compute the XOR convolution of the array with itself three times.

Key ideas:
- Represent the input values as a frequency array.
- Apply the Walsh-Hadamard Transform to convert the frequency array into the XOR domain.
- Cube every transformed value, which corresponds to performing a three-way XOR convolution.
- Apply the inverse transform to recover the frequencies of every possible XOR result.
- Count how many XOR values appear at least once.

This approach avoids explicitly checking all triplets, making it much faster for larger inputs.

---

## Algorithm

### Step 1: Build the Frequency Array

Create a frequency array of fixed size:

```cpp
MAXX = 2048
```

Initialize:

```cpp
f[x] = 1;
```

for every value present in:

```cpp
nums
```

---

### Step 2: Apply the Fast Walsh-Hadamard Transform

Perform the Walsh-Hadamard Transform on the frequency array.

For every block size:

```cpp
len = 1, 2, 4, ...
```

combine pairs of values using:

```cpp
a + b
```

and

```cpp
a - b
```

This converts the array into the XOR transform domain.

---

### Step 3: Perform Triple XOR Convolution

Once in the transform domain, cube every value:

```cpp
f[i] = f[i] * f[i] * f[i];
```

Cubing corresponds to combining three arrays under the XOR operation.

---

### Step 4: Apply the Inverse Transform

Run the inverse Walsh-Hadamard Transform.

For every block:

```cpp
(a + b) / 2
```

and

```cpp
(a - b) / 2
```

are used to reconstruct the original frequency domain.

After this step:

```cpp
f[i]
```

stores the number of triplets whose XOR equals:

```cpp
i
```

---

### Step 5: Count Distinct XOR Values

Traverse the resulting frequency array.

If:

```cpp
f[i] > 0
```

then XOR value:

```cpp
i
```

can be produced by at least one triplet.

Increment the answer.

---

### Step 6: Return the Answer

Return:

```cpp
ans;
```

---

## Why the Walsh-Hadamard Transform Works

The Walsh-Hadamard Transform is the XOR equivalent of the Fast Fourier Transform.

It converts XOR convolution into simple pointwise multiplication.

Instead of computing all triplets explicitly:

```cpp
a ^ b ^ c
```

the transform allows us to:

1. Transform the frequency array.
2. Multiply (cube) the transformed values.
3. Apply the inverse transform.

This efficiently computes the frequency of every possible XOR result.

---

## Complexity Analysis

Let:

```cpp
M = 2048
```

be the maximum XOR value range.

### Time Complexity

Building the frequency array:

```cpp
O(n)
```

Forward Walsh-Hadamard Transform:

```cpp
O(M log M)
```

Cubing every transformed value:

```cpp
O(M)
```

Inverse Walsh-Hadamard Transform:

```cpp
O(M log M)
```

Counting the results:

```cpp
O(M)
```

Overall:

```cpp
O(n + M log M)
```

---

### Space Complexity

Frequency array:

```cpp
O(M)
```

Overall:

```cpp
O(M)
```

---

## Notes

- Uses the Fast Walsh-Hadamard Transform (FWHT) for XOR convolution.
- Represents the input as a frequency array.
- Cubes the transformed frequencies to compute all XOR triplets.
- Applies the inverse transform to recover the frequency of each XOR value.
- Counts every XOR value that appears at least once.
- Avoids the naive `O(n³)` approach.
- This is the standard optimal solution for the problem.
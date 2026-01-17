# Count Primes

## Problem Statement
Given an integer `n`, return the number of **prime numbers** that are **strictly less than `n`**.

A prime number is a natural number greater than `1` that has no positive divisors other than `1` and itself.

---

## Approach 1: Brute Force (Leads to TLE)

### Solution Overview
The first approach checks **each number individually** to determine whether it is prime.

For every number from `2` to `n - 1`:
- It tests divisibility by all numbers up to its square root
- If no divisor is found, the number is counted as prime

While logically correct, this approach is **computationally expensive** for large values of `n`.

---

### Algorithm
1. Initialize a counter `count` to `0`.
2. For every number `i` from `2` to `n - 1`:
   - Assume `i` is prime.
   - Check divisibility from `2` to `√i`.
   - If divisible, mark it as non-prime.
3. If `i` is prime, increment `count`.
4. Return `count`.

---

### Complexity Analysis
- **Time Complexity:** `O(n √n)`  
  Each number requires a square-root check.
- **Space Complexity:** `O(1)`

---

### Limitations
- This approach exceeds the time limits for large inputs.
- Repeated primality checks make it inefficient.

---

## Approach 2: Sieve of Eratosthenes (Optimized)

### Solution Overview
The optimized solution uses the **Sieve of Eratosthenes**, a classic algorithm for efficiently finding prime numbers.

The idea is:
- Assume all numbers are prime initially
- Iteratively mark multiples of each prime as non-prime
- Count the numbers that remain marked as prime

---

### Algorithm
1. Create a boolean array `isPrime` of size `n + 1`, initialized to `true`.
2. Iterate from `2` to `n - 1`:
   - If `isPrime[i]` is `true`, increment the prime counter.
   - Mark all multiples of `i` (starting from `2i`) as `false`.
3. Return the total count of primes.

---

### Complexity Analysis
- **Time Complexity:** `O(n log log n)`  
  Efficient marking of multiples.
- **Space Complexity:** `O(n)`  
  Boolean array used to track prime numbers.

---

## Notes
- The brute-force solution is useful for understanding primality testing but does not scale.
- The Sieve of Eratosthenes is the standard optimized approach for this problem.
- This problem highlights the importance of choosing the right algorithm for large inputs.
- Further optimization can be achieved by starting the marking process from `i * i`.
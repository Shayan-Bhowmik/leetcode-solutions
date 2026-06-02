# Minimum Cost of Buying Candies With Discount

## Problem Statement

A shop is selling candies at various prices given by the array `cost`.

You can buy any two candies and get a third candy for free, provided that the cost of the free candy is less than or equal to the minimum cost of the two candies purchased.

Return the minimum cost needed to buy all the candies.

---

# Solution: Sorting + Greedy Selection

## Solution Overview

This solution uses a **greedy strategy** after sorting the candy prices.

Key ideas:
- Sort the candies in ascending order.
- Buy the most expensive candies first.
- For every group of three candies:
  - Pay for the two most expensive candies.
  - Get the third candy (the cheapest in the group) for free.
- Repeating this process minimizes the total amount paid.

The greedy choice works because making the cheapest candy in each group free maximizes the discount.

---

## Algorithm

1. Sort the `cost` array in ascending order.
2. Initialize `total_sum = 0`.
3. Traverse the array from the end:
   - Move in steps of `3`.
4. For each group:
   - Add the most expensive candy:
     ```cpp
     cost[i]
     ```
   - If another candy exists:
     ```cpp
     cost[i - 1]
     ```
     add it to the total.
   - Skip the third candy since it is free.
5. Return `total_sum`.

---

## Complexity Analysis

- **Time Complexity:** `O(n log n)`
  
  Sorting dominates the running time.

- **Space Complexity:** `O(1)`
  
  Ignoring the space used by the sorting algorithm.

---

## Notes

- Sorting allows the discount to be applied optimally.
- Every third candy in descending order becomes free.
- The traversal starts from the most expensive candies.
- Greedy selection guarantees the minimum total cost.
- This is the standard optimal solution for the problem.
- No additional data structures are required.
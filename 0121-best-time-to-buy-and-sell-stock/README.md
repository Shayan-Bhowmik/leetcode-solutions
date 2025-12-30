# Best Time to Buy and Sell Stock

## Problem Statement
You are given an array `prices` where `prices[i]` is the price of a given stock on the `iᵗʰ` day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

---

## Solution Overview
This problem is solved using a **single-pass greedy approach**.

The idea is to track the **minimum price so far** (best day to buy) and compute the maximum profit that can be achieved by selling on each subsequent day.

---

## Algorithm
1. Initialize:
   - `bestBuy` as the price on day `0`
   - `maxProfit` as `0`
2. Traverse the array from day `1` onward:
   - If the current price is greater than `bestBuy`, compute the profit and update `maxProfit` if it is higher.
   - Update `bestBuy` to the minimum price seen so far.
3. Return `maxProfit`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Notes
- Only one transaction (one buy and one sell) is allowed.
- The selling day must occur **after** the buying day.
- This approach efficiently handles all cases, including decreasing price sequences where no profit is possible.
# Majority Element

## Problem Statement
Given an array `nums` of size `n`, return the majority element.

The majority element is the element that appears **more than ⌊n / 2⌋ times**.  
You may assume that the majority element always exists in the array.

---

## Solution Overview
This problem is solved using the **Boyer–Moore Voting Algorithm**.

The algorithm works by maintaining a candidate element and a counter.  
Whenever the counter reaches zero, a new candidate is selected.  
Since the majority element appears more than half the time, it will remain as the final candidate.

---

## Algorithm
1. Initialize:
   - `freq` to track the vote count
   - `ans` to store the current candidate
2. Traverse the array:
   - If `freq` is `0`, set the current element as the candidate.
   - If the current element equals the candidate, increment `freq`.
   - Otherwise, decrement `freq`.
3. After traversal, `ans` will contain the majority element.
4. Return `ans`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Notes
- This approach guarantees linear time and constant space.
- It relies on the fact that the majority element appears more than half the time.
- Boyer–Moore is the optimal and intended solution for this problem.
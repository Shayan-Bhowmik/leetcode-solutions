# Find the Duplicate Number

## Problem Statement
You are given an integer array `nums` containing `n + 1` integers.

Each integer is in the range `[1, n]` inclusive.

Exactly:
- One number appears more than once (duplicate).
- All other numbers appear exactly once.

Return the duplicate number.

---

## Approach: Floyd’s Cycle Detection (Tortoise and Hare Algorithm)

### Solution Overview

Since the numbers are in the range `[1, n]`, we can treat the array as a **linked list** where:

- Each index represents a node.
- The value at each index represents the next pointer.

Because one number is repeated, there must be a **cycle** in this structure.

We use **Floyd’s Cycle Detection Algorithm**, which works in two phases:

1. **Detect the intersection point** inside the cycle.
2. **Find the entrance of the cycle**, which is the duplicate number.

This allows us to solve the problem efficiently without modifying the array and using constant extra space.

---

## Algorithm

1. Initialize two pointers:
   - `slow = nums[0]`
   - `fast = nums[0]`

2. Move pointers until they meet:
   - `slow = nums[slow]`
   - `fast = nums[nums[fast]]`
   - Continue until `slow == fast`

3. Reset `slow` to `nums[0]`.

4. Move both pointers one step at a time:
   - `slow = nums[slow]`
   - `fast = nums[fast]`
   - Continue until they meet again.

5. The meeting point is the duplicate number.

6. Return `slow`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`  
  The array is traversed at most twice.

- **Space Complexity:** `O(1)`  
  No extra data structures are used.

---

## Notes

- The array is not modified.
- No extra memory like hash sets is required.
- The solution relies on cycle detection logic.
- This is an optimal approach in both time and space.
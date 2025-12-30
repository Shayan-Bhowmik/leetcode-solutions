# Single Number

## Problem Statement
Given a non-empty array of integers `nums`, every element appears twice except for one.  
Find that single one.

You must implement a solution with **linear runtime complexity** and use **constant extra space**.

---

## Solution Overview
This problem is solved using the **bitwise XOR operation**.

The key observation is that XOR has the following properties:
- `a ^ a = 0`
- `a ^ 0 = a`
- XOR is commutative and associative

By XOR-ing all elements in the array, all duplicate numbers cancel each other out, leaving only the number that appears once.

---

## Algorithm
1. Initialize a variable `value` to `0`.
2. Iterate through the array:
   - XOR the current element with `value`.
3. After processing all elements, `value` will hold the single number.
4. Return `value`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Notes
- This approach satisfies the problem’s constraints of linear time and constant space.
- It avoids the need for extra data structures such as hash maps.
- The XOR technique is a common and efficient pattern for problems involving pairs.
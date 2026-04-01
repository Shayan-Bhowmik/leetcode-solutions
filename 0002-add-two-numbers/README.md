# Add Two Numbers

## Problem Statement
You are given two **non-empty linked lists** representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit.

Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number `0` itself.

---

# Solution: Linked List Traversal + Carry Handling

## Solution Overview
This solution simulates the addition of two numbers digit by digit, similar to manual addition.

Key ideas:
- Traverse both linked lists simultaneously.
- Maintain a `carry` for sums greater than 9.
- Use a dummy head node to simplify list construction.
- Continue until both lists and carry are fully processed.

---

## Algorithm
1. Create a dummy node `dummyHead` to store the result.
2. Initialize pointer `curr` to dummy node and `carry = 0`.
3. Traverse while `l1`, `l2`, or `carry` exists:
   - Initialize `total = carry`.
   - If `l1` exists:
     - Add `l1->val` to `total`
     - Move `l1` forward
   - If `l2` exists:
     - Add `l2->val` to `total`
     - Move `l2` forward
   - Compute:
     - `carry = total / 10`
     - Digit = `total % 10`
   - Create a new node with the digit and attach to result.
   - Move `curr` forward.
4. Return `dummyHead->next`.

---

## Complexity Analysis
- **Time Complexity:** `O(max(m, n))`  
  Traverse both linked lists once.
- **Space Complexity:** `O(max(m, n))`  
  For storing the result linked list.

---

## Notes
- Dummy node simplifies edge case handling.
- Handles different length lists naturally.
- Carry is processed even after both lists end.
- Digits are stored in reverse order, so addition is straightforward.
- This is the standard approach for this problem.
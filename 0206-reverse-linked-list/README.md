# Reverse Linked List

## Problem Statement
Given the `head` of a singly linked list, reverse the list, and return the reversed list.

---

# Solution: Iterative Pointer Reversal

## Solution Overview
This solution reverses the linked list iteratively by changing the direction of the `next` pointers.

Key ideas:
- Use three pointers:
  - `prev` → previous node
  - `curr` → current node
  - `next` → next node
- Reverse links one node at a time.
- Move pointers forward until the list is fully reversed.

This approach reverses the list in-place.

---

## Algorithm
1. Initialize:
   - `prev = NULL`
   - `curr = head`
   - `next = NULL`
2. Traverse while `curr != NULL`:
   - Store next node:
     - `next = curr->next`
   - Reverse current node link:
     - `curr->next = prev`
   - Move `prev` forward:
     - `prev = curr`
   - Move `curr` forward:
     - `curr = next`
3. Return `prev` as the new head of the reversed list.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Each node is visited exactly once.
- **Space Complexity:** `O(1)`  
  Reversal is done in-place using constant extra space.

---

## Notes
- Iterative approach is efficient and space optimized.
- Pointer manipulation is the core concept.
- `prev` becomes the new head after reversal.
- Works for empty and single-node linked lists.
- This is the standard optimal solution for reversing a linked list.
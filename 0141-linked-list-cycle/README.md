# Linked List Cycle

## Problem Statement
Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer.

Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

---

# Solution: Slow and Fast Pointer (Floyd’s Cycle Detection)

## Solution Overview
This solution uses the **two-pointer technique** to detect a cycle efficiently.

Key ideas:
- Use two pointers:
  - `slow` moves one step at a time
  - `fast` moves two steps at a time
- If a cycle exists:
  - The fast pointer will eventually meet the slow pointer.
- If no cycle exists:
  - The fast pointer will reach `NULL`.

This technique is also known as **Floyd’s Cycle Detection Algorithm**.

---

## Algorithm
1. Initialize:
   - `slow = head`
   - `fast = head`
2. Traverse while:
   - `fast != NULL`
   - `fast->next != NULL`
3. Move pointers:
   - `slow = slow->next`
   - `fast = fast->next->next`
4. If `slow == fast`:
   - A cycle exists → return `true`
5. If loop ends:
   - No cycle exists → return `false`

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Each node is visited at most a constant number of times.
- **Space Complexity:** `O(1)`  
  No extra space is used.

---

## Notes
- Efficient cycle detection without modifying the linked list.
- Fast pointer moving twice as quickly guarantees meeting inside a cycle.
- Works for empty and single-node linked lists.
- Uses constant extra memory.
- This is the standard optimal solution for cycle detection in linked lists.
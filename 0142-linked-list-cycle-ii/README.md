# Linked List Cycle II

## Problem Statement
Given the `head` of a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

There is a cycle in a linked list if some node in the list can be reached again by continuously following the `next` pointer.

Do not modify the linked list.

---

# Solution: Floyd’s Cycle Detection Algorithm

## Solution Overview
This solution uses the **slow and fast pointer technique** to first detect whether a cycle exists, and then find the starting node of the cycle.

Key ideas:
- Use two pointers:
  - `slow` moves one step at a time
  - `fast` moves two steps at a time
- If they meet, a cycle exists.
- Reset `slow` to `head`.
- Move both pointers one step at a time.
- The node where they meet again is the starting point of the cycle.

This works due to the mathematical properties of cycle distances.

---

## Algorithm
1. Initialize:
   - `slow = head`
   - `fast = head`
   - `isCycle = false`
2. Traverse while:
   - `fast != NULL`
   - `fast->next != NULL`
3. Move pointers:
   - `slow = slow->next`
   - `fast = fast->next->next`
4. If `slow == fast`:
   - Cycle detected
   - Set `isCycle = true`
   - Break loop
5. If no cycle exists:
   - Return `NULL`
6. Reset:
   - `slow = head`
7. Move both pointers one step at a time:
   - `slow = slow->next`
   - `fast = fast->next`
8. When `slow == fast`, return that node.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Linked list is traversed at most a few times.
- **Space Complexity:** `O(1)`  
  No extra space is used.

---

## Notes
- Uses Floyd’s Tortoise and Hare Algorithm.
- Does not modify the linked list.
- The second meeting point gives the cycle starting node.
- Efficient and optimal solution.
- Commonly asked linked list interview problem.
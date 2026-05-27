# Middle of the Linked List

## Problem Statement
Given the `head` of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

---

# Solution 1: Brute Force (Count Nodes)

## Solution Overview
This approach first counts the total number of nodes in the linked list and then traverses again to reach the middle node.

Key ideas:
- Count the total number of nodes.
- Compute the middle position using:
  - `(n / 2) + 1`
- Traverse again to the middle node.
- Return the middle node.

---

## Algorithm
1. Initialize `n = 0`.
2. Traverse the linked list and count the number of nodes.
3. Compute:
   - `mid = (n / 2) + 1`
4. Reset traversal pointer to head.
5. Move forward until reaching the middle position.
6. Return the middle node.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Two traversals of the linked list.
- **Space Complexity:** `O(1)`  
  Only constant extra space is used.

---

## Notes
- Simple and easy to understand.
- Requires two passes through the linked list.
- Correctly returns the second middle node for even-length lists.
- Useful for understanding linked list traversal basics.

---

# Solution 2: Slow and Fast Pointer

## Solution Overview
This solution uses the **two-pointer technique** to find the middle node in a single traversal.

Key ideas:
- `slow` pointer moves one step at a time.
- `fast` pointer moves two steps at a time.
- When `fast` reaches the end, `slow` will be at the middle.

This is the standard optimal approach.

---

## Algorithm
1. Initialize:
   - `slow = head`
   - `fast = head`
2. Traverse while:
   - `fast != NULL`
   - `fast->next != NULL`
3. Move:
   - `slow = slow->next`
   - `fast = fast->next->next`
4. When loop ends, return `slow`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Single traversal of the linked list.
- **Space Complexity:** `O(1)`  
  No extra space is used.

---

## Notes
- Efficient one-pass solution.
- Fast pointer moves twice as fast as slow pointer.
- Automatically handles both odd and even length lists.
- Returns the second middle node in even-sized lists.
- This is the standard interview-preferred solution.
# Merge Two Sorted Lists

## Problem Statement
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted linked list**. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

---

# Solution: Recursive Merge

## Solution Overview
This solution uses **recursion** to merge two sorted linked lists.

Key ideas:
- Compare the current nodes of both lists.
- The smaller node becomes part of the merged list.
- Recursively merge the remaining nodes.
- If one list becomes empty, return the other list.

This naturally maintains the sorted order of the merged list.

---

## Algorithm
1. If either list is empty:
   - Return the other list.
2. Compare the values of the current nodes:
   - If `head1->val <= head2->val`:
     - Set `head1->next` to the result of merging:
       - `head1->next` and `head2`
     - Return `head1`
3. Otherwise:
   - Set `head2->next` to the result of merging:
     - `head1` and `head2->next`
   - Return `head2`
4. Continue recursively until both lists are merged.

---

## Complexity Analysis
- **Time Complexity:** `O(n + m)`  
  Each node from both linked lists is processed exactly once.
- **Space Complexity:** `O(n + m)`  
  Due to the recursive call stack.

---

## Notes
- Maintains sorted order throughout the merge process.
- Reuses existing nodes instead of creating new ones.
- Base case handles empty list scenarios.
- Recursive solution is concise and easy to understand.
- An iterative solution can achieve the same time complexity with `O(1)` auxiliary space.
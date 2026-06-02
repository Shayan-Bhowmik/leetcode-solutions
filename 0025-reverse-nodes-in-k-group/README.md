# Reverse Nodes in k-Group

## Problem Statement

Given the head of a linked list, reverse the nodes of the list `k` at a time, and return the modified list.

- `k` is a positive integer.
- If the number of nodes is not a multiple of `k`, then the remaining nodes at the end should remain as they are.
- You may not alter the values in the list's nodes, only nodes themselves may be changed.

---

# Solution: Recursion + In-Place Reversal

## Solution Overview

This solution uses **recursion** to process the linked list in groups of size `k`.

Key ideas:
- First check whether at least `k` nodes are available.
- If fewer than `k` nodes remain, return the current head unchanged.
- Recursively process the remaining list after the first `k` nodes.
- Reverse the current group of `k` nodes.
- Connect the reversed group with the already processed remainder.

This ensures that every complete group of size `k` is reversed.

---

## Algorithm

### Step 1: Verify Group Size

1. Initialize:
   - `temp = head`
   - `count = 0`
2. Move forward `k` nodes.
3. If fewer than `k` nodes exist:
   - Return `head`.

### Step 2: Process Remaining List

1. Recursively call:
   ```cpp
   prevNode = reverseKGroup(temp, k);
   ```
2. This reverses all subsequent groups and returns the head of the processed remainder.

### Step 3: Reverse Current Group

1. Reset:
   - `temp = head`
   - `count = 0`
2. Reverse exactly `k` nodes:
   - Store next node.
   - Reverse current pointer.
   - Move pointers forward.
3. Continue until `k` nodes are reversed.

### Step 4: Return Result

1. Return `prevNode`, which becomes the new head of the reversed group.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  
  Each node is visited and reversed exactly once.

- **Space Complexity:** `O(n / k)`
  
  Due to recursive call stack for each group.

---

## Notes

- Reverses nodes in groups of exactly `k`.
- Remaining nodes smaller than `k` are left unchanged.
- Node values are not modified.
- Uses recursion to process groups from the end toward the beginning.
- Performs reversal in-place using pointer manipulation.
- This is a standard recursive solution for the problem.
- An iterative solution can achieve the same time complexity with `O(1)` auxiliary space.
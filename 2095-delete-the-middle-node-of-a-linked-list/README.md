# Delete the Middle Node of a Linked List

## Problem Statement

You are given the `head` of a linked list.

Delete the middle node and return the head of the modified linked list.

The middle node of a linked list of size `n` is the:

```cpp
⌊n / 2⌋th
```

node using 0-based indexing.

For example:

- `n = 1` → middle index = `0`
- `n = 5` → middle index = `2`
- `n = 6` → middle index = `3`

---

# Solution: Slow and Fast Pointer

## Solution Overview

This solution uses the **slow and fast pointer technique** to locate the middle node in a single traversal.

Key ideas:
- `slow` moves one node at a time.
- `fast` moves two nodes at a time.
- When `fast` reaches the end:
  - `slow` points to the middle node.
- Maintain a `prev` pointer to the node before `slow`.
- Remove the middle node by updating links.

This avoids counting the total number of nodes.

---

## Algorithm

### Step 1: Handle Edge Cases

If the list contains:

```cpp
0 or 1 node
```

return:

```cpp
NULL
```

because deleting the middle node leaves an empty list.

---

### Step 2: Initialize Pointers

Create:

```cpp
slow = head
fast = head
prev = NULL
```

---

### Step 3: Find the Middle Node

Traverse while:

```cpp
fast != NULL &&
fast->next != NULL
```

Move pointers:

```cpp
prev = slow;
slow = slow->next;
fast = fast->next->next;
```

After the loop:

```cpp
slow
```

points to the middle node.

and

```cpp
prev
```

points to the node before it.

---

### Step 4: Delete the Middle Node

Skip the middle node:

```cpp
prev->next = slow->next;
```

Delete it:

```cpp
delete slow;
```

---

### Step 5: Return Result

Return:

```cpp
head
```

as the modified linked list.

---

## Complexity Analysis

Let:

```cpp
n = number of nodes
```

### Time Complexity

```cpp
O(n)
```

The linked list is traversed only once.

---

### Space Complexity

```cpp
O(1)
```

Only a few pointers are used.

---

## Notes

- Uses the classic slow and fast pointer technique.
- Finds the middle node without counting nodes.
- Deletes the middle node in a single traversal.
- Handles empty and single-node lists separately.
- `prev` is required to reconnect the list after deletion.
- This is the standard optimal solution for the problem.
- Uses constant extra space.
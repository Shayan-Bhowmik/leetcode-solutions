# Copy List with Random Pointer

## Problem Statement
A linked list of length `n` is given such that each node contains an additional **random pointer**, which could point to any node in the list, or `null`.

Construct a **deep copy** of the list.

The deep copy should consist of exactly `n` brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state.

Return the head of the copied linked list.

---

# What is a Deep Copy?

A **deep copy** creates an entirely new linked list with new nodes.

Key points:
- Every node in the copied list is newly allocated.
- No node in the copied list points to a node from the original list.
- The `next` and `random` relationships are preserved exactly.

### Example

Original List:

```text
A(7) ----> B(13) ----> C(11)
 |            |           |
 v            v           v
null          A           B
```

Deep Copy:

```text
a(7) ----> b(13) ----> c(11)
 |            |           |
 v            v           v
null          a           b
```

Notice:
- `a`, `b`, and `c` are completely new nodes.
- No pointer in the copied list points to `A`, `B`, or `C`.

---

# Solution: Hash Map Mapping

## Solution Overview

This solution uses a **hash map** to store the mapping between original nodes and their copied nodes.

Key ideas:
- Create a copy of every node and store:
  - Original Node → Copied Node
- Build the `next` pointers during the first traversal.
- Assign the `random` pointers during the second traversal.
- Use the hash map to quickly find the copied version of any original node.

---

## Algorithm

### First Pass: Copy Nodes and Next Pointers

1. If `head == NULL`, return `NULL`.
2. Create the first copied node.
3. Store mapping:
   - `original node → copied node`
4. Traverse the original list:
   - Create copies of all nodes.
   - Connect copied nodes using `next`.
   - Store mappings in the hash map.

### Second Pass: Copy Random Pointers

1. Traverse both lists simultaneously.
2. For every original node:
   - Set:
     ```cpp
     copiedNode->random = m[originalNode->random];
     ```
3. This correctly links copied nodes using copied random pointers.

### Return Result

1. Return the head of the copied list.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - First traversal copies nodes.
  - Second traversal copies random pointers.

- **Space Complexity:** `O(n)`
  - Hash map stores one entry per node.

---

## Notes

- Hash map stores the correspondence between original and copied nodes.
- Random pointers can point anywhere in the list or be `NULL`.
- Deep copy guarantees complete independence from the original list.
- No pointer in the copied list references an original node.
- This is the standard hash map solution for this problem.
- An optimized solution exists with `O(1)` extra space using node interleaving.
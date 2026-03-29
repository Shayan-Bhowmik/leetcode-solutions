# LRU Cache

## Problem Statement
Design a data structure that follows the constraints of a **Least Recently Used (LRU) cache**.

Implement the `LRUCache` class:
- `LRUCache(int capacity)` initializes the cache with a positive size `capacity`.
- `int get(int key)` returns the value of the key if it exists, otherwise returns `-1`.
- `void put(int key, int value)` updates the value of the key if it exists, or inserts the key-value pair if it does not.
- If the number of keys exceeds the capacity, evict the **least recently used** key.

Both operations must run in `O(1)` average time complexity.

---

# Solution: Doubly Linked List + Hash Map

## Solution Overview
This solution uses a combination of a **doubly linked list** and a **hash map** to achieve constant time operations.

Key ideas:
- Hash map stores key → node for `O(1)` access.
- Doubly linked list maintains usage order:
  - Most recently used → near head
  - Least recently used → near tail
- On access (`get` or `put`), move node to the front.
- On capacity overflow, remove node from the tail.

---

## Algorithm

### Initialization
1. Create dummy `head` and `tail` nodes.
2. Connect `head -> tail`.
3. Store capacity in `limit`.
4. Use a hash map `m` for key → node mapping.

---

### Helper Functions

**addNode(newNode):**
- Insert node right after `head`.

**delNode(oldNode):**
- Remove node from its current position.

---

### get(key)
1. If key not in map → return `-1`.
2. Retrieve the node.
3. Remove it from its current position.
4. Insert it right after `head` (mark as recently used).
5. Return its value.

---

### put(key, value)
1. If key exists:
   - Remove old node.
   - Delete from map.
2. If cache is at capacity:
   - Remove least recently used node (`tail->prev`).
   - Delete it from map.
3. Create new node.
4. Insert it after `head`.
5. Add to map.

---

## Complexity Analysis
- **Time Complexity:** `O(1)`  
  All operations (`get`, `put`, insert, delete) are constant time.
- **Space Complexity:** `O(capacity)`  
  For storing nodes and hash map entries.

---

## Notes
- Doubly linked list allows `O(1)` insertion and deletion.
- Hash map provides `O(1)` access to nodes.
- Dummy head and tail simplify edge cases.
- Most recently used nodes are kept near the head.
- Least recently used node is always `tail->prev`.
- This is the standard optimal design for LRU Cache.
# Create Binary Tree From Descriptions

## Problem Statement

You are given a 2D integer array `descriptions` where:

```cpp
descriptions[i] = [parenti, childi, isLefti]
```

indicates that:

- `parenti` is the value of a parent node.
- `childi` is the value of a child node.
- `isLefti` indicates whether the child is a left child:
  - `1` → left child
  - `0` → right child

Construct the binary tree described by `descriptions` and return its root.

It is guaranteed that the given descriptions form a valid binary tree.

---

# Solution: Hash Map + Root Detection + BFS Construction

## Solution Overview

This solution builds the tree in three phases:

1. Store parent-child relationships using a hash map.
2. Identify the root node.
3. Construct the binary tree using Breadth-First Search (BFS).

Key ideas:
- Every child node is stored in a set.
- The root is the only node that never appears as a child.
- A hash map stores:
  - left child
  - right child
- BFS is used to create and connect all nodes.

---

## Algorithm

### Step 1: Store Relationships

Create:

```cpp
unordered_map<int, pair<int,int>> mp;
```

where:

```cpp
mp[parent] = {leftChild, rightChild}
```

Also create:

```cpp
unordered_set<int> st;
```

to store all child nodes.

For every description:

```cpp
[parent, child, isLeft]
```

- Insert `child` into the set.
- Store the child in the appropriate position:
  - left child if `isLeft == 1`
  - right child otherwise

---

### Step 2: Find the Root

Traverse all descriptions.

The root is the node that:

```cpp
never appears as a child
```

i.e.

```cpp
st.find(parent) == st.end()
```

Store that node as the root value.

---

### Step 3: Create Root Node

Construct:

```cpp
TreeNode* root = new TreeNode(rootValue);
```

Initialize a queue:

```cpp
queue<TreeNode*> q;
```

Push the root into the queue.

---

### Step 4: Build the Tree Using BFS

While the queue is not empty:

1. Extract the current node.
2. Check its stored children in the map.

#### Left Child

If a left child exists:

```cpp
TreeNode* left = new TreeNode(leftValue);
```

Attach:

```cpp
current->left = left;
```

Push into queue.

#### Right Child

If a right child exists:

```cpp
TreeNode* right = new TreeNode(rightValue);
```

Attach:

```cpp
current->right = right;
```

Push into queue.

---

### Step 5: Return Root

Return the constructed root node.

---

## Complexity Analysis

Let:

```cpp
n = descriptions.size()
```

### Time Complexity

- Building relationships: `O(n)`
- Root detection: `O(n)`
- Tree construction: `O(n)`

Overall:

```cpp
O(n)
```

---

### Space Complexity

- Hash map: `O(n)`
- Child set: `O(n)`
- Queue: `O(n)`

Overall:

```cpp
O(n)
```

---

## Notes

- Uses a hash map to store parent-child relationships.
- Uses a set to identify the root node efficiently.
- Root is the only node that never appears as a child.
- BFS is used to construct the tree level by level.
- Each tree node is created exactly once.
- The solution assumes the descriptions form a valid binary tree.
- This is an efficient linear-time solution for the problem.
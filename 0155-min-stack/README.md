# Min Stack

## Problem Statement

Design a stack that supports:

- `push(int val)` — Push the element onto the stack.
- `pop()` — Remove the element on the top of the stack.
- `top()` — Get the top element.
- `getMin()` — Retrieve the minimum element in the stack.

All operations must run in **O(1)** time complexity.

Implement the `MinStack` class.

---

# Solution: Single Stack with Encoded Values

## Solution Overview

This solution stores the minimum element without using an additional stack.

Key ideas:
- Maintain a variable:
  ```cpp
  minVal
  ```
  representing the current minimum.
- When a new minimum is inserted:
  - Store a specially encoded value in the stack.
  - Update `minVal`.
- During `pop()`, decode the previous minimum when necessary.
- This allows retrieving the minimum element in constant time using only one stack.

---

## Encoding Technique

When:

```cpp
val < minVal
```

instead of storing `val`, store:

```cpp
2 * val - minVal
```

and update:

```cpp
minVal = val
```

This encoded value is always smaller than the current minimum and acts as a marker.

---

## Decoding Technique

When popping:

```cpp
s.top() < minVal
```

the top element is encoded.

The previous minimum is recovered using:

```cpp
minVal = 2 * minVal - s.top()
```

---

## Algorithm

### push(val)

#### Empty Stack

1. Push:
   ```cpp
   val
   ```
2. Set:
   ```cpp
   minVal = val
   ```

#### New Minimum

If:

```cpp
val < minVal
```

1. Push:
   ```cpp
   2 * val - minVal
   ```
2. Update:
   ```cpp
   minVal = val
   ```

#### Normal Case

Push:

```cpp
val
```

directly.

---

### pop()

1. Check the top element.

#### Encoded Value

If:

```cpp
s.top() < minVal
```

recover previous minimum:

```cpp
minVal = 2 * minVal - s.top();
```

2. Remove the element.

---

### top()

#### Encoded Value

If:

```cpp
s.top() < minVal
```

the actual top element is:

```cpp
minVal
```

#### Normal Value

Return:

```cpp
s.top()
```

---

### getMin()

Return:

```cpp
minVal
```

---

## Complexity Analysis

### Time Complexity

| Operation | Complexity |
|------------|------------|
| push() | O(1) |
| pop() | O(1) |
| top() | O(1) |
| getMin() | O(1) |

---

### Space Complexity

```cpp
O(n)
```

Only one stack is maintained.

---

## Notes

- Uses a single stack instead of two stacks.
- Encoded values store information about previous minimums.
- `minVal` always tracks the current minimum element.
- `long long` is used to prevent integer overflow during encoding and decoding.
- Achieves constant-time minimum retrieval.
- This is the standard space-optimized solution for Min Stack.
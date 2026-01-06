# Reverse String

## Problem Statement
Given an array of characters `s`, reverse the array **in-place**.

You must do this by modifying the input array directly with **O(1)** extra memory.

---

## Solution Overview
This README presents **two approaches** to solve the problem:

- **Approach 1:** Two-pointer technique (manual in-place swap)
- **Approach 2:** Using the C++ Standard Library `reverse()` function

Both approaches reverse the string in-place and satisfy the problem constraints.

---

## Approach 1: Two-Pointer Technique

### Explanation
This approach uses two pointers:
- One starting from the **beginning** of the array
- One starting from the **end** of the array

The characters at these positions are swapped, and the pointers move toward each other until they meet.  
This effectively reverses the array in-place without using extra memory.

---

### Algorithm
1. Initialize `start = 0` and `end = s.size() - 1`.
2. While `start < end`:
   - Swap `s[start]` and `s[end]`.
   - Increment `start`.
   - Decrement `end`.
3. The array is reversed once the loop ends.

---

### Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Approach 2: Using STL `reverse()`

### Explanation
This approach leverages the built-in `reverse()` function from the C++ Standard Library.

The function internally reverses the range defined by the iterators, modifying the array in-place.  
This results in cleaner and more concise code.

---

### Algorithm
1. Call `reverse(s.begin(), s.end())`.

---

### Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Notes
- Both approaches reverse the string **in-place**, as required.
- The two-pointer approach demonstrates core algorithmic thinking.
- The STL-based approach is concise and preferred in production when readability is a priority.
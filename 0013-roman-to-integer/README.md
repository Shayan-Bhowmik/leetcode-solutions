# Roman to Integer

## Problem Statement
Roman numerals are represented by seven different symbols:  
`I`, `V`, `X`, `L`, `C`, `D`, and `M`.

| Symbol | Value |
|--------|------|
| I      | 1    |
| V      | 5    |
| X      | 10   |
| L      | 50   |
| C      | 100  |
| D      | 500  |
| M      | 1000 |

Given a Roman numeral string `s`, convert it to an integer.

Roman numerals are usually written largest to smallest from left to right. However, in some cases:
- `I` before `V` or `X` represents 4 and 9
- `X` before `L` or `C` represents 40 and 90
- `C` before `D` or `M` represents 400 and 900

---

# Solution: Reverse Traversal + Value Comparison

## Solution Overview
This solution processes the string from **right to left** and uses comparison logic to handle subtraction cases.

Key ideas:
- Traverse from the end of the string.
- Maintain:
  - `x` → final result
  - `y` → previous (right-side) value
- If the current value is smaller than the previous value → subtract it.
- Otherwise → add it.
- Use arrays to map Roman symbols to integer values.

---

## Algorithm
1. Store Roman symbols and their corresponding values:
   - `sym = {'I','V','X','L','C','D','M'}`
   - `val = {1,5,10,50,100,500,1000}`
2. Initialize:
   - `x = 0` (result)
   - `y = 0` (previous value)
3. Traverse the string from right to left:
   - For each character, find its value.
   - If current value < `y`:
     - Subtract it from result.
   - Else:
     - Add it to result.
   - Update `y` to current value.
4. Return `x`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  Traverse the string once (inner loop is constant size = 7).
- **Space Complexity:** `O(1)`  
  Fixed-size arrays for mapping.

---

## Notes
- Reverse traversal simplifies handling subtraction cases.
- Comparison with previous value determines add/subtract.
- Mapping via arrays is simple but can be optimized using a hash map.
- Works for all valid Roman numerals.
- This is a standard approach for this problem.
# Angle Between Hands of a Clock

## Problem Statement

Given two numbers:

- `hour` representing the hour hand position.
- `minutes` representing the minute hand position.

Return the smaller angle (in degrees) formed between the hour hand and the minute hand.

Answers within `10^-5` of the actual value are accepted.

---

# Solution: Clock Angle Calculation

## Solution Overview

This solution computes the positions of both clock hands and then finds the smaller angle between them.

Key ideas:
- The minute hand moves:
  ```cpp
  360° / 60 = 6°
  ```
  per minute.
- The hour hand moves:
  ```cpp
  360° / 12 = 30°
  ```
  per hour.
- The hour hand also moves continuously as minutes pass:
  ```cpp
  0.5°
  ```
  per minute.
- Compute both hand angles.
- Calculate the absolute difference.
- Return the smaller of:
  - Direct angle
  - Reflex angle

---

## Algorithm

### Step 1: Compute Hour Hand Angle

The hour hand position is:

```cpp
hourAngle = (30 * hour) + (0.5 * minutes);
```

because:

```cpp
30° per hour
```

and

```cpp
0.5° per minute
```

---

### Step 2: Compute Minute Hand Angle

The minute hand position is:

```cpp
minuteAngle = 6 * minutes;
```

because:

```cpp
360 / 60 = 6°
```

per minute.

---

### Step 3: Compute Angle Difference

Calculate:

```cpp
abs(hourAngle - minuteAngle)
```

---

### Step 4: Return Smaller Angle

Two angles are possible between the hands:

#### Direct Angle

```cpp
abs(hourAngle - minuteAngle)
```

#### Reflex Angle

```cpp
360 - abs(hourAngle - minuteAngle)
```

Return:

```cpp
min(
    abs(hourAngle - minuteAngle),
    360 - abs(hourAngle - minuteAngle)
)
```

---

## Complexity Analysis

### Time Complexity

```cpp
O(1)
```

Only a few arithmetic operations are performed.

---

### Space Complexity

```cpp
O(1)
```

No extra space is used.

---

## Notes

- The hour hand moves continuously, not discretely.
- The term:
  ```cpp
  0.5 * minutes
  ```
  accounts for the hour hand's movement between hour marks.
- `abs()` computes the direct angle difference.
- `min()` ensures the smaller angle is returned.
- Works for all valid clock times.
- This is the standard mathematical solution for the problem.
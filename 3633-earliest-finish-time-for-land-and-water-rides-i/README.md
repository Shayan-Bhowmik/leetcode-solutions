# Earliest Finish Time for Land and Water Rides

## Problem Statement

You are given four integer arrays:

- `landStartTime`
- `landDuration`
- `waterStartTime`
- `waterDuration`

A visitor must complete exactly one land ride and one water ride.

The rides can be taken in either order:
- Land ride → Water ride
- Water ride → Land ride

A ride can only start at or after its start time. If the visitor finishes the first ride before the second ride becomes available, they must wait.

Return the earliest possible time at which both rides can be completed.

---

# Solution: Brute Force Enumeration

## Solution Overview

This solution checks every possible combination of one land ride and one water ride.

Key ideas:
- Try every land ride with every water ride.
- Consider both possible orders:
  - Land first, then water
  - Water first, then land
- Compute the finishing time for each order.
- Keep track of the minimum finishing time found.

This guarantees that the optimal answer is considered.

---

## Algorithm

1. Let:
   - `n = landStartTime.size()`
   - `m = waterStartTime.size()`
2. Initialize:
   ```cpp
   ans = INT_MAX
   ```
3. For each land ride `i`:
   - Compute:
     ```cpp
     landEnd = landStartTime[i] + landDuration[i]
     ```
4. For each water ride `j`:
   - Compute:
     ```cpp
     waterEnd = waterStartTime[j] + waterDuration[j]
     ```

### Case 1: Land Ride → Water Ride

1. Finish land ride:
   ```cpp
   landEnd
   ```
2. Start water ride at:
   ```cpp
   max(landEnd, waterStartTime[j])
   ```
3. Compute:
   ```cpp
   finish1 = max(landEnd, waterStartTime[j]) + waterDuration[j]
   ```

### Case 2: Water Ride → Land Ride

1. Finish water ride:
   ```cpp
   waterEnd
   ```
2. Start land ride at:
   ```cpp
   max(waterEnd, landStartTime[i])
   ```
3. Compute:
   ```cpp
   finish2 = max(waterEnd, landStartTime[i]) + landDuration[i]
   ```

### Update Answer

1. Take:
   ```cpp
   min(finish1, finish2)
   ```
2. Update:
   ```cpp
   ans = min(ans, min(finish1, finish2))
   ```

5. Return `ans`.

---

## Complexity Analysis

- **Time Complexity:** `O(n × m)`
  
  Every land ride is paired with every water ride.

- **Space Complexity:** `O(1)`
  
  Only a few variables are used.

---

## Notes

- Considers both possible ride orders.
- Uses `max()` to handle waiting for ride availability.
- Guarantees the earliest valid completion time.
- Straightforward brute force solution.
- Suitable when the number of rides is relatively small.
- Can be optimized further for larger constraints.
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

# Solution: Earliest Ride Completion Optimization

## Solution Overview

This solution avoids checking every possible pair of land and water rides.

Key ideas:
- Find the earliest possible completion time among all land rides.
- Find the earliest possible completion time among all water rides.
- Consider both possible ride orders:
  - Land ride first, then water ride.
  - Water ride first, then land ride.
- Compute the earliest finishing time achievable for each order.
- Return the minimum of the two results.

This reduces the need for comparing every land ride with every water ride.

---

## Algorithm

### Step 1: Find Earliest Land Completion

1. Initialize:
   ```cpp
   ear_land_time = INT_MAX
   ```
2. Traverse all land rides:
   ```cpp
   ear_land_time = min(
       ear_land_time,
       landStartTime[i] + landDuration[i]
   );
   ```

This gives the earliest possible time any land ride can finish.

---

### Step 2: Find Earliest Water Completion

1. Initialize:
   ```cpp
   ear_water_time = INT_MAX
   ```
2. Traverse all water rides:
   ```cpp
   ear_water_time = min(
       ear_water_time,
       waterStartTime[j] + waterDuration[j]
   );
   ```

This gives the earliest possible time any water ride can finish.

---

### Step 3: Land Ride → Water Ride

1. For every water ride:
   - Start after:
     - finishing the earliest land ride, and
     - the water ride's start time.
2. Compute:
   ```cpp
   max(waterStartTime[j], ear_land_time)
   + waterDuration[j]
   ```
3. Store the minimum value as:
   ```cpp
   land_wait_water
   ```

---

### Step 4: Water Ride → Land Ride

1. For every land ride:
   - Start after:
     - finishing the earliest water ride, and
     - the land ride's start time.
2. Compute:
   ```cpp
   max(landStartTime[k], ear_water_time)
   + landDuration[k]
   ```
3. Store the minimum value as:
   ```cpp
   water_wait_land
   ```

---

### Step 5: Return Answer

Return:

```cpp
min(land_wait_water, water_wait_land)
```

---

## Complexity Analysis

- **Time Complexity:** `O(n + m)`
  
  Each land ride and water ride is processed once.

- **Space Complexity:** `O(1)`
  
  Only constant extra variables are used.

---

## Notes

- Avoids the `O(n × m)` brute-force comparison.
- Computes earliest land and water completion times independently.
- Considers both ride orders.
- Uses `max()` to account for waiting until a ride becomes available.
- Achieves linear time complexity.
- Significantly faster than enumerating all ride pairs.
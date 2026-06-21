# Maximum Ice Cream Bars

## Problem Statement

It is a hot summer day, and a boy wants to buy some ice cream bars.

You are given an array:

```cpp
costs
```

where:

```cpp
costs[i]
```

is the price of the `i-th` ice cream bar, and an integer:

```cpp
coins
```

representing the number of coins available.

Return the maximum number of ice cream bars the boy can buy with the available coins.

---

# Solution: Counting Sort + Greedy Purchase

## Solution Overview

This solution uses a **counting sort approach** instead of sorting the entire array.

Key ideas:
- Count the frequency of every ice cream cost.
- Buy the cheapest ice cream bars first.
- Spend coins greedily from the lowest cost to the highest cost.
- If there are not enough coins to buy all bars of a certain cost, buy as many as possible and stop.

This maximizes the number of ice cream bars purchased.

---

## Algorithm

### Step 1: Find Maximum Cost

Determine:

```cpp
m = max(costs)
```

This defines the size of the frequency array.

---

### Step 2: Build Frequency Array

Create:

```cpp
vector<long long> count(m + 1, 0);
```

For every ice cream bar:

```cpp
count[costs[i]]++;
```

Now:

```cpp
count[x]
```

stores the number of bars costing:

```cpp
x
```

---

### Step 3: Buy Cheapest Bars First

Initialize:

```cpp
curr_coins = coins
```

and:

```cpp
total = 0
```

Traverse all possible costs:

```cpp
j = 0 ... m
```

---

### Step 4: Purchase All Bars of Current Cost

Compute:

```cpp
curr_cost = count[j] * j
```

If enough coins exist:

```cpp
curr_coins >= curr_cost
```

buy all bars:

```cpp
curr_coins -= curr_cost;
total += count[j];
```

---

### Step 5: Buy Partial Quantity

If insufficient coins remain:

```cpp
curr_coins < curr_cost
```

buy as many bars as possible:

```cpp
total += curr_coins / j;
```

Then return:

```cpp
total
```

because no more expensive bars can be purchased.

---

### Step 6: Return Result

After processing all costs:

```cpp
return total;
```

---

## Complexity Analysis

Let:

```cpp
n = costs.size()
```

and

```cpp
m = max(costs)
```

### Time Complexity

Building frequency array:

```cpp
O(n)
```

Traversing all possible costs:

```cpp
O(m)
```

Overall:

```cpp
O(n + m)
```

---

### Space Complexity

```cpp
O(m)
```

For the frequency array.

---

## Notes

- Uses counting sort instead of comparison sorting.
- Purchases ice cream bars greedily from the cheapest price.
- Maximizes the total number of bars that can be bought.
- Avoids the `O(n log n)` sorting approach.
- Particularly efficient when the maximum cost value is not too large.
- This is a standard counting-sort-based solution for the problem.
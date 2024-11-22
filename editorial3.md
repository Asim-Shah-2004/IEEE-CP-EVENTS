# Minimum Cost Cake Cutting: Editorial Solution
## Problem Statement
Justin needs to cut a rectangular cake into 1×1 squares with minimum cost, where horizontal and vertical cuts have different costs, and each cut extends fully across the cake.

## Intuition
This is a greedy problem where:
1. Each cut multiplies previous cuts
2. Higher cost cuts should be made earlier
3. The number of pieces a cut creates affects total cost

## Key Insights
1. **Multiplication Effect**:
   - Each horizontal cut crosses all vertical sections
   - Each vertical cut crosses all horizontal sections
   - Later cuts cost more in total due to multiplication

2. **Greedy Choice Property**:
   - Always make the highest cost cut first
   - This minimizes the multiplication effect on expensive cuts
   - Can prove optimality through exchange argument

## Greedy Solution
### Algorithm
1. Sort both cut arrays in descending order
2. Keep track of current pieces count:
   - hp (horizontal pieces)
   - vp (vertical pieces)
3. Always choose higher cost between available cuts
4. Multiply current cut cost by opposite direction piece count

### Proof of Correctness
Let's prove why greedy approach works:

1. **Exchange Argument**:
   Suppose optimal solution doesn't make highest cost cut first.
   - Let C1 be highest cost cut
   - Let C2 be cut made before C1
   - Total = (C2 × 1) + (C1 × 2)
   - If we swap: (C1 × 1) + (C2 × 2)
   - Difference = C1 - C2 > 0
   Therefore, making highest cost cut first always better.

## Implementation Analysis
```cpp
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, 
                         vector<int>& verticalCut) {
        // Sort cuts in descending order
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        
        // Track pieces count
        int hp = 1;  // horizontal pieces
        int vp = 1;  // vertical pieces
        long long cost = 0;
        
        int i = 0, j = 0;  // pointers for both arrays
        
        // Process cuts in decreasing order of cost
        while (i < horizontalCut.size() && j < verticalCut.size()) {
            if (horizontalCut[i] > verticalCut[j]) {
                // Make horizontal cut
                cost += (long long)horizontalCut[i] * vp;
                i++;
                hp++;
            } else {
                // Make vertical cut
                cost += (long long)verticalCut[j] * hp;
                j++;
                vp++;
            }
        }
        
        // Process remaining horizontal cuts
        while (i < horizontalCut.size()) {
            cost += (long long)horizontalCut[i] * vp;
            i++;
            hp++;
        }
        
        // Process remaining vertical cuts
        while (j < verticalCut.size()) {
            cost += (long long)verticalCut[j] * hp;
            j++;
            vp++;
        }
        
        return cost;
    }
};
```

### Code Breakdown
1. **Sorting**:
   - Use reverse iterators for descending sort
   - Ensures highest costs processed first

2. **Piece Tracking**:
   - hp: count of horizontal pieces
   - vp: count of vertical pieces
   - Updated after each cut

3. **Cost Calculation**:
   - Use long long for large numbers
   - Multiply cut cost by opposite direction pieces

## Complexity Analysis
- **Time Complexity**: O(m log m + n log n)
  * Sorting both arrays dominates
  * While loop is O(m + n)

- **Space Complexity**: O(1)
  * Only constant extra space needed
  * Input arrays not counted

## Example Walkthrough
Input: m=3, n=2, horizontalCut=[1,3], verticalCut=[5]

1. After sorting:
   - horizontalCut = [3,1]
   - verticalCut = [5]

2. Steps:
   ```
   1. vertical(5): cost = 5×1 = 5, hp=1, vp=2
   2. horizontal(3): cost += 3×2 = 6, hp=2, vp=2
   3. horizontal(1): cost += 1×2 = 2, hp=3, vp=2
   Total: 13
   ```

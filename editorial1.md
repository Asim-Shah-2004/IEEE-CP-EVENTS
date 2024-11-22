# Maximum Water Container: Editorial Solution
## Problem Statement
Jake, an architecture student, conceptualizes a unique fish tank design problem that translates into finding the maximum area of water that can be contained between two vertical lines (blocks).

## Intuition
The problem can be visualized as finding the largest rectangular area between any two blocks, where:
- The width is the distance between the blocks
- The height is limited by the shorter of the two blocks
- Area = width × minimum height of the two blocks

## Key Observations
1. **Area Calculation**: 
   - For any two blocks at positions i and j:
   - Area = (j - i) × min(height[i], height[j])
   - We need to maximize this value

2. **Brute Force Approach**: 
   - Try all possible pairs of blocks: O(n²)
   - Not efficient for large inputs (n ≤ 10⁵)

3. **Optimal Solution Pattern**:
   - Start with maximum width (endpoints)
   - Strategically move inward to find larger areas
   - Key insight: Always move the pointer with smaller height

## Two-Pointer Solution
### Algorithm
1. Initialize two pointers:
   - Left pointer (l) at the start of array
   - Right pointer (r) at the end of array
2. Calculate current area
3. Move the pointer pointing to smaller height inward
4. Repeat until pointers meet

### Why does this work?
1. **Proof of Correctness**:
   - Initially, we consider maximum width
   - Moving inward from shorter block:
     * If we find taller block: Potential for larger area
     * If we find shorter block: Area will decrease
   - Moving inward from taller block:
     * Can't increase area as it's limited by shorter block

2. **Optimality**:
   - We never skip a potentially maximum area
   - For each width, we consider the best possible height

## Implementation Analysis
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;              // Left pointer
        int r = n - 1;          // Right pointer
        int res = 0;            // Store maximum area
        
        while (l < r) {
            // Calculate current area
            res = max(res, min(height[l], height[r]) * (r - l));
            
            // Move pointer with smaller height
            if (height[l] < height[r]) {
                l++;
            } else if (height[l] > height[r]) {
                r--;
            } else {
                // If heights are equal, move either pointer
                l++;
                r--;
            }
        }
        return res;
    }
};
```

### Code Breakdown
1. **Variable Initialization**:
   - `l = 0`: Left pointer at start
   - `r = n-1`: Right pointer at end
   - `res = 0`: Tracks maximum area

2. **Main Loop**:
   - Continues until pointers meet
   - Updates maximum area if current area is larger
   - Moves appropriate pointer based on height comparison

3. **Optimization**:
   - When heights are equal, we can move either pointer
   - Moving both simultaneously reduces iterations

## Complexity Analysis
- **Time Complexity**: O(n)
  * Single pass through array
  * Each element visited at most once

- **Space Complexity**: O(1)
  * Only uses constant extra space
  * No additional data structures needed

## Example Walkthrough
Using sample input: [1, 8, 6, 2, 5, 4, 8, 3, 7]

1. Initial state:
   - l = 0 (height = 1), r = 8 (height = 7)
   - Area = min(1, 7) × 8 = 8

2. Move left pointer (smaller height):
   - l = 1 (height = 8), r = 8 (height = 7)
   - Area = min(8, 7) × 7 = 49

3. Final result: 49

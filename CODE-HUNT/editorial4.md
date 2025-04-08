# Converting Array to Ones using GCD: Editorial Solution

## Problem Statement
Given an array of integers, perform operations where you can replace one of two adjacent elements with their GCD. Find the minimum operations needed to convert all elements to 1.

## Intuition
Key insights:
1. If we have any 1 in the array, we can use it to convert adjacent elements to 1
2. If no 1 exists, we need to find the shortest sequence of elements whose GCD is 1
3. After getting first 1, we can sequentially convert remaining elements

## Solution Approach
### Part 1: Existing Ones
- If array contains any 1s:
  * Each remaining element needs one operation with an adjacent 1
  * Total operations = n - (count of 1s)

### Part 2: Creating First One
If no 1s exist:
1. Find shortest segment where GCD = 1
2. This segment can create a 1 in minimum operations
3. Use this 1 to convert remaining elements

## Algorithm
1. Count existing ones
   ```cpp
   int onesCount = count(arr.begin(), arr.end(), 1);
   if (onesCount > 0) return n - onesCount;
   ```

2. If no ones exist:
   - Try all possible segments
   - Calculate progressive GCD
   - Track minimum segment length that gives GCD = 1
   ```cpp
   for (int i = 0; i < n; i++) {
       long long currentGcd = arr[i];
       for (int j = i + 1; j < n; j++) {
           currentGcd = gcd(currentGcd, arr[j]);
           if (currentGcd == 1) {
               minSegmentLength = min(minSegmentLength, j - i);
               break;
           }
       }
   }
   ```

3. Calculate total operations:
   - Segment operations = length of minimum segment
   - Remaining operations = array length - 1
   ```cpp
   return minSegmentLength + n - 1;
   ```

## Example Walkthrough
Consider array: [2, 2, 3, 4, 6]

1. No 1s present initially
2. Find segments with GCD = 1:
   - [2,3]: GCD = 1 (length = 2)
   - [2,2,3]: GCD = 1 (length = 3)
   - etc.
3. Minimum segment = [2,3] (length = 2)
4. Operations:
   - Convert [2,3] to 1: 1 operation
   - Use this 1 to convert remaining elements: 4 operations
   - Total = 5 operations


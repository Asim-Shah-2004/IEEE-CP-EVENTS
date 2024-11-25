# Maximum Travel Content Score: Bottom-Up Approach  
## Problem Statement  
Tasha needs to maximize her score in Contentesia by balancing local content points earned by staying in a city and journey points earned by traveling between cities, over a fixed number of days.  

## Intuition  
This problem involves dynamic programming with a bottom-up approach to find the maximum score:  
1. On each day, Tasha can either:  
   - Stay in the current city  
   - Travel to another city  
2. The bottom-up DP table computes scores for all states iteratively.  
3. The result is the highest score achievable after all days.  

## Key Insights  
1. **DP Table Representation**:  
   - `dp[day][city]`: Maximum score achievable on a given day in a specific city.  

2. **Transition**:  
   - Stay: Add local score for staying in the same city.  
   - Travel: Add journey score and local score for the destination city.  

3. **Initialization and Iteration**:  
   - Start with zero scores.  
   - Iteratively update the DP table for each day and city based on possible decisions.  

## Bottom-Up Dynamic Programming Solution  
### Algorithm  
1. Initialize `dp` array with zeros.  
2. Iterate over each day:  
   - Update scores for staying in the same city.  
   - Update scores for traveling to another city.  
3. Track the maximum score across all cities after the last day.  

### Implementation  
```cpp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int n, k; 
    cin >> n >> k;
    
    // Input for stayScore
    vector<vector<int>> stay(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> stay[i][j];
        }
    }
    
    // Input for travelScore
    vector<vector<int>> travel(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> travel[i][j];
        }
    }
    
    // DP table
    long long dp[205][205] = {0};
    long long maxScore = 0;
    
    // Bottom-up calculation
    for (int day = 0; day < k; day++) {
        for (int city = 0; city < n; city++) {
            // Stay in the current city
            dp[day + 1][city] = max(dp[day + 1][city], dp[day][city] + stay[day][city]);
            maxScore = max(maxScore, dp[day + 1][city]);
            
            // Travel to another city
            for (int nextCity = 0; nextCity < n; nextCity++) {
                dp[day + 1][nextCity] = max(dp[day + 1][nextCity], dp[day][city] + travel[city][nextCity]);
                maxScore = max(maxScore, dp[day + 1][nextCity]);
            }
        }
    }
    
    // Output the maximum score
    cout << maxScore << endl;
}

int main() {
    solve();
}
```  

## Code Breakdown  
1. **Inputs**:  
   - `stay` stores local content points for each city and day.  
   - `travel` stores journey points between cities.  

2. **DP Table**:  
   - `dp[day][city]`: Tracks the maximum score on a specific day and city.  
   - Updates are based on staying or traveling.  

3. **Result**:  
   - After all days, `maxScore` holds the highest score.  

## Complexity Analysis  
- **Time Complexity**: O(k × n²)  
  * `k`: Days  
  * `n`: Cities  
  * Each day involves checking all city pairs.  

- **Space Complexity**: O(k × n)  
  * DP table size  

## Example Walkthrough  
### Input:  
```
n = 2, k = 1  
stayScore = [[2, 3]]  
travelScore = [[0, 2], [1, 0]]  
```  

### Execution:  
1. Day 0:  
   - City 0: Stay = 2, Travel = 2  
   - City 1: Stay = 3, Travel = 1  

2. Day 1:  
   - Max score = 3 (Start in City 1 and stay).  

### Output:  
```
3
```  

## Summary  
The bottom-up approach ensures efficient calculation of maximum scores with reusable subproblem solutions. It iteratively computes the best possible outcomes for each day and city, ultimately yielding the optimal result.

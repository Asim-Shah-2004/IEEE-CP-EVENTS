# Maximum Travel Content Score: Editorial Solution
## Problem Statement
Tasha needs to maximize her score in Contentesia by optimally choosing between staying in cities for local content points and traveling between cities for journey points over a fixed number of days.

## Intuition
This is a dynamic programming problem where at each day and city:
1. We can either stay in the current city
2. Or travel to any other city
3. The optimal solution requires considering all possible sequences of decisions

## Key Observations
1. **State Variables**:
   - Current day (k)
   - Current city (currCity)
   - These fully determine possible future decisions

2. **Decision Space**:
   - Stay: Earn local points + future points from same city
   - Travel: Earn travel points + future points from new city
   - Need to try all possibilities for travel

3. **Optimal Substructure**:
   - Maximum score from current state = max(stay_score, max_travel_score)
   - Solutions to subproblems can be reused

## Dynamic Programming Solution
### Algorithm
1. Create DP state: dp[day][current_city]
2. For each state:
   - Try staying (one option)
   - Try traveling to each other city
   - Take maximum of all choices
3. Try starting from each city

### Recurrence Relation
```
dp[k][curr] = max(
    stayScore[k][curr] + dp[k+1][curr],
    max(travelScore[curr][i] + dp[k+1][i]) for all cities i
)
```

## Implementation Analysis
```cpp
class Solution {
public:
    int maxDays;
    int dp[201][201];  // DP memoization array
    
    int solve(int k, int n, vector<vector<int>>& stayScore, 
             vector<vector<int>>& travelScore, int currCity) {
        // Base case: reached end of days
        if(k == maxDays) return 0;
        
        // Return memoized result if available
        if(dp[k][currCity] != -1) return dp[k][currCity];
        
        // Option 1: Stay in current city
        int scoreStay = stayScore[k][currCity] + 
                       solve(k+1, n, stayScore, travelScore, currCity);
        
        // Option 2: Travel to another city
        int scoreTravel = 0;
        for(int i = 0; i < n; i++) {
            int temp = travelScore[currCity][i] + 
                      solve(k+1, n, stayScore, travelScore, i);
            scoreTravel = max(temp, scoreTravel);    
        }
        
        // Store and return maximum of both options
        return dp[k][currCity] = max(scoreStay, scoreTravel);
    }
    
    int maxScore(int n, int k, vector<vector<int>>& stayScore, 
                vector<vector<int>>& travelScore) {
        maxDays = k;
        int maxi = 0;
        memset(dp, -1, sizeof(dp));
        
        // Try starting from each city
        for(int i = 0; i < n; i++) {
            int curr = solve(0, n, stayScore, travelScore, i);
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};
```

### Code Breakdown
1. **DP Array**:
   - `dp[201][201]`: Stores maximum score for each day and city
   - Initialized to -1 for memoization

2. **solve() Function**:
   - Parameters:
     * k: current day
     * n: number of cities
     * currCity: current location
   - Returns maximum possible score from this state

3. **maxScore() Function**:
   - Tries each city as starting point
   - Returns global maximum score

## Complexity Analysis
- **Time Complexity**: O(k × n²)
  * States: k days × n cities
  * Each state considers n travel options
  * Memoization ensures each state computed once

- **Space Complexity**: O(k × n)
  * DP table size
  * Recursion stack depth O(k)

## Example Walkthrough
Using sample input: n=2, k=1, stayScore=[[2,3]], travelScore=[[0,2],[1,0]]

1. Try starting from City 0:
   - Stay: 2 points
   - Travel to City 1: 2 points
   - Maximum: 2 points

2. Try starting from City 1:
   - Stay: 3 points
   - Travel to City 0: 1 point
   - Maximum: 3 points

3. Global maximum: 3 points (start in City 1 and stay)

# Maximum Travel Content Score: Comprehensive Solution

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

## Dynamic Programming Approaches

### Approach 1: Top-Down Recursive Solution with Memoization

#### Recurrence Relation
```
dp[k][curr] = max(
    stayScore[k][curr] + dp[k+1][curr],
    max(travelScore[curr][i] + dp[k+1][i]) for all cities i
)
```

#### Implementation
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

#### Complexity Analysis (Top-Down)
- **Time Complexity**: O(k × n²)
  * States: k days × n cities
  * Each state considers n travel options
  * Memoization ensures each state computed once

- **Space Complexity**: O(k × n)
  * DP table size
  * Recursion stack depth O(k)

### Approach 2: Bottom-Up Dynamic Programming Solution

#### Implementation
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

#### Complexity Analysis (Bottom-Up)
- **Time Complexity**: O(k × n²)
  * `k`: Days
  * `n`: Cities
  * Each day involves checking all city pairs

- **Space Complexity**: O(k × n)
  * DP table size

## Example Walkthrough
Using sample input: n=2, k=1, stayScore=[[2,3]], travelScore=[[0,2],[1,0]]

### Top-Down Approach:
1. Try starting from City 0:
   - Stay: 2 points
   - Travel to City 1: 2 points
   - Maximum: 2 points

2. Try starting from City 1:
   - Stay: 3 points
   - Travel to City 0: 1 point
   - Maximum: 3 points

3. Global maximum: 3 points (start in City 1 and stay)

### Bottom-Up Approach:
1. Day 0:
   - City 0: Stay = 2, Travel = 2
   - City 1: Stay = 3, Travel = 1

2. Day 1:
   - Max score = 3 (Start in City 1 and stay)

## Key Insights
1. Both approaches solve the problem using dynamic programming
2. Top-down uses recursion with memoization
3. Bottom-up uses iterative table filling
4. Both have similar time and space complexity
5. Choice between approaches depends on personal preference and specific use case

## Recommendation
- Use top-down approach if you prefer recursive thinking
- Use bottom-up approach for slightly better space efficiency
- Both solutions provide optimal results for the maximum travel content score problem
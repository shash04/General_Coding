// Given the array houses and an integer k. where houses[i] is the location of the ith house along a street,
// your task is to allocate k mailboxes in the street.

// Return the minimum total distance between each house and its nearest mailbox.

// The answer is guaranteed to fit in a 32-bit signed integer.

// Example 1:
// Input: houses = [1,4,8,10,20], k = 3
// Output: 5
// Explanation: Allocate mailboxes in position 3, 9 and 20.
// Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 

// Example 2:
// Input: houses = [2,3,5,12,18], k = 2
// Output: 9
// Explanation: Allocate mailboxes in position 3 and 14.
// Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.

// Example 3:
// Input: houses = [7,4,6,1], k = 1
// Output: 8

// Example 4:
// Input: houses = [3,6,14,10], k = 4
// Output: 0

// Constraints:

// n == houses.length
// 1 <= n <= 100
// 1 <= houses[i] <= 10^4
// 1 <= k <= n
// Array houses contain unique integers.

// https://leetcode.com/problems/allocate-mailboxes/

class Solution {
    int n;
    vector<vector<int>> costs;
    vector<vector<int>> memo;
    
    int dp(vector<int>& houses, int cur, int k)
    {
        // If no more boxes to place and last house done
        if(k == 0 && cur == n)
            return 0;
        
        // If either no more boxes to place OR last house done
        if(k == 0 || cur == n)
            return INT_MAX;
        
        if(memo[k][cur] != -1)
            return memo[k][cur];
        
        int ans = INT_MAX;
        
        // Min cost for placing k boxes from cur loc : curAns =
        // min(curAns, min cost for placing k - 1 boxes from cur + 1 location)
        for(int j = cur; j < n; j++)
        {
            int remaining = dp(houses, j + 1, k - 1);
            
            if(remaining != INT_MAX)
                ans = min(ans, costs[cur][j] + remaining);
        }
        
        memo[k][cur] = ans;
        return ans;
    }
public:
    int minDistance(vector<int>& houses, int k) {
        n = houses.size();
        
        // for 2 houses, cost is minimized by placing the mailbox at median
        // costs[i][j] = cumulative cost of placing a mailbox in between i and j (at median of i and j)
        // memo[i][j] = min cost of placing i boxes starting from j
        
        costs.resize(n, vector<int>(n, 0));
        memo.resize(k + 1, vector<int>(n, -1));
        
        // sort houses as placement of mailboxes is to be done at medians
        sort(houses.begin(), houses.end());
        
        // Populate the costs for placing one mailbox between all combinations of i and j
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                // For a starting and ending point (i and j), add costs for all houses in between
                for(int t = i; t <= j; t++)
                {
                    int median = (i + j) / 2;
                    costs[i][j] += abs(houses[median] - houses[t]);
                }
            }
        }
        
        // Get min cost by recursive dp approach
        return dp(houses, 0, k);
    }
};
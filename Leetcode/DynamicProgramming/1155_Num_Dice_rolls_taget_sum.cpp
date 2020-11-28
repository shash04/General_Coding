// You have d dice, and each die has f faces numbered 1, 2, ..., f.

// Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

// Example 1:
// Input: d = 1, f = 6, target = 3
// Output: 1
// Explanation: 
// You throw one die with 6 faces.  There is only one way to get a sum of 3.

// Example 2:
// Input: d = 2, f = 6, target = 7
// Output: 6
// Explanation: 
// You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
// 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

// Example 3:
// Input: d = 2, f = 5, target = 10
// Output: 1
// Explanation: 
// You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.

// Example 4:
// Input: d = 1, f = 2, target = 3
// Output: 0
// Explanation: 
// You throw one die with 2 faces.  There is no way to get a sum of 3.

// Example 5:
// Input: d = 30, f = 30, target = 500
// Output: 222616187
// Explanation: 
// The answer must be returned modulo 10^9 + 7.
 
// Constraints:

// 1 <= d, f <= 30
// 1 <= target <= 1000

// ********************************************************************************
// DP - bottom - UP approach - 1D Vector
// ********************************************************************************
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp (target + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= d; i++)
        {
            for(int t = target; t >= 0; t--)
            {
                dp[t] = 0;
                
                for(int k = 1; k <= f; k++)
                {
                    dp[t] += t >= k ? dp[t- k] : 0;
                    dp[t] = dp[t] % 1000000007;
                }
            }
        }
        
        return dp[target];
    }
};


// ********************************************************************************
// DP - bottom - UP approach - 2D vector
// ********************************************************************************

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= d; i++)
        {
            for(int t = 1; t <= target; t++)
            {
                for(int k = 1; k <= f; k++)
                {
                    dp[i][t] += (k <= t) ? dp[i - 1][t - k] : 0;
                    dp[i][t] %= 1000000007;
                }
            }
        }
        
        return dp[d][target];
    }
};

// ********************************************************************************
// Memoization technique - TLE for some cases
// ********************************************************************************
class Solution {
    map<pair<int, int>, int> memo;
public:
    int numRollsToTarget(int d, int f, int target) {
        if(d == 0)
            return target == 0;
        
        if(memo[make_pair(d, target)])
            return memo[make_pair(d, target)];
        
        int curRes = 0;
        
        for(int i = 1; i <= f; i++)
        {
            curRes += numRollsToTarget(d - 1, f, target - i);
        }
        
        memo[make_pair(d, target)] = curRes % 1000000007;
        return curRes;
    }
};

// ********************************************************************************
// Better Memoization with use of vectors - FASTEST OF ALL SOLUTIONS ##############
// ********************************************************************************
class Solution {
    vector<vector<int>> memo;
    
    int recursive(int d, int f, int target)
    {
        if(d == 0 || target < 0)
            return target == 0 ? 1 : 0;
        
        if(memo[d][target] != -1)
            return memo[d][target];
        
        int curRes = 0;
        
        for(int i = 1; i <= f; i++)
        {
            curRes += recursive(d - 1, f, target - i);
            curRes %= 1000000007;
        }
        
        memo[d][target] = curRes;
        return curRes;
    }
public:
    int numRollsToTarget(int d, int f, int target) {
        memo.resize(d + 1, vector<int>(target + 1, -1));
        
        return recursive(d, f, target);
    }
};
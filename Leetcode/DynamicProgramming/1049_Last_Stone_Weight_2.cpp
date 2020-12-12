// We have a collection of rocks, each rock has a positive integer weight.

// Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

// If x == y, both stones are totally destroyed;
// If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
// At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

// Example 1:
// Input: [2,7,4,1,8,1]
// Output: 1
// Explanation: 
// We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
// we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
// we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
// we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.

// Note:
// 1 <= stones.length <= 30
// 1 <= stones[i] <= 100

// https://leetcode.com/problems/last-stone-weight-ii/


//*********************************************************************************************
// sum(S1) - sum(S2) = result
// totalSum - 2 * sum(S1) = result
// sum(S1) <= totalSum / 2

// Thus find max possible value of sum(S1) less than or equal to (totalSum / 2)
//*********************************************************************************************
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() == 0)
            return 0;
        
        int sum = 0;
        
        for(int& stone : stones)
            sum += stone;
        
        int target = sum / 2;
        
        vector<vector<int>> dp (stones.size() + 1, vector<int>(target + 1, 0));
        
        for(int i = 1; i <= stones.size(); i++)
        {
            for(int j = 1; j <= target; j++)
            {
                // if current stone val is more than target, can't include. Take value excluding cur stone.
                if(stones[i-1] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                // Max of (total excluding cur stone, result of dp[target - cur stone val] + cur stone val)
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - stones[i-1]] + stones[i-1]);
                }
            }
        }
        
        return sum - (2 * dp[stones.size()][target]);
    }
};
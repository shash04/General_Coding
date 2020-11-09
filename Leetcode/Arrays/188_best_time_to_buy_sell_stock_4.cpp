// Say you have an array for which the i-th element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most k transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

// Example 1:
// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

// Example 2:
// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
//              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// ******************************************************************************************************************
// Faster solution - O(k*n)
// ******************************************************************************************************************

class Solution {
    int findMaxProfitUnlimitedTransactions(vector<int>& prices)
    {
        int maxProfit = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
                maxProfit += prices[i] - prices[i-1];
        }
        
        return maxProfit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        
        // Optimization for very high k (unlimited transactions) to avoid allocation huge vector memory
        if(k > prices.size() / 2)
            return findMaxProfitUnlimitedTransactions(prices);
        
        vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
        
        // i = row = transaction number ; j = col = day number
        for(int i = 1; i <= k; i++)
        {
            // start with maxDiff = -prices[0]
            int maxDiff = -prices[0];
            
            for(int j = 1; j < prices.size(); j++)
            {
                // prev = don't do transaction on cur day and take max from last day
                int prev = dp[i][j-1];
                
                dp[i][j] = max(prev, prices[j] + maxDiff);
                
                maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
            }
        }
        
        return dp[k][prices.size() - 1];
    }
};

// ******************************************************************************************************************
// SLower solution - O(k*n^2)
// ******************************************************************************************************************
class Solution {
    int findMaxProfitUnlimitedTransactions(vector<int>& prices)
    {
        int maxProfit = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
                maxProfit += prices[i] - prices[i-1];
        }
        
        return maxProfit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        // Optimization for very high k (unlimited transactions) to avoid allocation huge vector memory
        if(k > prices.size() / 2)
            return findMaxProfitUnlimitedTransactions(prices);
        
        vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
        
        // i = row = transaction number ; j = col = day number
        for(int i = 1; i <= k; i++)
        {
            for(int j = 1; j < prices.size(); j++)
            {
                // prev = don't do transaction on cur day and take max from last day
                int prev = dp[i][j-1];
                
                // get max(selling on j day - buying on some prev day m + dp[one less transaction][m]
                int curMax = INT_MIN;
                
                for(int m = 0; m < j; m++)
                {
                    curMax = max(curMax, prices[j] - prices[m] + dp[i-1][m]);
                }
                
                // curr max profit is max of the two values computed
                dp[i][j] = max(curMax, prev);
            }
        }
        
        return dp[k][prices.size() - 1];
    }
};
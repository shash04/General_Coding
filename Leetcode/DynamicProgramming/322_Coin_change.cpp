// You are given coins of different denominations and a total amount of money amount.
// Write a function to computethe fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:
// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1

// Example 2:
// Input: coins = [2], amount = 3
// Output: -1
// Note:
// You may assume that you have an infinite number of each kind of coin.

// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount + 1, amount + 1);
        
        dp[0] = 0;                                          // zero coins required to make zero sum
        
        for(int coin : coins)                               // Iterate over all coins
        {
            for(int i=coin; i<=amount; i++)                 // Starting index is always higher than coin value
            {
                dp[i] = min(dp[i], 1 + dp[i-coin]);         // min(num coins of prev value, 1 + num coins wihout current coin value)
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
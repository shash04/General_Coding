// Given coins of certain denominations and a total, how many minimum coins would you need to make this total.

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
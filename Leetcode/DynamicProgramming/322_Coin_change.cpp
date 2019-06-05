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
        vector<int> v1 (amount + 1, amount + 1);
        v1[0] = 0;
        
        for(int coin : coins)                               // Iterate over all coins
        {
            for(int i=coin; i<=amount; i++)                 // Starting index is always higher than coin value
            {
                v1[i] = min(v1[i], 1 + v1[i-coin]);         // min of (num of coins with earlier denomination, 1 + number of coins wihout current coin value)
            }
        }
        return v1[amount] > amount ? -1 : v1[amount];
    }
};
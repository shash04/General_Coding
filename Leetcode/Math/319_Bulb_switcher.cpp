// There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb.
// On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on).
// For the i-th round, you toggle every i bulb. For the n-th round, you only toggle the last bulb.
// Find how many bulbs are on after n rounds.

// Example:
// Input: 3
// Output: 1 
// Explanation: 
// At first, the three bulbs are [off, off, off].
// After first round, the three bulbs are [on, on, on].
// After second round, the three bulbs are [on, off, on].
// After third round, the three bulbs are [on, off, off]. 

// So you should return 1, because there is only one bulb is on.

// https://leetcode.com/problems/bulb-switcher/

class Solution {
public:
    int bulbSwitch(int n) {
        int onBulbCount = 0;

        // Assuming we start with all bulbs off
        // Bulb number with ood number of factors will remain on in the end
        // Only perfect squares have odd number of factors
        // For e.g. Factors of 18 - 1,2,3,6,9,18
        // For e.g. Factors of 16 - 1,2,4,8,16
        // As 4 * 4 makes it a perfect square, it makes the num factors odd
        for (int i = 1; i*i <= n; i++)
        {
            onBulbCount++;    
        }

        return onBulbCount;
    }
};
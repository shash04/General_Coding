// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
// Find the two elements that appear only once. You can return the answer in any order.

// Follow up: Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?


// Example 1:
// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.

// Example 2:
// Input: nums = [-1,0]
// Output: [-1,0]

// Example 3:
// Input: nums = [0,1]
// Output: [1,0]
 

// Constraints:
// 1 <= nums.length <= 30000
//  Each integer in nums will appear twice, only two integers will appear once.

// https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        
        // Get a bitmask that is combination of two numbers that appear only once
        for(int& n : nums)
            bitmask ^= n;
        
        // Bitmask has combination of two numbers
        // Convert bitmask to reflect only the rightmost set bit different for both numbers
        bitmask = bitmask & (-bitmask);
        
        // Using the above bitmask, split the numbers in two sets for which the bit is set or unset
        // This property is going to help us differentiate x and y
        // All the numbers repeated twice will fall in same bucket and negate each other due to XOR operation
        vector<int> ans = {0, 0};
        
        for(int& n : nums)
        {
            if((bitmask & n) == 0)
                ans[0] = ans[0] ^ n;
            else
                ans[1] = ans[1] ^ n;
        }
        
        return ans;
    }
};
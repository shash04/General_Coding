// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Example 1:
// Input: [2,2,3,2]
// Output: 3

// Example 2:
// Input: [0,1,0,1,0,1,99]
// Output: 99

// https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Ones keep track of numbers appeared once till now
        // Twos keeps track of numbers appeared twice till now
        int ones = 0;
        int twos = 0;
        
        for(int& n : nums)
        {
            // Add a number to ones if it is not present in ones (0 ^ A = A) and it is not present in twos (~twos)
            // If the number is present, remove it from ones (A ~ A = 0)
            ones = (ones ^ n) & ~twos;
            
            // Add a number to twos if it is not present in twos (0 ^ A = A) and it is not present in ones (~ones)
            // If the number has appeared once, it should get removed in prev step
            // If the number is present in twos, remove it (A ~ A = 0)
            twos = (twos ^ n) & ~ones;
        }
        
        // Only the number appeared once remains in ones
        return ones;
    }
};
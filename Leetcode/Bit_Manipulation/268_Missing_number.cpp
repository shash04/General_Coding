// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

// Example 1:
// Input: [3,0,1]
// Output: 2

// Example 2:
// Input: [9,6,4,2,3,5,7,0,1]
// Output: 8
// Note:
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

// https://leetcode.com/problems/missing-number/

/*
Concept - number XOR number = 0
number XOR 0 = number
nums contains n numbers and it is missing exactly one number on the range [0..n-1],
we know that n definitely replaces the missing number in nums.
Thus, initialize result = n and XOR it with every index and value, left value = missing number.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i = 0;
        
        for(int num : nums)
        {
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};
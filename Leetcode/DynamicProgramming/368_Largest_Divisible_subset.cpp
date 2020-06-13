// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

// Si % Sj = 0 or Sj % Si = 0.

// If there are multiple solutions, return any subset is fine.

// Example 1:
// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)

// Example 2:
// Input: [1,2,4,8]
// Output: [1,2,4,8]

// https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> retVec;
        
        // Sort the initial arr to use DP to add elements to subset
        sort(nums.begin(), nums.end());
        
        // dp - keeps track of max size of subset at i-th index
        // kid - keeps track of next smaller element that is part of subset
        vector<int> dp(nums.size(), 0);
        vector<int> kid(nums.size(), 0);
        
        // size of max subset, ending index of max subset
        int maxSize = 0, maxIdx = 0;
        
        // For every element, iterate till 0th element
        // Check if nums[i] % nums[j] == 0
        // if yes - increment the len in dp if max subset is smaller
        for(int i=0; i < nums.size(); i++)
        {
            for(int j=i; j >= 0; j--)
            {
                if((nums[i] % nums[j] == 0) && (dp[i] < 1 + dp[j]))
                {
                    dp[i] = 1 + dp[j];
                    kid[i] = j;
                }
                
                if(dp[i] > maxSize)
                {
                    maxSize = dp[i];
                    maxIdx = i;
                }
            }
        }
        
        // starting from max element that should be part of ans subset
        // go till smallest
        // In the end, reverse this arr to have the correct order
        for(int i=0; i < maxSize; i++)
        {
            retVec.push_back(nums[maxIdx]);
            maxIdx = kid[maxIdx];
        }
        
        reverse(retVec.begin(), retVec.end());
        
        return retVec;
    }
};
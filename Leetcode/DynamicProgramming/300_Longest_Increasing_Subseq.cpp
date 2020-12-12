// Given an unsorted array of integers, find the length of longest increasing subsequence.

// Example:
// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

// Note:
// There may be more than one LIS combination, it is only necessary for you to return the length.
// Your algorithm should run in O(n2) complexity.

// Follow up: Could you improve it to O(n log n) time complexity?

// https://leetcode.com/problems/longest-increasing-subsequence/

// **************************************************************************************************
// 1D Dp approach - O(N2) time complexity
// i th index in dp keeps track of LIS till i
// **************************************************************************************************
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int maxLis = 0;
        
        // Start with dp and all elements as 1 - min longest subsequence is num itself
        vector<int> dp (nums.size(), 1);
        
        // i would be iterating ahead of j
        // for e.g. [3,1,2] : for i=1 : j = 0; for i = 2 : j = 0, 1
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                // If num at j is less than num at i, LIS at j is max(curr value at j, 1 + LIS at i)
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }

            maxLis = max(maxLis, dp[i]);
        }            
        
        return maxLis;
    }
};

// **************************************************************************************************
// Lower Bound approach - O(N * Log(N) complexity
// **************************************************************************************************
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        vector<int> v1;
        
        for(int& n : nums)
        {
            auto iter = lower_bound(v1.begin(), v1.end(), n);
            
            if(iter != v1.end())
                *iter = n;
            else
                v1.push_back(n);
        }
        
        return v1.size();
    }
};

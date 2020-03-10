// Given an array of integers nums and a positive integer k, find whether it's possible to divide this
// array into k non-empty subsets whose sums are all equal.

// Example 1:
// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

// Note:

// 1 <= k <= len(nums) <= 16.
// 0 < nums[i] < 10000.

// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size() == 0 && k == 0)
            return false;
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
            sum += nums[i];
        
        // sum has to be divisible by k
        if(sum % k)
            return false;
        
        // bool vector to keep track of visited nums
        vector<bool> visited (nums.size(), false);
        
        return canPartitionHelper(nums, k, visited, 0, 0, sum/k);
    }
    
    bool canPartitionHelper(vector<int>& nums, int k, vector<bool>& visited, int startIdx, int currSum, int target)
    {
        // if k-1 subsets have target sum, k th subset will also have target sum
        if(k == 1)
            return true;
        
        // if target sum found, recursive call with k = k-1
        if(currSum == target)
            return canPartitionHelper(nums, k-1, visited, 0, 0, target);
        
        // early return if currSum exceeds target sum
        if(currSum > target)
            return false;
        
        // traverse through every unvisited number
        for(int i = startIdx; i < nums.size(); i++)
        {
            if(visited[i])
                continue;
            
            // make visited true and check if curr num can be inclueded in subset 
            visited[i] = true;
            
            if(canPartitionHelper(nums, k, visited, i, currSum + nums[i], target))
                return true;
            
            // if curr num can not be included in subset, un visit the num
            visited[i] = false;
        }
        
        return false;
    }
};
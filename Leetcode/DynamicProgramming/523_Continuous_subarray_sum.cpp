// Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous
// subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.

// Example 1:
// Input: [23, 2, 4, 6, 7],  k=6
// Output: True
// Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.

// Example 2:
// Input: [23, 2, 6, 4, 7],  k=6
// Output: True
// Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
 

// Constraints:
// The length of the array won't exceed 10,000.
// You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

// https://leetcode.com/problems/continuous-subarray-sum/

// ***************************************************************************************************************
// Using unordered map to store (sum % k, index) -> basically (remainder, index).
// If remainder repeated, return true if currIdx - map[rem] > 1
// ***************************************************************************************************************
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2)
            return false;
        
        unordered_map<int, int> sumIdxMap;
        
        sumIdxMap[0] = -1;
        
        int sum = 0;
        
        for(int i=0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(k != 0)
                sum = sum % k;
            
            if(sumIdxMap.count(sum))
            {
                if(i - sumIdxMap[sum] > 1)
                    return true;
            }
            else
            {
                sumIdxMap[sum] = i;
            }
        }
        
        return false;
    }
};

// ***************************************************************************************************************
// Using unordered_set to keep track of all remainders uptil now (sum % k)
// Use pre to delay insertion in set by one loop so that the window size is more than 1
// ***************************************************************************************************************
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2)
            return false;
        
        unordered_set<int> remSet;
        
        int sum = 0, pre = 0;
        
        for(int i=0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(k != 0)
                sum = sum % k;
            
            if(remSet.count(sum))
                return true;

            remSet.insert(pre);
            pre = sum;
        }
        
        return false;
    }
};

// ***************************************************************************************************************
// Better brute force approach - store sum for every window size and keep adding to these sums
// ***************************************************************************************************************
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2)
            return false;
        
        vector<int> dp (nums);
        
        for(int i=2; i <= nums.size(); i++)
        {
            for(int end = i - 1; end < nums.size(); end++)
            {
                dp[end + 1 - i] += nums[end];
                
                if(k == 0)
                {
                    if(dp[end + 1 - i] == 0)
                        return true;
                    
                    continue;
                }
                
                if(dp[end + 1 - i] % k == 0)
                    return true;
            }
        }
        
        return false;
    }
};
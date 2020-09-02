// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.

// Example 1:
// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last index.

// https://leetcode.com/problems/jump-game/

// *********************************************************************************
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        
        int i = 0;
        int maxReach = 0;
        
        for(; i < nums.size() && i <= maxReach; i++)
        {
            maxReach = max(maxReach, i + nums[i]);
        }
        
        return i == nums.size();
    }
};

// *********************************************************************************
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() < 2)
            return true;
        
        int end = 0;
        int maxEnd = 0;
        int i = 0;
        
        while(end < nums.size() - 1)
        {
            for(; i<=end; i++)
            {
                maxEnd = max(maxEnd, i + nums[i]);
                
                if(maxEnd >= nums.size() - 1)
                    return true;
            }
            
            // if you couldn't update the maxEnd => cannot reach last index
            if(end == maxEnd)
                break;
            
            end = maxEnd;
        }
        
        return false;
    }
};

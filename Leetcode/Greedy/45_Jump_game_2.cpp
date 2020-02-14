// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.

// Example:
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Note:
// You can assume that you can always reach the last index.

// https://leetcode.com/problems/jump-game-ii/

// Starting from 0th postion, calculate max end for each index.
// For each index till curr max end, get another maxEnd
// This greedy algo helps to keep max num of jumps to lowest value
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        
        int jumps = 0;
        int end = 0;
        int maxEnd = 0;
        int i = 0;
        
        while(end < nums.size() - 1)
        {
            jumps++;
            for(; i<=end; i++)
            {
                maxEnd = max(maxEnd, i + nums[i]);
                
                if(maxEnd >= nums.size() - 1)
                    return jumps;
            }
            
            // if you couldn't update the maxEnd => cannot reach last index
            if(end == maxEnd)
                break;
            
            end = maxEnd;
        }
        
        // Couldn't reach last index
        return -1;
    }
};

// *************************************************************************
// Alternate solution that assumes we will reach end index for sure
// *************************************************************************

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        
        int jumps = 0;
        int start = 0;
        int reach = 0;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            reach = max(reach, i + nums[i]);
            if(i == start)
            {
                start = reach;
                jumps++;
            }
        }
        
        return jumps;
    }
};

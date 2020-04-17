// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.

// Note:
// The solution set must not contain duplicate triplets.

// Example:
// Given array nums = [-1, 0, 1, 2, -1, -4],
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++)
        {
            int target = -nums[i];                      // For every num, try and find 2sum
            int start = i+1;
            int end = nums.size()-1;
            
            if(target < 0)                              // Already in positive range. All/No negative numbers to left
                break;
            
            while(start < end)
            {
                int sum = nums[start] + nums[end];      // Current sum
                
                if(sum < target)                        // Move start pointer if curr sum < target
                    start++;
                else if(sum > target)                   // Move end pointer if curr sum > target
                    end--;
                else                                    // Perfect combination found
                {
                    vector<int> v1 = {nums[i], nums[start], nums[end]};
                    ret.push_back(v1);
                    
                    while(start < end && nums[start] == v1[1])      // Avoid duplicates for curr start num
                        start++;
                    
                    while(end > start && nums[end] == v1[2])        // Avoid duplicates for curr end num
                        end--;
                }
            }
            
            while(i+1 < nums.size() && nums[i] == nums[i+1])        // Avoid duplicates for first num in combination
                i++;
        }
        return ret;
    }
};

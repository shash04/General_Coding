// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// Example:
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

// https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if(!nums.size())
            return result;
        
        sort(nums.begin(), nums.end());        
        getAllPermutations(nums, result, 0);
        return result;
    }
    
    void getAllPermutations(vector<int> nums, vector<vector<int>>& result, int curr_index)
    {
        if(curr_index >= nums.size())
        {
            result.push_back(nums);
            return;
        }
        
        for(int i=curr_index; i<nums.size(); i++)
        {
            if(i == curr_index || nums[i] != nums[curr_index])
            {
                swap(nums[curr_index], nums[i]);
                getAllPermutations(nums, result, curr_index+1);
                // swap(nums[curr_index], nums[i]);
            }
        }
    }
};
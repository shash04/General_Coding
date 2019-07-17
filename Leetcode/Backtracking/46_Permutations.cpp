// Given a collection of distinct integers, return all possible permutations.

// Example:
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(!nums.size())
            return result;
        
        getAllPermutations(nums, result, 0);
        return result;
    }
    
    void getAllPermutations(vector<int>& nums, vector<vector<int>>& result, int curr_index)
    {
        if(curr_index >= nums.size())
        {
            result.push_back(nums);
            return;
        }
        
        for(int i=curr_index; i<nums.size(); i++)
        {
            swap(nums[curr_index], nums[i]);
            getAllPermutations(nums, result, curr_index+1);
            swap(nums[curr_index], nums[i]);
        }
    }
};
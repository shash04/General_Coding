// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> retVec;
        vector<int> currVec;
        getCombinations(retVec, currVec, 0, nums);
        return retVec;
    }
    
    void getCombinations(vector<vector<int>>& retVec, vector<int> currVec, int i, vector<int>& nums)
    {
        retVec.push_back(currVec);
        
        for(int k = i; k < nums.size(); k++)
        {
            currVec.push_back(nums[k]);
            getCombinations(retVec, currVec, k+1, nums);
            currVec.pop_back();
        }
    }
};
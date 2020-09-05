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

// ******************************************************************************************************
// Solution with extra space but easy to understsand
// ******************************************************************************************************

class Solution {
    unordered_map<int, int> numMap;
    
    void backtrack(vector<vector<int>>& retVec, vector<int> currVec, int len)
    {
        if(currVec.size() == len)
        {
            retVec.push_back(currVec);
            return;
        }
        
        for(auto& entry : numMap)
        {
            if(entry.second > 0)
            {
                entry.second--;
                currVec.push_back(entry.first);
                
                backtrack(retVec, currVec, len);
                
                currVec.pop_back();
                entry.second++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> retVec;
        
        for(int& n : nums)
            numMap[n]++;
        
        backtrack(retVec, {}, nums.size());
        
        return retVec;
    }
};

// ******************************************************************************************************
// Solution with no extra space but difficult to understand no to swap back logic
// ******************************************************************************************************

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

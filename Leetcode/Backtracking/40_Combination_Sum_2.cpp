// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
// Each number in candidates may only be used once in the combination.
// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        vector<vector<int>> result;
        
        getAllCombinations(candidates, target, combination, result, 0);
        
        return result;
    }
    
    void getAllCombinations(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& result, int begin)
    {
        if(target == 0)
        {
            result.push_back(combination);
            return;
        }
        
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
        {
            // Conditions to avoid duplicates. For example 2 - avoid multiple [1,2,2]
            if (i == begin || candidates[i] != candidates[i - 1])
            {
                combination.push_back(candidates[i]);
                getAllCombinations(candidates, target - candidates[i], combination, result, i + 1);
                combination.pop_back();
            }
        } 
    }
};
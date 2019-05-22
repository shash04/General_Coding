// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sums to target.
// The same repeated number may be chosen from candidates unlimited number of times.
// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]

// Example 2:
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Sort the original list of candidates
        sort(candidates.begin(), candidates.end());
        
        vector<int> currCombination;
        vector<vector<int>> result;
        
        // Function populates individual combination and pushes to result vector
        getCombinations(candidates, target, currCombination, result, 0);
        
        return result;
    }
    
    void getCombinations(vector<int>& candidates, int target, vector<int>& currCombination, vector<vector<int>>& result, int begin)
    {
        // If the target sum is achieved => found correct combination
        if(target == 0)
        {
            result.push_back(currCombination);
            return;
        }
        
        // Starting from the begin position, push element and do recursive call
        // Either target sum will be achieved and combination stored OR
        // Remove last element and try with next element possible
        for(int i=begin; i < candidates.size() && target >= candidates[i]; i++)
        {
            currCombination.push_back(candidates[i]);
            getCombinations(candidates, target - candidates[i], currCombination, result, i);
            currCombination.pop_back();
        }
    }
};
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
        // Important to sort candidates to avoid duplicates and target >= candidates[i] to work
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> retVec;
        vector<int> currVec;
        
        getCombinations(retVec, candidates, target, currVec, 0);
        
        return retVec;
    }
    
    void getCombinations(vector<vector<int>>& retVec, vector<int>& candidates, int target, vector<int>& currVec, int currIdx)
    {
        if(target == 0)
        {
            retVec.push_back(currVec);
            return;
        }
        
        for(int i=currIdx; i < candidates.size() && target >= candidates[i]; i++)
        {
            // Conditions to avoid duplicates. For example 2 - avoid multiple [1,2,2]
            if(i != currIdx && candidates[i] == candidates[i-1])
                continue;
            
            currVec.push_back(candidates[i]);
            getCombinations(retVec, candidates, target - candidates[i], currVec, i+1);
            currVec.pop_back();
        }
    }
};

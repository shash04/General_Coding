// Find all possible combinations of k numbers that add up to a number n, given that only numbers
// from 1 to 9 can be used and each combination should be a unique set of numbers.

// Note:
// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.

// Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]

// Example 2:
// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> retVec;
        
        if(n == 0 || k == 0)
            return retVec;
        
        vector<int> currVec;
        
        backtrack(retVec, currVec, 1, k, n);
        
        return retVec;
    }
    
    void backtrack(vector<vector<int>>& retVec, vector<int>& currVec, int currN, int& k, int n)
    {
        if(currVec.size() == k && n == 0)
        {
            retVec.push_back(currVec);
            return;
        }
        
        if(currVec.size() > k)
            return;
        
        for(int i = currN; i <= 9 && n >= i; i++)
        {
            currVec.push_back(i);
            backtrack(retVec, currVec, i+1, k, n - i);
            currVec.pop_back();
        }
    }
};
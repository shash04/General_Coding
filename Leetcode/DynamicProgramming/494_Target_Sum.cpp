// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -.
// For each integer, you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.

// Example 1:

// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// There are 5 ways to assign symbols to make the sum of nums be target 3.
 

// Constraints:
// The length of the given array is positive and will not exceed 20.
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.

// https://leetcode.com/problems/target-sum/

// ***************************************************************************************************************
// 1D DP approach
// ***************************************************************************************************************

// ***************************************************************************************************************
// 2D DP approach
// ***************************************************************************************************************


// ***************************************************************************************************************
// Recusrive approach with memoization assuming that max sum is 1000
// ***************************************************************************************************************
class Solution {
    vector<vector<int>> idxSumAns;
    
    int recursive(vector<int>& nums, int S, int idx, int curSum)
    {
        if(idx == nums.size())
        {
            if(curSum == S)
                return 1;
            else
                return 0;
        }
        
        if(idxSumAns[idx][curSum + 1000] != -1)
            return idxSumAns[idx][curSum + 1000];
        
        int ans =   recursive(nums, S, idx + 1, curSum + nums[idx]);
        ans +=      recursive(nums, S, idx + 1, curSum - nums[idx]);
        
        idxSumAns[idx][curSum + 1000] = ans;
        
        return ans;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
            return 0;
        
        // Assuming max sum is 1000. Thus indexing sum as sum + 1000 to take care of negative sums
        idxSumAns.resize(nums.size(), vector<int>(2001, -1));
        
        return recursive( nums, S, 0, 0);
    }
};

// ***************************************************************************************************************
// Recursive approach with memoization with Map
// ***************************************************************************************************************
class Solution {
    map<pair<int, int>, int> idxSumAns;
    
    int recursive(vector<int>& nums, int S, int idx, int curSum)
    {
        if(idx == nums.size())
        {
            if(curSum == S)
                return 1;
            else
                return 0;
        }
        
        if(idxSumAns.count(make_pair(idx, curSum)))
            return idxSumAns[make_pair(idx, curSum)];
        
        int ans =   recursive(nums, S, idx + 1, curSum + nums[idx]);
        ans +=      recursive(nums, S, idx + 1, curSum - nums[idx]);
        
        idxSumAns[make_pair(idx, curSum)] = ans;
        
        return ans;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
            return 0;
        
        return recursive( nums, S, 0, 0);
    }
};

// ***************************************************************************************************************
// Recusive Approach - slowest
// ***************************************************************************************************************
class Solution {
    void recursive(int& ans, vector<int>& nums, int S, int idx, int curSum)
    {
        if(idx == nums.size())
        {
            if(curSum == S)
                ans++;
            
            return;
        }
        
        recursive(ans, nums, S, idx + 1, curSum + nums[idx]);
        recursive(ans, nums, S, idx + 1, curSum - nums[idx]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        
        if(nums.size() == 0)
            return 0;
        
        recursive(ans, nums, S, 0, 0);
        
        return ans;
    }
};
// Given an array A of integers, return the length of the longest arithmetic subsequence in A.

// Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and
// that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

// Example 1:
// Input: A = [3,6,9,12]
// Output: 4
// Explanation: 
// The whole array is an arithmetic sequence with steps of length = 3.

// Example 2:
// Input: A = [9,4,7,2,10]
// Output: 3
// Explanation: 
// The longest arithmetic subsequence is [4,7,10].

// Example 3:
// Input: A = [20,1,15,3,10,5,8]
// Output: 4
// Explanation: 
// The longest arithmetic subsequence is [20,15,10,5].

// Constraints:
// 2 <= A.length <= 1000
// 0 <= A[i] <= 500

// https://leetcode.com/problems/longest-arithmetic-subsequence/

// ************************************************************************
// Optimized solution for time
// Find max diff possible in the given array = 2 * maxVal + 1
// Create a 2D array with indexing as [difference][A vector indices]
// ************************************************************************
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.size() < 2)
            return A.size();
        
        int maxLen = 0;
        
        int maxVal = 0;
        
        for(int& n : A)
            maxVal = max(maxVal, n);
        
        // 2 * maxVal + 1 size as adding maxVal to diff to avoid -ve diff
        // row = diff ; col = num of numbers till j-th index in A having diff == diff
        vector<vector<int>> dp(2 * maxVal + 1, vector<int>(A.size(), 0));      
        
        for(int i = 1; i < A.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                int diff = A[i] - A[j] + maxVal;        // Add maxVal so that diff is not negative and thus no -ve idx
                
                dp[diff][i] = dp[diff][j] + 1;
                
                maxLen = max(maxLen, dp[diff][i]);
            }
        }
        
        return maxLen + 1;
    }
};

// ************************************************************************
// Natural response
// Create a 2D array with indexing as [A vector indices][difference]
// arithmatic sequence - difference d is important
// for every number
// - iterate throught all prev numbers and find d
// - add the entry or increment the entry of d and store per index
// - per index we need to keep track of multiple diff d (2D array)
// ************************************************************************

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.size() == 0)
            return 0;
        
        int maxLen = 1;
        
        unordered_map<int, unordered_map<int, int>> idxDiff;
        
        for(int i = 1; i < A.size(); i ++)
        {
            for(int j = 0; j < i; j++)
            {
                int d = A[i] - A[j];
                
                if(idxDiff[j].count(d))
                    idxDiff[i][d] = 1 + idxDiff[j][d];
                else
                    idxDiff[i][d] = 1;
                
                maxLen = max(maxLen, idxDiff[i][d]);
            }
        }
        
        return maxLen + 1;
    }
};

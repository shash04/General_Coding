// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example:
// Input: 

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4

// https://leetcode.com/problems/maximal-square/

// ********************************************************************************************************************
// Space complexity - O(m * n)
// ********************************************************************************************************************
class Solution {
    int nR;
    int nC;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        int retSize = 0;
        nR = matrix.size();
        nC = matrix[0].size();
        
        vector<vector<int>> dp (nR, vector<int>(nC, 0));
        
        for(int i=0; i < nR; i++)
        {
            for(int j=0; j < nC; j++)
            {
                if(i==0 || j==0 || matrix[i][j] == '0')
                {
                    // If matrix[i][j] == 0, curr i and j can't be in square
                    // If matrix[i][j] == 1 for i==0 || j==0, Max square dim for top row and left col is 1
                    dp[i][j] = matrix[i][j] - '0';
                }
                else
                {
                    dp[i][j] = minOfThree(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
                }
                
                retSize = max(retSize, dp[i][j]);
            }
        }
        
        return retSize * retSize;
    }
    
    int minOfThree(int& a, int& b, int& c)
    {
        return min(min(a, b), c);
    }
};

// ********************************************************************************************************************
// Space complexity - O(n) - Use two vectors (pre - keeps prev row information and curr - keeps curr row information)
// ********************************************************************************************************************
class Solution {
    int nR;
    int nC;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        int retSize = 0;
        nR = matrix.size();
        nC = matrix[0].size();
        
        vector<int> pre (nC, 0);
        vector<int> cur (nC, 0);
        
        for(int i=0; i < nR; i++)
        {
            for(int j=0; j < nC; j++)
            {
                if(i==0 || j==0 || matrix[i][j] == '0')
                {
                    cur[j] = matrix[i][j] - '0';
                }
                else
                {
                    cur[j] = minOfThree(pre[j-1], pre[j], cur[j-1]) + 1;
                }
                
                retSize = max(retSize, cur[j]);
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        
        return retSize * retSize;
    }
    
    int minOfThree(int& a, int& b, int& c)
    {
        return min(min(a, b), c);
    }
};
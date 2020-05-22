// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

// Example 1:
// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15

// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.

// Example 2:
// Input: matrix = 
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7

// Explanation: 
// There are 6 squares of side 1.  
// There is 1 square of side 2. 
// Total number of squares = 6 + 1 = 7.

// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

// ***************************************************************************************************
// 1D DP - Time Complexity O(M * N)
// Space Complexity O(N)
// ***************************************************************************************************
class Solution {
    int nR, nC;
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        int retAns = 0;
        
        nR = matrix.size();
        nC = matrix[0].size();
        
        // Every entry in dp corresponds to num of squares formed till i,j as right bottom corner
        vector<int> prevRow (nC, 0);
        vector<int> currRow (nC, 0);
        
        
        for(int i=0; i < nR; i++)
        {
            for(int j=0; j < nC; j++)
            {
                // For first row and col, max num of squares that could be formed is 1
                if(matrix[i][j] == 1)
                {
                    if(i == 0 || j == 0)
                    {
                        currRow[j] = 1;
                    }
                    // if matrix[i][j] == 1, check for min size of square (3 ways to do that)
                    // that could be formed by adding i,j as right bottom corner.
                    else
                    {
                        currRow[j] = 1 + min(prevRow[j-1], min(prevRow[j], currRow[j-1]));
                    }
                    retAns += currRow[j];
                }
            }
            fill(prevRow.begin(), prevRow.end(), 0);
            prevRow.swap(currRow);
        }
        
        return retAns;
    }
};

// ***************************************************************************************************
// 2D DP - Time Complexity O(M * N)
// Space Complexity O(M * N)
// ***************************************************************************************************

class Solution {
    int nR, nC;
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        int retAns = 0;
        
        nR = matrix.size();
        nC = matrix[0].size();
        
        // Every entry in dp corresponds to num of squares formed till i,j as right bottom corner
        vector<vector<int>> dp (nR, vector<int>(nC, 0));
        
        for(int i=0; i < nR; i++)
        {
            for(int j=0; j < nC; j++)
            {
                if(matrix[i][j] == 1)
                {
                    // For first row and col, max num of squares that could be formed is 1
                    if(i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    // if matrix[i][j] == 1, check for min size of square (3 ways to do that)
                    // that could be formed by adding i,j as right bottom corner.
                    else
                    {
                        dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    }
                    
                    retAns += dp[i][j];
                }
            }
        }
        
        return retAns;
    }
};
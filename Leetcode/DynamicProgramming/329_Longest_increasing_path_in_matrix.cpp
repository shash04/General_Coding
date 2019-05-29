// Given an integer matrix, find the length of the longest increasing path.
// From each cell, you can either move to four directions: left, right, up or down.
// You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

// Example 1:
// Input: nums = 
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [1, 2, 6, 9].

// Example 2:
// Input: nums = 
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

// https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3072/

// Concept: Keep track of max path for each cell in mtarix (split into subproblems). Typical DP problem.
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(!rows)
            return 0;
        int cols = matrix[0].size();
        
        // Create a look up table for max path for each cell in matrix
        vector<int> dp_row ( cols, -1);
        vector<vector<int>> dp (rows, dp_row);
        
        int longestPath = 1;
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(dp[i][j] == -1)
                    DFS(matrix, dp, i, j);
                longestPath = max(longestPath, dp[i][j]);
            }
        }
        return longestPath;
    }
    
    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Initialize curr_max variable to keep track for max path for current cell
        int curr_max = 1;
        
        if(i-1>=0 && matrix[i-1][j] > matrix[i][j])
            curr_max = max(curr_max, 1 + DFS(matrix, dp, i-1, j));
        
        if(i+1<rows && matrix[i+1][j] > matrix[i][j])
            curr_max = max(curr_max, 1 + DFS(matrix, dp, i+1, j));
        
        if(j-1>=0 && matrix[i][j-1] > matrix[i][j])
            curr_max = max(curr_max, 1 + DFS(matrix, dp, i, j-1));
        
        if(j+1<cols && matrix[i][j+1] > matrix[i][j])
            curr_max = max(curr_max, 1 + DFS(matrix, dp, i, j+1));
        
        // Update the max path length for current cell
        dp[i][j] = curr_max;
        return dp[i][j];
    }
};

// TIME LIMIT EXCEEDED
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(!rows)
            return 0;
        int cols = matrix[0].size();
        int longestPath = 1;
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                int curr_path = 1;
                DFS(matrix, longestPath, curr_path, i, j);
            }
        }
        return longestPath;
    }
    
    void DFS(vector<vector<int>>& matrix, int& longestPath, int curr_path, int i, int j)
    {
        if(matrix[i][j] == INT_MIN)
            return;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        longestPath = max(longestPath, curr_path);
        
        int tempVal = matrix[i][j];
        matrix[i][j] = INT_MIN;
        
        if(i-1>=0 && matrix[i-1][j] > tempVal)
            DFS(matrix, longestPath, curr_path + 1, i-1, j);
        
        if(i+1<rows && matrix[i+1][j] > tempVal)
            DFS(matrix, longestPath, curr_path + 1, i+1, j);
        
        if(j-1>=0 && matrix[i][j-1] > tempVal)
            DFS(matrix, longestPath, curr_path + 1, i, j-1);
        
        if(j+1<cols && matrix[i][j+1] > tempVal)
            DFS(matrix, longestPath, curr_path + 1, i, j+1);
        
        matrix[i][j] = tempVal;
    }
};
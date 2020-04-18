// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Example:
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.

// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(!grid.size() || !grid[0].size())
            return 0;
        
        int nR = grid.size();
        int nC = grid[0].size();
        
        vector<vector<int>> sum (nR, vector<int>(nC, grid[0][0]));
        
        // boundary condition for left col
        // min sum to reach any index is sum of all prev indexes
        for(int i=1; i < nR; i++)
            sum[i][0] = sum[i-1][0] + grid[i][0];
        
        // boundary condition for top row
        for(int j=1; j < nC; j++)
            sum[0][j] = sum[0][j-1] + grid[0][j];
        
        for(int i=1; i < nR; i++)
        {
            for(int j=1; j < nC; j++)
            {
                sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
            }
        }
        
        return sum[nR-1][nC-1];
    }
};
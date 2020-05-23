// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

// Example 1:
// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]

// Example 2:
// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]

// Follow up:
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

// https://leetcode.com/problems/set-matrix-zeroes/

// ***********************************************************************************
// Space complexity - O(1)
// ***********************************************************************************
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 | matrix[0].size() == 0)
            return;
        
        bool col0 = false;
        int nR = matrix.size();
        int nC = matrix[0].size();
        
        // keep track of zero row and col in first ele in row and col
        // special flag for first col to avoid overwriting actual 0 info for 0,0
        for(int i=0; i < nR; i++)
        {
            if(matrix[i][0] == 0)
                col0 = true;
            
            for(int j = 1; j < nC; j++)
            {
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        
        // important to go from end to begin to avoid overwriting first row and col
        for(int i=nR-1; i >= 0; i--)
        {
            for(int j=nC-1; j >= 1; j--)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            
            if(col0 == true)
                matrix[i][0] = 0;
        }
    }
};

// ***********************************************************************************
// Space complexity - O(m + n)
// ***********************************************************************************
class Solution {
    int nR;
    int nC;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
        
        nR = matrix.size();
        nC = matrix[0].size();
        vector<pair<int,int>> zeroLoc;
        vector<bool> rowSkip (nR, false);
        vector<bool> colSkip (nC, false);
        
        for(int i=0; i < nR; i++)
        {
            for(int j=0; j < nC; j++)
            {
                if(matrix[i][j] == 0)
                    zeroLoc.push_back({i,j});
            }
        }
        
        for(auto& entry : zeroLoc)
        {
            int r = entry.first;
            int c = entry .second;
            
            if(!rowSkip[r])
            {
                setRowZero(matrix, r);
                rowSkip[r] = true;
            }
            
            if(!colSkip[c])
            {
                setColZero(matrix, c);
                colSkip[c] = true;
            }
        }
    }
    
    void setRowZero(vector<vector<int>>& matrix, int r)
    { 
        for(int j=0; j < nC; j++)
            matrix[r][j] = 0;
    }
    
    void setColZero(vector<vector<int>>& matrix, int c)
    {
        for(int i=0; i < nR; i++)
            matrix[i][c] = 0;
    }
};

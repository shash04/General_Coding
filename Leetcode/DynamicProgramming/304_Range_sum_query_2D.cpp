// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by
// its upper left corner (row1, col1) and lower right corner (row2, col2).

// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12

// Note:
// You may assume that the matrix does not change.
// There are many calls to sumRegion function.
// You may assume that row1 ≤ row2 and col1 ≤ col2.

// https://leetcode.com/problems/range-sum-query-2d-immutable/

// Concept : Entry (x,y) in sumMatrix will have sum from 0,0 in matrix till (x-1, y-1) in matrix
class NumMatrix {
    vector<vector<int>> sumMatrix;
    int nR;
    int nC;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
        
        nR = matrix.size();
        nC = matrix[0].size();
        
        sumMatrix.resize(nR+1, vector<int>(nC+1, 0));
        
        // Fill all rows for first column
        int currSum = 0;
        for(int i=1; i <= nR; i++)
        {
            currSum += matrix[i-1][0];
            sumMatrix[i][1] = currSum;
        }
        
        // Fill all columns for first row
        currSum = 0;
        for(int j=1; j <= nC; j++)
        {
            currSum += matrix[0][j-1];
            sumMatrix[1][j] = currSum;
        }
        
        // Fill rest of the matrix
        for(int i=2; i <= nR; i++)
        {
            for(int j=2; j <= nC; j++)
            {
                currSum = matrix[i-1][j-1] + sumMatrix[i-1][j] + sumMatrix[i][j-1] - sumMatrix[i-1][j-1];
                sumMatrix[i][j] = currSum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int retSum = sumMatrix[row2+1][col2+1] - sumMatrix[row1][col2+1] - sumMatrix[row2+1][col1] + sumMatrix[row1][col1];
        return retSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
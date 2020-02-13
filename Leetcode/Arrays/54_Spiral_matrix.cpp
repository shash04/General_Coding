// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// Example 1:
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// https://leetcode.com/problems/spiral-matrix/

class Solution {    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        
        vector<int> retVec;
        
        int bottom = matrix.size()-1;
        int right = matrix[0].size()-1;
        int left = 0;
        int top = 0;
        
        int dir = 0;
        
        while(left <= right && top <= bottom)
        {
            switch(dir)
            {
                case 0:
                    for(int i=left; i<=right; i++)
                    {
                        retVec.push_back(matrix[top][i]);
                    }
                    top++;
                    dir = (dir + 1) % 4;
                    break;

                case 1:
                    for(int i=top; i<=bottom; i++)
                    {
                        retVec.push_back(matrix[i][right]);
                    }
                    right--;
                    dir = (dir + 1) % 4;
                    break;

                case 2:
                    for(int i=right; i>=left; i--)
                    {
                        retVec.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                    dir = (dir + 1) % 4;
                    break;

                case 3:
                    for(int i=bottom; i>=top; i--)
                    {
                        retVec.push_back(matrix[i][left]);
                    }
                    left++;
                    dir = (dir + 1) % 4;
                    break;
            }
        }
        return retVec;
    }
};
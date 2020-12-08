// Given a matrix and a target, return the number of non-empty submatrices that sum to target.

// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate
// that is different: for example, if x1 != x1'.

// Example 1:
// Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
// Output: 4
// Explanation: The four 1x1 submatrices that only contain 0.

// Example 2:
// Input: matrix = [[1,-1],[-1,1]], target = 0
// Output: 5
// Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

// Example 3:
// Input: matrix = [[904]], target = 0
// Output: 0

// Constraints:
// 1 <= matrix.length <= 100
// 1 <= matrix[0].length <= 100
// -1000 <= matrix[i] <= 1000
// -10^8 <= target <= 10^8

// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int result = 0;
        int nR = matrix.size();
        int nC = matrix[0].size();
        
        vector<vector<int>> sumMatrix (nR, vector<int>(nC, 0));
        
        for(int i = 0; i < nR; i++)
            sumMatrix[i][0] = matrix[i][0];
        
        for(int i = 0; i < nR; i++)
        {
            for(int j = 1; j < nC; j++)
            {
                sumMatrix[i][j] = sumMatrix[i][j - 1] + matrix[i][j];
            }
        }
        
        // Move leftCol from 0 to nC and rightCol from leftCol to nC - all combinations of cols
        for(int leftCol = 0; leftCol < nC; leftCol++)
        {
            for(int rightCol = leftCol; rightCol < nC; rightCol++)
            {
                // For every combination of col, get cumumlative sum for rows = sum of sub matrix
                // Check if this sum is equal to target and add to result
                unordered_map<int, int> sumMap;
                sumMap[0] = 1;
                
                int curSum = 0;
                
                // Iterating over all rows for cur leftCol and rightCol
                for(int r = 0; r < nR; r++)
                {
                    // Logic for finding target sum is same as finding subarray sum equal to target
                    // Keep track of cumulative sum in map. If curSum - target was already stored in map,
                    // it means cur sub matrix sum is equal to target. Add sumMap[curSum - target]
                    // to result as it sumMap[curSum - target] = num of occurences of this
                    if(leftCol == 0)
                        curSum += sumMatrix[r][rightCol];
                    else
                        curSum += sumMatrix[r][rightCol] - sumMatrix[r][leftCol - 1];
                    
                    if(sumMap.count(curSum - target))
                        result += sumMap[curSum - target];
                    
                    sumMap[curSum]++;
                }                
            }
        }
        
        return result;
    }
};
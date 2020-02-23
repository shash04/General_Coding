// In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.
// (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
// We may rotate the i-th domino, so that A[i] and B[i] swap values.
// Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.
// If it cannot be done, return -1.

// Example 1:
// Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
// Output: 2
// Explanation: 
// The first figure represents the dominoes as given by A and B: before we do any rotations.
// If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.

// Example 2:
// Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
// Output: -1
// Explanation: 
// In this case, it is not possible to rotate the dominoes to make one row of values equal.
 
// Note:
// 1 <= A[i], B[i] <= 6
// 2 <= A.length == B.length <= 20000

// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

/* Algorithm :
1) Pick up the first element. It has two sides: A[0] and B[0].
2) Check if one could make all elements in A row or B row to be equal to A[0].
    If yes, return the minimum number of rotations needed.
3) Check if one could make all elements in A row or B row to be equal to B[0].
    If yes, return the minimum number of rotations needed.
4) Otherwise return -1.
*/

class Solution {
    int countRotations(int x, vector<int>& A, vector<int>& B)
    {
        // how many rotations should be done
        // to have all elements in A equal to x
        // and to have all elements in B equal to x
        int rotationsA = 0, rotationsB = 0;
        
        for(int i=0; i < A.size(); i++)
        {
            if(A[i] != x && B[i] != x)
                return -1;
            else if(A[i] != x)
                rotationsA++;
            else if(B[i] != x)
                rotationsB++;
        }
        
        return min(rotationsA, rotationsB);
    }
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.size() != B.size())
            return -1;
        
        int rotations = countRotations(A[0], A, B);
        
        if(rotations != -1 || A[0] == B[0])
            return rotations;
        else
            rotations = countRotations(B[0], A, B);
        
        return rotations;
    }
};
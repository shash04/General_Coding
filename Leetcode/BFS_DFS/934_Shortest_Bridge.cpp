// In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

// Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

// Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

// Example 1:
// Input: A = [[0,1],[1,0]]
// Output: 1

// Example 2:
// Input: A = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2

// Example 3:
// Input: A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1
 
// Constraints:
// 2 <= A.length == A[0].length <= 100
// A[i][j] == 0 or A[i][j] == 1

// https://leetcode.com/problems/shortest-bridge/

// **********************************************************************************************************************
// Concept = Paint one island with number 2, and then keep expanding the boundaries with color + 1 till island 1 is hit
// Nice explanation with diagrams :
// https://leetcode.com/problems/shortest-bridge/discuss/189293/C%2B%2B-BFS-Island-Expansion-%2B-UF-Bonus
// **********************************************************************************************************************

class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int nR, nC;
    
    void paint(vector<vector<int>>& A, int r, int c)
    {
        A[r][c] = 2;
        
        for(auto& dir : dirs)
        {
            int R = r + dir.first;
            int C = c + dir.second;
            
            if(R < 0 || R >= nR || C < 0 || C >= nC || A[R][C] != 1)
                continue;
            
            paint(A, R, C);
        }
    }
    
    bool expand(vector<vector<int>>& A, int r, int c, int color)
    {
        for(auto& dir : dirs)
        {
            int R = r + dir.first;
            int C = c + dir.second;
            
            if(R < 0 || R >= nR || C < 0 || C >= nC)
                continue;
            
            if(A[R][C] == 1)
                return true;
            
            if(A[R][C] == 0)
                A[R][C] = color + 1;
        }
        
        return false;
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        if(A.size() == 0 || A[0].size() == 0)
            return 0;
        
        nR = A.size();
        nC = A[0].size();
        
        bool paintedOneIsland = false;
        
        // Find one island and paint it to color 2
        for(int i = 0; i < nR && !paintedOneIsland; i++)
        {
            for(int j = 0; j < nC && !paintedOneIsland; j++)
            {
                if(A[i][j] == 1)
                {
                    paint(A, i, j);
                    paintedOneIsland = true;
                }
            }
        }
        
        // Starting with color 2, for every iteration, paint the boundaries of island 2, 3, 4, ...
        // As soon as island with 1 is reached, return color - 2
        int color = 2;
        
        while(1)
        {
            for(int i = 0; i < nR; i++)
            {
                for(int j = 0; j < nC; j++)
                {
                    if(A[i][j] == color && expand(A, i, j, color))
                        return color - 2;
                }
            }
            color++;
        }
        
        return 1;
    }
};
// Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

// The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

// A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).

// Example 1:
// Input: [[5,4,5],[1,2,6],[7,4,6]]
// Output: 4
// Explanation: 
// The path with the maximum score is highlighted in yellow. 

// Example 2:
// Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
// Output: 2

// Example 3:
// Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
// Output: 3

// Note:
// 1 <= R, C <= 100
// 0 <= A[i][j] <= 10^9

// https://leetcode.com/problems/path-with-maximum-minimum-value/

class Solution {
    int nR, nC;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        if(A.size() == 0 || A[0].size() == 0)
            return -1;
        
        nR = A.size();
        nC = A[0].size();
        
        int maxScoreResult = A[0][0];
        
        vector<vector<bool>> visited (nR, vector<bool>(nC, false));
        
        priority_queue<tuple<int, int, int>> pq;
        
        pq.push(make_tuple(A[0][0], 0, 0));
        visited[0][0] = true;
        
        while(!pq.empty())
        {
            auto [val, r, c] = pq.top();
            pq.pop();
            
            maxScoreResult = min(maxScoreResult, val);
            
            if(r == nR - 1 && c == nC - 1)
                break;
            
            for(auto& dir : dirs)
            {
                int R = r + dir.first;
                int C = c + dir.second;
                
                if(R < 0 || R >= nR || C < 0 || C >= nC || visited[R][C])
                    continue;
                
                visited[R][C] = true;
                
                pq.push(make_tuple(A[R][C], R, C));
            }
        }
        
        return maxScoreResult;
    }
};
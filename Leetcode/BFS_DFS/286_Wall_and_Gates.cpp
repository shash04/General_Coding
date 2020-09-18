// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF
// as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

// Example: 

// Given the 2D grid:

// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF

// After running your function, the 2D grid should be:

//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4

//   https://leetcode.com/problems/walls-and-gates/

class Solution {
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int nR, nC;

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0 || rooms[0].size() == 0)
            return;
        
        nR = rooms.size();
        nC = rooms[0].size();
        
        int curDist = 1;
        
        queue<pair<int, int>> q1;
        
        // Push locations of gates in the queue
        for(int i = 0; i < nR; i++)
        {
            for(int j = 0; j < nC; j++)
            {
                if(rooms[i][j] == 0)
                {
                    q1.push({i, j});
                }
            }
        }
        
        while(!q1.empty())
        {
            int qSize = q1.size();
            
            while(qSize--)    
            {
                int r = q1.front().first;
                int c = q1.front().second;
                q1.pop();
                
                // explore all neighbors for current node
                for(auto& dir : dirs)
                {
                    int R = r + dir.first;
                    int C = c + dir.second;
                    
                    // conditions for not visiting the neighbor
                    if(R < 0 || R >= nR || C < 0 || C >= nC || rooms[R][C] != INT_MAX)
                        continue;
                    
                    // distance from gate is min of current val and curDist from gate
                    rooms[R][C] = min(rooms[R][C], curDist);
                    
                    // Add to queue
                    q1.push({R, C});
                }
            }
            
            // increment the cur distance from gate
            curDist++;
        }
    }
};
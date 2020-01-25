// In a given grid, each cell can have one of three values:

// the value 0 representing an empty cell;
// the value 1 representing a fresh orange;
// the value 2 representing a rotten orange.
// Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
// If this is impossible, return -1 instead.

// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int nR, nC;
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        nR = grid.size();
        nC = grid[0].size();
        
        queue<pair<int, int>> q1;
        int minutes = 0;
        int freshOranges = 0;
        
        for(int i=0; i<nR; i++)
        {
            for(int j=0; j<nC; j++)
            {
                if(grid[i][j] == 2)
                    q1.push({i,j});
                
                else if(grid[i][j] == 1)
                    freshOranges++;
            }
        }
        
        if(!freshOranges)
            return 0;
        
        BFS(grid, q1, minutes, freshOranges);
        
        if( freshOranges == 0 )
            return minutes - 1;
        
        return -1;
    }
    
    void BFS(vector<vector<int>>& grid, queue<pair<int, int>>& q1, int& minutes, int& freshOranges)
    {
        while(!q1.empty())
        {
            minutes++;
            int qSize = q1.size();
        
            while(qSize--)
            {
                auto currLoc = q1.front();
                q1.pop();
                
                int r = currLoc.first;
                int c = currLoc.second;
                                
                for(auto dir : dirs)
                {
                    int R = r + dir.first;
                    int C = c + dir.second;
                    
                    if(R < 0 || R >= nR || C < 0 || C >= nC || grid[R][C] == 2 || grid[R][C] == 0)
                        continue;
                    
                    grid[R][C] = 2;
                    q1.push({R,C});
                    freshOranges--;
                }
            }
        }
    }
};
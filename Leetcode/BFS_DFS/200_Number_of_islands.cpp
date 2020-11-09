// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed
// by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:
// Input:
// 11110
// 11010
// 11000
// 00000
// Output: 1

// Example 2:
// Input:
// 11000
// 11000
// 00100
// 00011
// Output: 3

// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int totalRows = grid.size();
        if(totalRows <= 0)
            return 0;
        
        int totalCol = grid[0].size();
        int numIslands = 0;
        
        for(int i=0; i<totalRows; i++)
        {
            for(int j=0; j<totalCol; j++)
            {
                if(grid[i][j] == '1')
                {
                    numIslands++;
                    dfs(grid, i, j);
                    // bfs(grid, i, j);
                }
            }
        }
        return numIslands;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        grid[row][col] = '0';
        int totalRows = grid.size();
        int totalCol = grid[0].size();
        
        if(row - 1 >= 0 && grid[row-1][col] == '1')
            dfs(grid, row-1, col);
        
        if(row + 1 < totalRows && grid[row+1][col] == '1')
            dfs(grid, row+1, col);
        
        if(col - 1 >= 0 && grid[row][col-1] == '1')
            dfs(grid, row, col-1);
        
        if(col + 1 < totalCol && grid[row][col+1] == '1')
            dfs(grid, row, col+1);
    }

    // Alternate bfs implementation for same
    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        
        queue<pair<int,int>> q1;
        q1.push({r, c});
        grid[r][c] = '0';
        while(!q1.empty())
        {
            auto curr = q1.front();
            int row = curr.first;
            int col = curr.second;
            q1.pop();
            
            if(row-1 >= 0 && grid[row-1][col] == '1'){
                q1.push({row-1,col});
                grid[row-1][col] = '0';
            }
            if(row+1 < nr && grid[row+1][col] == '1'){
                q1.push({row+1,col});
                grid[row+1][col] = '0';
            }
            if(col-1 >= 0 && grid[row][col-1] == '1'){
                q1.push({row,col-1});
                grid[row][col-1] = '0';
            }
            if(col+1 < nc && grid[row][col+1] == '1'){
                q1.push({row,col+1});
                grid[row][col+1] = '0';
            }
        }
    }
};

// ****************************************************************************
// Solution with use of dirs vector at top
// ****************************************************************************
class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int nR, nC;
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        nR = grid.size();
        nC = grid[0].size();
        
        int numIslands = 0;
        
        for(int i=0; i<nR; i++)
        {
            for(int j=0; j<nC; j++)
            {
                if(grid[i][j] == '1')
                {
                    numIslands++;
                    DFS(grid, i, j);
                    // BFS(grid, i, j);
                }
            }
        }
        
        return numIslands;
    }
    
    void DFS(vector<vector<char>>& grid, int& r, int& c)
    {
        grid[r][c] = '0';
        
        for(auto dir : dirs)
        {
            int R = r + dir.first;
            int C = c + dir.second;
            
            if(R < 0 || R >= nR || C < 0 || C >= nC || grid[R][C] == '0')
                continue;
            
            DFS(grid, R, C);
        }
    }

    void BFS(vector<vector<char>>& grid, int& i, int& j)
    {
        grid[i][j] = '0';
        queue<pair<int, int>> q1;
        q1.push({i, j});
        
        while(!q1.empty())
        {
            int qSize = q1.size();
            
            while(qSize--)
            {
                int r = q1.front().first;
                int c = q1.front().second;
                q1.pop();
                
                for(auto& dir : dirs)
                {
                    int R = r + dir.first;
                    int C = c + dir.second;
                    
                    if(R < 0 || R >= nR || C < 0 || C >= nC || grid[R][C] == '0')
                        continue;
                    
                    grid[R][C] = '0';
                    q1.push({R,C});
                }
            }
        }
    }
};
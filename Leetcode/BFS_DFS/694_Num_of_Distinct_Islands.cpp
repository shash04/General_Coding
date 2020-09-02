// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally
// (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// Count the number of distinct islands. An island is considered to be the same as another if and only if
// one island can be translated (and not rotated or reflected) to equal the other.

// Example 1:
// 11000
// 11000
// 00011
// 00011
// Given the above grid map, return 1.

// Example 2:
// 11011
// 10000
// 00001
// 11011
// Given the above grid map, return 3.

// Notice that:
// 11
// 1
// and
//  1
// 11
// are considered different island shapes, because we do not consider reflection / rotation.

// Note: The length of each dimension in the given grid does not exceed 50.

// https://leetcode.com/problems/number-of-distinct-islands/

// **********************************************************************************************
// Concept - for every island :
// Do DFS and create a Hash of directions taken
// Store this hash in set
// Directions will match for same islands. Thus return set size. 
// **********************************************************************************************
class Solution {
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    set<set<pair<int, int>>> hashRolColSet;
    int nR;
    int nC;
    vector<vector<bool>> visited;
    
    void DFS(vector<vector<int>>& grid, int r, int c, set<pair<int, int>>& currHashSet, int hashR, int hashC)
    {
        visited[r][c] = true;
        
        currHashSet.insert(make_pair(hashR, hashC));
        
        for(auto& dir : dirs)
        {
            int R = r + dir.first;
            int C = c + dir.second;
            
            if(R < 0 || R >= nR || C < 0 || C >= nC || grid[R][C] == 0 || visited[R][C])
                continue;
            
            DFS(grid, R, C, currHashSet, hashR + dir.first, hashC + dir.second);
        }
    }
    
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        nR = grid.size();
        nC = grid[0].size();
        
        visited.resize(nR, vector<bool>(nC, false));
        
        for(int i = 0; i < nR; i++)
        {
            for(int j = 0; j < nC; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    set<pair<int, int>> currHashSet;
                    
                    DFS(grid, i, j, currHashSet, 0, 0);
                    
                    hashRolColSet.insert(currHashSet);
                }
            }
        }
        
        return hashRolColSet.size();
    }
};
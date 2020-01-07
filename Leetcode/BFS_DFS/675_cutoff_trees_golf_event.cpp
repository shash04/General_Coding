// You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:
//     1) 0 represents the obstacle can't be reached.
//     2) 1 represents the ground can be walked through.
//     3) The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.

// You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree
// with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).
// You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all
// the trees. If you can't cut off all the trees, output -1 in that situation.
// You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

// Example 1:
// Input: 
// [
//  [1,2,3],
//  [0,0,0],
//  [7,6,5]
// ]
// Output: -1

// Example 2:
// Input: 
// [
//  [2,3,4],
//  [0,0,5],
//  [8,7,6]
// ]
// Output: 6
// Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.

// https://leetcode.com/problems/cut-off-trees-for-golf-event/

class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest.size() == 0 || forest[0].size() == 0)
            return 0;
        
        // Create a vector of trees to track ones with height > 1
        vector<vector<int>> trees;
        int nR  = forest.size();
        int nC = forest[0].size();
        
        for(int i=0; i<nR; i++)
        {
            for(int j=0; j<nC; j++)
            {
                int height = forest[i][j];
                if(height > 1)
                    trees.push_back( {height, i, j} );
            }
        }
        
        // Sort trees vector according to heights as always cut lowest height tree first
        sort(trees.begin(), trees.end());
        int totalSteps = 0;
        int startRow = 0;
        int startCol = 0;
        
        // Iterate over trees vector as all trees with height > 1 need to be cut
        for(int i=0; i<trees.size(); i++)
        {
            // BFS to find path to next shortest tree
            int curr_steps = navigate(startRow, startCol, trees[i][1], trees[i][2], forest);
            
            // If can't navigate to next tree, all trees can't be cut. Return -1
            if(curr_steps == -1)
                return -1;
            
            totalSteps += curr_steps;
            startRow = trees[i][1];
            startCol = trees[i][2];
        }
        
        return totalSteps;
    }
    
    
    int navigate(int currRow, int currCol, int endRow, int endCol, vector<vector<int>>& forest)
    {
        if(currRow == endRow && currCol == endCol)
            return 0;
        
        int curr_steps = 0;
        int nR = forest.size();
        int nC = forest[0].size();
        
        // Keep track of visited trees i.e. nodes
        vector<vector<int>> visited (nR, vector<int>(nC, 0));
        queue<pair<int, int>> q1;
        
        q1.push( {currRow, currCol} );
        visited[currRow][currCol] = 1;
        
        while(!q1.empty())
        {
            curr_steps++;
            
            // IMPORTANT to copy queue size in variable as its modified inside loop
            int qsize = q1.size(); 
            for(int j=0; j<qsize; j++)
            {
                int r = q1.front().first;
                int c = q1.front().second;
                q1.pop();
                
                for(auto dir : dirs)
                {
                    int R = r + dir.first;
                    int C = c + dir.second;
                    
                    if(R<0 || R>=nR || C<0 || C>=nC || visited[R][C] || forest[R][C]==0)
                        continue;
                    
                    if(R == endRow && C == endCol)
                        return curr_steps;
                    
                    q1.push({R,C});
                    visited[R][C] = true;
                }
            }
        }
        
        return -1;
    }
};
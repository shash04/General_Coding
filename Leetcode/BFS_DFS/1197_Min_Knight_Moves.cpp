// In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

// A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction,
// then one square in an orthogonal direction.

// Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.

// Example 1:
// Input: x = 2, y = 1
// Output: 1
// Explanation: [0, 0] → [2, 1]

// Example 2:
// Input: x = 5, y = 5
// Output: 4
// Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]

// Constraints:
// |x| + |y| <= 300

// https://leetcode.com/problems/minimum-knight-moves/

// *********************************************************************************************************
// Recursive solution with memoization and keeping the co-ordinates always in first quadrant
// recurse from [x,y] to [0,0]. Thus recusive call only with [x-2, y-1] and [x-1, y-2]
// Special case for x + y == 2
// *********************************************************************************************************
class Solution {
    int helper(unordered_map<string, int>& memo, int x, int y)
    {
        // Take absolute value of x and y to keep them in first quadrant
        x = abs(x);
        y = abs(y);
    
        // check if current co-ordinates already visited
        string key = to_string(x) + "," + to_string(y);
        
        if(memo.count(key))
            return memo[key];
        
        // check if reached destination of 0,0
        if(x + y == 0)
            return 0;
        // exception cases - [0,2], [1,1], [2,0] - fastest way to reach is 2 steps
        // but if with abs logic - it will take more
        else if(x + y == 2)
            return 2;
        
        int minSteps = min(helper(memo, x - 1, y - 2), helper(memo, x - 2, y - 1)) + 1;
        
        memo[key] = minSteps;
        return minSteps;
    }
public:
    int minKnightMoves(int x, int y) {      
        if(x == 0 && y == 0)
            return 0;
        
        unordered_map<string, int> memo;
        
        return helper(memo, x, y);
    }
};

// *********************************************************************************************************
// BFS solution - LOGICAL but TLE
// *********************************************************************************************************
class Solution {
    vector<pair<int, int>> moves = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    
public:
    int minKnightMoves(int x, int y) {
        int numMoves = 0;
        
        if(x == 0 && y == 0)
            return numMoves;
        
        queue<pair<int, int>> bfsQ;
        bfsQ.push(make_pair(0, 0));
        
        set<pair<int, int>> visited;
        visited.insert(make_pair(0, 0));
        
        while(!bfsQ.empty())
        {
            int qSize = bfsQ.size();
            
            while(qSize--)
            {
                int r = bfsQ.front().first;
                int c = bfsQ.front().second;
                bfsQ.pop();
                
                for(auto& nextMove : moves)
                {
                    int R = r + nextMove.first;
                    int C = c + nextMove.second;
                    
                    if(visited.count(make_pair(R, C)))
                        continue;
                    
                    if(R == x && C == y)
                        return numMoves + 1;
                    
                    bfsQ.push(make_pair(R, C));
                    visited.insert(make_pair(R, C));
                }
            }
            
            numMoves++;
        }
        
        return numMoves;
    }
};
// According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised
// by the British mathematician John Horton Conway in 1970."

// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with
// its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wiki article):

// Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population..
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// Write a function to compute the next state (after one update) of the board given its current state.
// The next state is created by applying the above rules simultaneously to every cell in the current state,
// where births and deaths occur simultaneously.

// Example:
// Input: 
// [
//   [0,1,0],
//   [0,0,1],
//   [1,1,1],
//   [0,0,0]
// ]
// Output: 
// [
//   [0,0,0],
//   [1,0,1],
//   [0,1,1],
//   [0,1,0]
// ]

// Follow up:
// Could you solve it in-place? Remember that the board needs to be updated at the same time:
// You cannot update some cells first and then use their updated values to update other cells.

// In this question, we represent the board using a 2D array. In principle, the board is infinite,
// which would cause problems when the active area encroaches the border of the array. How would you address these problems?

// https://leetcode.com/problems/game-of-life/

class Solution {
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    int nR, nC;
    
    // Logic to keep track of older state
    // live to dead = 2
    // dead to live = -2

    void applyRules(vector<vector<int>>& board, int r, int c)
    {
        int liveNeighbors = 0;
        int deadNeighbors = 0;
        
        for(auto& dir : dirs)
        {
            int R = r + dir.first;
            int C = c + dir.second;
            
            if(R < 0 || R >= nR || C < 0 || C >= nC)
                continue;
            
            if(board[R][C] == 1 || board[R][C] == 2)
                liveNeighbors++;
            else if(board[R][C] == 0 || board[R][C] == -2)
                deadNeighbors++;
        }
        
        // If current cell is live
        if(board[r][c] == 1)
        {
            if(liveNeighbors < 2 || liveNeighbors > 3)
                board[r][c] = 2;                
        }
        else if(board[r][c] == 0 && liveNeighbors == 3)
        {
            board[r][c] = -2;
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0 && board[0].size() == 0)
            return;
        
        nR = board.size();
        nC = board[0].size();
        
        for(int i = 0; i < nR; i++)
        {
            for(int j = 0; j < nC; j++)
            {
                applyRules(board, i, j);
            }
        }
        
        for(int i = 0; i < nR; i++)
        {
            for(int j = 0; j < nC; j++)
            {
                if(board[i][j] == 2)
                    board[i][j] = 0;
                else if(board[i][j] == -2)
                    board[i][j] = 1;
            }
        }
    }
};

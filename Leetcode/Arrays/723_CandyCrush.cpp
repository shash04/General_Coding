// This question is about implementing a basic elimination algorithm for Candy Crush.

// Given a 2D integer array board representing the grid of candy, different positive integers board[i][j] represent different types of candies.
// A value of board[i][j] = 0 represents that the cell at position (i, j) is empty. The given board represents the state of the game following the player's move.

// Now, you need to restore the board to a stable state by crushing candies according to the following rules:

// If 3 or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the same time - these positions become empty.
// After crushing all candies simultaneously, if an empty space on the board has candies on top of itself,
// then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)
// After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
// If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
// You need to perform the above rules until the board becomes stable, then return the current board.

// https://leetcode.com/problems/candy-crush/

class Solution {
    int nR, nC;
    
    void updateBoard(vector<vector<int>>& board)
    {
        for(int c = 0; c < nC; c++)
        {
            int ptr = nR - 1;
            
            // copy over entries with 0 val
            for(int r = nR - 1; r >= 0; r--)
            {
                if(board[r][c] > 0)
                {
                    board[ptr][c] = board[r][c];
                    ptr--;
                }
            }
            
            // fill top with zeros
            for(int r = ptr; r >= 0; r--)
                board[r][c] = 0;
        }
    }
    
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return {{}};
        
        vector<vector<int>> result;
        
        nR = board.size();
        nC = board[0].size();
        
        while(true)
        {
            bool changed = false;
            
            // Check for matching candies per row
            // NOTE - check for 3 candies together
            for(int r = 0; r < nR; r++)
            {
                for(int c = 0; c < nC - 2; c++)
                {
                    if(board[r][c] == 0)
                        continue;
                    
                    int curVal = abs(board[r][c]);

                    if(curVal == abs(board[r][c+1]) && curVal == abs(board[r][c+2]))
                    {
                        board[r][c] = -curVal;
                        board[r][c+1] = -curVal;
                        board[r][c+2] = -curVal;
                        
                        changed = true;
                    }
                }
            }
            
            // Check for matching candies per col
             // NOTE - check for 3 candies together
            for(int c = 0; c < nC; c++)
            {
                for(int r = 0; r < nR - 2; r++)
                {
                    if(board[r][c] == 0)
                        continue;
                    
                    int curVal = abs(board[r][c]);

                    if(curVal == abs(board[r+1][c]) && curVal == abs(board[r+2][c]))
                    {
                        board[r][c] = -curVal;
                        board[r+1][c] = -curVal;
                        board[r+2][c] = -curVal;
                        
                        changed = true;
                    }
                }
            }
            
            // breaking condition if board is STABLE
            if(changed == false)
                break;
            
            updateBoard(board);
            changed = false;
        }
        
        return board;
    }
};
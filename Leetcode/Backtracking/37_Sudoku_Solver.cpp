// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Empty cells are indicated by the character '.'.

// Note:
// The given board contain only digits 1-9 and the character '.'.
// You may assume that the given Sudoku puzzle will have a single unique solution.
// The given board size is always 9x9.

// https://leetcode.com/problems/sudoku-solver/

class Solution {
    bool validateBoard(const vector<vector<char>>& board, int r, int c, char val)
    {
        // validate all rows for current c
        for(int i = 0; i < 9; i++)
            if(board[i][c] == val)
                return false;
        
        // validate all cols for current r
        for(int j = 0; j < 9; j++)
            if(board[r][j] == val)
                return false;
        
        // Validate sub box
        int subBoxR = r - r % 3;
        int subBoxC = c - c % 3;
        
        for(int i = subBoxR; i < subBoxR + 3; i++)
        {
            for(int j = subBoxC; j < subBoxC + 3; j++)
            {
                if(board[i][j] == val)
                    return false;
            }
        }
        
        // If reached here, it means valid entry - return true
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board, int r, int c)
    {
        // If filled all rows successfully, return true
        if(r == 9)
            return true;
        
        // If filled all cols for current row successfully, return backtrack for row + 1
        if(c == 9)
            return backtrack(board, r + 1, 0);
        
        // If current row and col is for pre-existing entry, skip current col
        if(board[r][c] != '.')
            return backtrack(board, r, c + 1);
        
        // Idea is to try filling numbers col wise for every row by validating the entry
        // If entry is currently valid, modify board and recurse
        // If recursive calls return true - return true
        // If recursive calls return false - backtrack the added entry and try with new number
        for(char n = '1'; n <= '9'; n++)
        {
            if(validateBoard(board, r, c, n))
            {
                board[r][c] = n;
                
                if(backtrack(board, r, c + 1))
                    return true;
                
                board[r][c] = '.';
            }
        }
        
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        // backtrack starting with 0th row and 0th column
        backtrack(board, 0, 0);
    }
};
// Design a Tic-tac-toe game that is played between two players on a n x n grid.
// You may assume the following rules:
// A move is guaranteed to be valid and is placed on an empty block.
// Once a winning condition is reached, no more moves is allowed.
// A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

// Example:
// Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

// TicTacToe toe = new TicTacToe(3);

// toe.move(0, 0, 1); -> Returns 0 (no one wins)
// |X| | |
// | | | |    // Player 1 makes a move at (0, 0).
// | | | |

// toe.move(0, 2, 2); -> Returns 0 (no one wins)
// |X| |O|
// | | | |    // Player 2 makes a move at (0, 2).
// | | | |

// toe.move(2, 2, 1); -> Returns 0 (no one wins)
// |X| |O|
// | | | |    // Player 1 makes a move at (2, 2).
// | | |X|

// toe.move(1, 1, 2); -> Returns 0 (no one wins)
// |X| |O|
// | |O| |    // Player 2 makes a move at (1, 1).
// | | |X|

// toe.move(2, 0, 1); -> Returns 0 (no one wins)
// |X| |O|
// | |O| |    // Player 1 makes a move at (2, 0).
// |X| |X|

// toe.move(1, 0, 2); -> Returns 0 (no one wins)
// |X| |O|
// |O|O| |    // Player 2 makes a move at (1, 0).
// |X| |X|

// toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
// |X| |O|
// |O|O| |    // Player 1 makes a move at (2, 1).
// |X|X|X|

// Follow up:
// Could you do better than O(n2) per move() operation?

// https://leetcode.com/problems/design-tic-tac-toe/

// ****************************************************************************************************
// Faster solution 1 :
// ****************************************************************************************************

class TicTacToe {
public:
    vector<vector<int>> grid;
    int N;
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        N = n;
        grid = vector<vector<int>> (n, vector<int>(n, -1));
    }
    
    bool checkHorizontal(int& row, int& player)
    {
        for(int i=0; i<N; i++)
        {
            if(grid[row][i] != player)
                return false;
        }
        return true;
    }
    
    bool checkVertical(int& col, int& player)
    {
        for(int i=0; i<N; i++)
        {
            if(grid[i][col] != player)
                return false;
        }
        return true;
    }
    
    bool checkDiagonal1(int& row, int& col, int& player)
    {
        if(row != col)
            return false;
        
        for(int i=0; i<N; i++)
        {
            if(grid[i][i] != player)
                return false;
        }
        return true;
    }
    
    bool checkDiagonal2(int& row, int& col, int& player)
    {
        if(row != N-1-col)
            return false;
        
        for(int i=0; i<N; i++)
        {
            if(grid[i][N-1-i] != player)
                return false;
        }
        return true;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        grid[row][col] = player;

        if(checkHorizontal(row, player) ||
           checkVertical(col, player) ||
           checkDiagonal1(row, col, player) ||
           checkDiagonal2(row, col, player))
        {
            return player;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

// ****************************************************************************************************
// Faster solution 2 :
// ****************************************************************************************************

class TicTacToe {
public:
    int N;
    vector<int> rowSum, colSum;
    int d1Sum, d2Sum;
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        N = n;
        rowSum = vector<int> (n, 0);
        colSum = vector<int> (n, 0);
        d1Sum = d2Sum = 0;
    }
    
    int checkSum(int sum)
    {
        // return sum == N ? 2 : (sum == -N ? 1 : 0); 
        if(sum == N)
            return 2;
        else if(sum == -N)
            return 1;
        else
            return 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        // update val will be -1 for player1 and 1 for player2
        int update = 2 * player - 3;
        rowSum[row] += update;
        colSum[col] += update;
        
        if(row == col)
            d1Sum += update;
        if(row == N-1-col)
            d2Sum += update;
        
        // Return bitwise OR of returned values
        return (checkSum(rowSum[row]) | checkSum(colSum[col]) | checkSum(d1Sum) | checkSum(d2Sum));
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */


// ****************************************************************************************************
// Slower solution :
// ****************************************************************************************************

class TicTacToe {
public:
    vector<vector<int>> grid;
    vector<vector<int>> gridCol;
    vector<int> d1;
    vector<int> d2;
    vector<int> p1;
    vector<int> p2;
    int N;
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        N           = n;
        grid        = vector<vector<int>> (n, vector<int>(n, -1));
        gridCol     = vector<vector<int>> (n, vector<int>(n, -1));
        d1          = vector<int> (n, -1);
        d2          = vector<int> (n, -1);
        p1          = vector<int> (n, 1);
        p2          = vector<int> (n, 2);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        grid[row][col] = player;
        gridCol[col][row] = player;

        if(row == col)
            d1[row] = player;
        if(row == N-1-col)
            d2[N-1-col] = player;

        
        for(int i=0; i<N; i++)
        {
            if(grid[i] == p1 || gridCol[i] == p1 || d1 == p1 || d2 == p1)
                return 1;
            if(grid[i] == p2 || gridCol[i] == p2 || d1 == p2 || d2 == p2)
                return 2;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
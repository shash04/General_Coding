// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
// or vertically neighboring. The same letter cell may not be used more than once.

// Example:
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

// https://leetcode.com/problems/word-search/

// Fastest Solution:
class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int nR, nC;
    
    bool exist(vector<vector<char>>& board, string word) {
        nR = board.size();
        nC = board[0].size();
        
        for(int i=0; i<nR; i++)
        {
            for(int j=0; j<nC; j++)
            {
                if(DFS(i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool DFS(int r, int c, vector<vector<char>>& board, string& word, int idx)
    {
        if(idx == word.size())
            return true;
        
        if(r < 0 || r >= nR || c < 0 || c >= nC)
            return false;

        if(word[idx] != board[r][c])
            return false;
        
        char temp = board[r][c];
        board[r][c] = '*';
        
        for(auto dir : dirs)
        {
            int R = r + dir.first;
            int C = c + dir.second;
            
            if(DFS(R, C, board, word, idx+1))
                return true;
        }
        board[r][c] = temp;
        return false;
    }
};

// Alternate - Slower solution
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(!board.size() || !board[0].size() || !word.size())
            return false;
        
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(isWordPresent(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool isWordPresent(vector<vector<char>>& board, string word, int i, int j, int index)
    {
        int rows = board.size();
        int cols = board[0].size();
        
        if(index >= word.size() || board[i][j] != word[index])
            return false;
        
        if(index == word.size()-1)
            return true;
        
        char temp = board[i][j];
        board[i][j] = '*';
        bool result = false;
        
        if(!result && i+1 < rows)
            result = isWordPresent(board, word, i+1, j, index+1);
        if(!result && i-1 >= 0)
            result = isWordPresent(board, word, i-1, j, index+1);
        if(!result && j+1 < cols)
            result = isWordPresent(board, word, i, j+1, index+1);
        if(!result && j-1 >= 0)
            result = isWordPresent(board, word, i, j-1, index+1);
        
        board[i][j] = temp;
        
        return result;
    }
};

// ************************************************************************************************************
// Alternate solution. Slowest
// ************************************************************************************************************
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || word.size() == 0)
            return false;
        
        int rows = board.size();
        int cols = board[0].size();
        bool ans = false;
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                isWordPresent(board, word, "", i, j, 0, ans);
                if(ans)
                    return ans;
            }
        }
        return ans;
    }
    
    void isWordPresent(vector<vector<char>>& board, string word, string curr_word, int i, int j, int pos, bool& ans)
    {
        curr_word += board[i][j];
        
        if(pos >= word.size() || curr_word[pos] != word[pos])
            return;
        
        char temp = board[i][j];
        board[i][j] = '-1';
        
        if(curr_word == word)
        {
            ans = true;
            return;
        }
        
        int rows = board.size();
        int cols = board[0].size();
        
        if(!ans && i+1<rows && board[i+1][j] != '-1')
            isWordPresent(board, word, curr_word, i+1, j, pos+1, ans);
        if(!ans && i-1>=0 && board[i-1][j] != '-1')
            isWordPresent(board, word, curr_word, i-1, j, pos+1, ans);
        if(!ans && j+1<cols && board[i][j+1] != '-1')
            isWordPresent(board, word, curr_word, i, j+1, pos+1, ans);
        if(!ans && j-1>=0 && board[i][j-1] != '-1')
            isWordPresent(board, word, curr_word, i, j-1, pos+1, ans);
        
        board[i][j] = temp;
    }
};
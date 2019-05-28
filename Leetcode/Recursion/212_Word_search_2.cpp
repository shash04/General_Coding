// Given a 2D board and a list of words from the dictionary, find all words in the board.
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
// or vertically neighboring. The same letter cell may not be used more than once in a word.

// Example:
// Input: 
// board = [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// words = ["oath","pea","eat","rain"]

// Output: ["eat","oath"]

// Note:
// All inputs are consist of lowercase letters a-z.
// The values of words are distinct.

// https://leetcode.com/problems/word-search-ii/

// Optimal Trie aaproach solution
class Solution {
public:
    const static int NUM_CHILDREN = 26;
    struct TrieNode
    {
        TrieNode* children[NUM_CHILDREN];
        bool endOfWord;
    };
    
    TrieNode* createNode(void)
    {
        TrieNode* newNode = new TrieNode;
        for(int i=0; i<NUM_CHILDREN; i++)
        {
            newNode->children[i] = NULL;
        }
        newNode->endOfWord = false;
        return newNode;
    }
    
    void addWord(TrieNode* root, string str)
    {
        TrieNode* iter = root;
        for(int i=0; i<str.size(); i++)
        {
            int index = str[i] - 'a';
            if(!iter->children[index])
                iter->children[index] = createNode();
            iter = iter->children[index];
        }
        iter->endOfWord = true;
    }
    
    void findAllWords(vector<vector<char>>& board, TrieNode* root, int x, int y, string curr_str, set<string>& resultSet)
    {
        // Check if out of bounds or already visited
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == ' ')
            return;
        
        // Check if curr char exists in trie
        int index = board[x][y] - 'a';
        if(root->children[index] != NULL)
        {
            curr_str    += board[x][y];
            char c_temp = board[x][y];                      // Store for restoring after current DFS call
            board[x][y] = ' ';                              // To mark as already visited
            
            if(root->children[index]->endOfWord == true)    // Word found in dict
                resultSet.insert(curr_str);
            
            root = root->children[index];                   // Update root ptr
            
            findAllWords(board, root, x+1, y, curr_str, resultSet);
            findAllWords(board, root, x-1, y, curr_str, resultSet);
            findAllWords(board, root, x, y+1, curr_str, resultSet);
            findAllWords(board, root, x, y-1, curr_str, resultSet);
            
            board[x][y] = c_temp;
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Create a trie structure from words dict
        TrieNode* root = createNode();
        for(auto i : words)
            addWord(root, i);
        
        // DFS for every element in board to look for matching word in trie
        set<string> resultSet;
        vector<string> resultVec;
        for(int x=0; x<board.size(); x++)
        {
            for(int y=0; y<board[0].size(); y++)
            {
                string curr_str = "";
                findAllWords(board, root, x, y, curr_str, resultSet);
            }
        }
        
        for(auto word : resultSet)
            resultVec.push_back(word);
        return resultVec;
    }
};

// ***************************************************************************************************************************
// Alternate DFS approach, but VERY SLOW. EXCEEDS TIME LIMIT
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> resultSet;
        vector<string> resultVec;
        unordered_set<string> wordSet;

        for(auto i : words)
            wordSet.insert(i);
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                set<pair<int, int>> m1;
                string curr_str = "";
                DFS(board, wordSet, resultSet, m1, curr_str, i, j);
            }
        }
        for(auto word : resultSet)
            resultVec.push_back(word);
        return resultVec;
    }
    
    void DFS(vector<vector<char>>& board, unordered_set<string>& wordSet , set<string>& resultSet, set<pair<int, int>> m1, string curr_str, int i, int j)
    {
        int rLimit = board.size();
        int cLimit = board[0].size();
        if(m1.find({i,j}) != m1.end())
            return;
        else
            m1.insert({i,j});
        
        curr_str += board[i][j];
        
        if(wordSet.find(curr_str) != wordSet.end())
        {
            resultSet.insert(curr_str);
            return;
        }

        if(i-1 >= 0)
            DFS(board, wordSet, resultSet, m1, curr_str, i-1, j);
        if(i+1 < rLimit)
            DFS(board, wordSet, resultSet, m1, curr_str, i+1, j);
        if(j-1 >= 0)
            DFS(board, wordSet, resultSet, m1, curr_str, i, j-1);
        if(j+1 < cLimit)
            DFS(board, wordSet, resultSet, m1, curr_str, i, j+1);
    }
};
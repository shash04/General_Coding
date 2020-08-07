// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a-z or '.'
// A '.' means it can represent any one letter.

// Example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true

// Note:
// You may assume that all words are consist of lowercase letters a-z.

// https://leetcode.com/problems/add-and-search-word-data-structure-design/

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
};

class WordDictionary {
    // Create a root for the trie
    TrieNode* root;
    
    // Overload function to search word
    bool searchTrie(string word, TrieNode* iter)
    {
        // iterate over the word to check for every char
        for(int i=0; i < word.size(); i++)
        {
            char currChar = word[i];
            if(currChar != '.')
            {
                if(iter->children.count(currChar) == 0)
                    return false;
                else
                    iter = iter->children[currChar];
            }
            else
            {
                // Replace '.' with every char and check if children[c] exists
                // If yes - move the iter to that node and recursively call the function for substr
                // Return true if match found or keep looking
                for(char c = 'a'; c <= 'z'; c++)
                {
                    if(iter->children.count(c))
                    {
                        if(searchTrie(word.substr(i+1), iter->children[c]))
                            return true;
                    }
                }
                
                // None of the chars replaced has further node children - return false
                return false;
            }
        }
        
        // check if its end of word as Trie may have further chars than end of word
        return iter->endOfWord;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
        root->endOfWord = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* iter = root;
        
        for(char& c : word)
        {
            if(!iter->children.count(c))
            {
                TrieNode* newNode = new TrieNode();
                newNode->endOfWord = false;
                iter->children[c] = newNode;
                iter = newNode;
            }
            else
            {
                iter = iter->children[c];
            }
        }
        
        iter->endOfWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchTrie(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
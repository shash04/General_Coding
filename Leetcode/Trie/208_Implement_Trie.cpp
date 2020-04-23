// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
    struct TrieNode
    {
        unordered_map<char, TrieNode*> children;
        bool endOfWord;
    };
    
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
        root->endOfWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* iter = root;
        
        for(char& c : word)
        {
            if(iter->children.find(c) == iter->children.end())
            {
                TrieNode* newNode = new TrieNode;
                newNode->endOfWord = false;
                
                iter->children.insert({c, newNode});
            }
            iter = iter->children[c];
        }
        iter->endOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {        
        TrieNode* iter = root;
        
        for(char& c : word)
        {
            if(iter->children.find(c) == iter->children.end())
                return false;
            
            iter = iter->children[c];
        }
        
        return iter->endOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* iter = root;
        
        for(char& c : prefix)
        {
            if(iter->children.find(c) == iter->children.end())
                return false;
            
            iter = iter->children[c];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// Given a list of strings words representing an English Dictionary, find the longest word in words that can be
// built onecharacterat a time by other words in words. If there is more than one possible answer, return the
// longest word with the smallest lexicographical order.
// If there is no answer, return the empty string.

// Example 1:
// Input: 
// words = ["w","wo","wor","worl", "world"]
// Output: "world"
// Explanation: 
// The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

// Example 2:
// Input: 
// words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// Output: "apple"
// Explanation: 
// Both "apply" and "apple" can be built from other words in the dictionary.
// However, "apple" is lexicographically smaller than "apply".

// Note:
// All the strings in the input will only contain lowercase letters.
// The length of words will be in the range [1, 1000].
// The length of words[i] will be in the range [1, 30].

// https://leetcode.com/problems/longest-word-in-dictionary/

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
            newNode->children[i] = NULL;
        newNode->endOfWord = false;
        return newNode;
    }
    
    void insertWord(TrieNode* root, string str)
    {
        TrieNode* iter = root;
        
        for(int i=0; i<str.length(); i++)
        {
            int index = str[i] - 'a';
            if(!iter->children[index])
                iter->children[index] = createNode();
            iter = iter->children[index];
        }
        iter->endOfWord = true;
    }
    
    string getLongestWord(TrieNode* root)
    {
        string retStr = "";
        int maxLen = 0;
        getLongestWordHelper(root, "", 0, retStr, maxLen);
        return retStr;
    }
    
    void getLongestWordHelper(TrieNode* root, string curr_str, int curr_len, string& retStr, int& maxLen)
    {
        for(int i=0; i<NUM_CHILDREN; i++)
        {
            if(!root->children[i])
                continue;
            
            if(root->children[i]->endOfWord)
            {
                curr_len++;
                curr_str += (char)(i + 'a');
                
                if(curr_len > maxLen)
                {
                    maxLen = curr_len;
                    retStr = curr_str;
                }
                
                getLongestWordHelper(root->children[i], curr_str, curr_len, retStr, maxLen);
                
                curr_len--;
                curr_str.pop_back();
            }
        }
    }
    
    string longestWord(vector<string>& words) {
        TrieNode* root = createNode();
        
        for(int i=0; i<words.size(); i++)
        {
            insertWord(root, words[i]);
        }
        
        return getLongestWord(root);
    }
};
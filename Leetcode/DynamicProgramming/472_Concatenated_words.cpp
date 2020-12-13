// Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

// Example:
// Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
//  "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

// Note:
// The number of elements of the given array will not exceed 10,000
// The length sum of elements in the given array will not exceed 600,000.
// All the input string will only include lower case letters.
// The returned elements order does not matter.

// https://leetcode.com/problems/concatenated-words/

class Solution {
    bool wordBreak(string& word, unordered_set<string>& wordSet)
    {
        if(word.size() == 0 || wordSet.size() == 0)
            return false;
        
        vector<bool> dp (word.size() + 1, false);
        
        dp[0] = true;
        
        for(int len = 1; len <= word.size(); len++)
        {            
            for(int i = 0; i < len; i++)
            {
                if(dp[i] && wordSet.count(word.substr(i, len - i)))
                {
                    dp[len] = true;
                    break;
                }
            }
        }
        
        return dp[word.size()];
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        
        if(words.size() == 0)
            return result;
        
        unordered_set<string> wordSet (words.begin(), words.end());
        
        for(string& word : words)
        {
            wordSet.erase(word);
            
            if(wordBreak(word, wordSet))
                result.push_back(word);
            
            wordSet.insert(word);
        }
        
        return result;
    }
};
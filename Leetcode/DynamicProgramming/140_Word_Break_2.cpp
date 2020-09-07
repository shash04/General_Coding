// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to
// construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

// Note:
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.

// Example 1:
// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]

// Example 2:
// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.

// Example 3:
// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []

// https://leetcode.com/problems/word-break-ii/

class Solution {
    unordered_map<string, vector<string>> subStrBreakMap;
    unordered_set<string> wordSet;
    
    void populateWordSet(vector<string>& wordDict)
    {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
    }
    
    void addWordToPrev(string& word, vector<string>& prevResult)
    {
        for(int i = 0; i < prevResult.size(); i++)
        {
            prevResult[i] += " " + word;
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(subStrBreakMap.count(s))
            return subStrBreakMap[s];
        
        if(wordSet.size() == 0)
            populateWordSet(wordDict);
        
        vector<string> result;
        
        // whole word is present in word Dict
        if(wordSet.count(s))
            result.push_back(s);
        
        // Starting from index 1, split the string in 2 words
        // check if later part is present in word Dict
        // if yes - call word break for prev part and add the
        // later part to all the entries in the vector returned
        for(int i = 1; i < s.size(); i++)
        {
            string word = s.substr(i);
            
            if(wordSet.count(word))
            {
                string rem = s.substr(0, i);
                vector<string> prevResult = wordBreak(rem, wordDict);
                
                // if combination was not possible, prevResult would return a null vector
                // word won't be added to any entry and the result from this split will be null
                addWordToPrev(word, prevResult);
                
                // Add the prevResult vector to result
                result.insert(result.end(), prevResult.begin(), prevResult.end());
            }
        }
        
        subStrBreakMap[s] = result;
        return result;
    }
};
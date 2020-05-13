// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if
// s can be segmented into a space-separated sequence of one or more dictionary words.

// Note:
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.

// Example 1:
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.

// Example 3:
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false

// https://leetcode.com/problems/word-break/

// Logic: bool vector dp[j] == true indicates that substr till j is present in dict
// check if substr between i-j is present in dict. If yes, dp[i] = true (word segment is present in dict) 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0 || wordDict.size() == 0)
            return false;
        
        unordered_set<string> wordSet (wordDict.begin(), wordDict.end());
        
        vector<bool> dp (s.size() + 1, false);
       
        dp[0] = true;
        
        // Starting with one char go till entire string
        // For every len, split the string into two and check if both parts are in dict
        // dp[i] keeps track of substring from 0 to i. If dp[i] == true : word break till i lies in dict
        for(int len = 1; len <= s.size(); len++)
        {
            for(int i = 0; i < len; i++)
            {
                if(dp[i] && wordSet.count(s.substr(i, len - i)))
                {
                    dp[len] = true;             // Note that if the split satisfies conditions, make dp[len] = true
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};


// *****************************************************************************************************
// Recursive approach with memoization
// *****************************************************************************************************

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0 || wordDict.size() == 0)
            return false;
        
        unordered_map<string , bool> m1;
        
        unordered_set<string> wordSet (wordDict.begin(), wordDict.end());
        
        return helper(s, wordSet, m1);
    }
    
    bool helper(string s, unordered_set<string>& wordSet, unordered_map<string , bool>& m1)
    {
        if(s.size() == 0)
            return  true;
        
        if(m1.count(s))
            return m1[s];
        
        int sSize = s.size();
        
        for(int i=1; i <= sSize; i++)
        {
            if(wordSet.count(s.substr(0, i)) && helper(s.substr(i, sSize - i), wordSet, m1))
            {
                m1[s.substr(i, sSize - i)] = true;
                return true;
            }
        }
        
        m1[s] = false;
        
        return false;
    }
};

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
        if(wordDict.size() == 0)
            return false;
        
        vector<bool> dp (s.size() + 1, false);
        dp[0] = true;
        
        for(int i=1; i<=s.size(); i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(dp[j] == true)
                {
                    string curr_word = s.substr(j, i-j);
                    if(find(wordDict.begin(), wordDict.end(), curr_word) != wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
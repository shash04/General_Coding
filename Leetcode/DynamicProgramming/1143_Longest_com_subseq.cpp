// Given two strings text1 and text2, return the length of their longest common subsequence.

// A subsequence of a string is a new string generated from the original string with some characters(can be none)
// deleted without changing the relative order of the remaining characters.
// (eg, "ace" is a subsequence of "abcde" while "aec" is not).
// A common subsequence of two strings is a subsequence that is common to both strings.

// If there is no common subsequence, return 0.

// Example 1:
// Input: text1 = "abcde", text2 = "akcge" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.

// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ans = 0;
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        
        return LCS(text1, text2, dp);
    }
    
    int LCS(const string& s1, const string& s2, vector<vector<int>>& dp)
    {
        if(s1.size() == 0 || s2.size() == 0)
            return 0;
        
        for(int i=0; i < s1.size(); i++)
        {
            for(int j=0; j < s2.size(); j++)
            {
                // If the chars match : 1 + LCS(s1 - s1[i], s2 - s2[j])
                // Else : max(LCS(s1 - s1[i], s2), LCS(s1, s2 - s2[j]))
                if(s1[i] == s2[j])
                {
                    dp[i+1][j+1] = 1 + dp[i][j];
                }
                else
                {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
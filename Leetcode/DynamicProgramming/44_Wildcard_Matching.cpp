// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Note:
// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like ? or *.

// Example 1:
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.

// Example 3:
// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

// Example 4:
// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

// Example 5:
// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false

// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        
        vector<vector<int>> dp (sLen + 1, vector<int>(pLen + 1, false));
        
        dp[0][0] = true;
        
        // If curr char in p is '*', take value from j - 1
        // Would be true only in cases like p = "*", "**", "****", ...
        for(int j = 1; j <= pLen; j++)
        {
            if(p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }
        
        for(int i = 1; i <= sLen; i++)
        {
            for(int j = 1; j <= pLen; j++)
            {
                // Case 1 - If curr char in s matches with curr char in p OR curr char in p is '?'
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                
                // Case 2 - If curr char in p is '*'
                // a. If '*' is considered as "" (empty seq), take value from dp[i][j-1]
                // b. If '*' is considered as any char, take value from dp[i-1][j]
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        
        return dp[sLen][pLen];
    }
};

// ************************************************************************************************************
// Space optimal 1D DP approach
// ************************************************************************************************************
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        
        // 1D dp - index i indicates the status of s matched with curr substring of p
        vector<int> dp (sLen + 1, false);
        
        dp[0] = true;
        
        for(int j = 1; j <= pLen; j++)
        {
            bool pre = dp[0];
            
            dp[0] = dp[0] && p[j-1] == '*';
            
            for(int i = 1; i <= sLen; i++)
            {
                // Store the curr value in dp before it is updated
                bool temp = dp[i];
                
                // Case 1 - If curr char in s matches with curr char in p OR curr char in p is '?'
                if(p[j-1] != '*')
                {
                    dp[i] = pre && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
                // Case 2 - If curr char in p is '*'
                else
                {
                    dp[i] = dp[i] || dp[i-1];
                }
                
                pre = temp;
            }
        }
        
        return dp[sLen];
    }
};
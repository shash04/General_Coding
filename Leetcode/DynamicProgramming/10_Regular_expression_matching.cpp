// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
// Note:
// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like . or *.

// Example 1:
// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".

// Example 2:
// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

// Example 3:
// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false

// https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        
        vector<vector<int>> dp (sLen + 1, vector<int>(pLen + 1, false));
        
        // Empty string and empty pattern match
        dp[0][0] = true;
        
        // If patter has '*', consider zero occurences of prev char in p.
        // Thus get dp value from j-2
        for(int j=1; j <= pLen; j++)
        {
            if(p[j-1] == '*')
                dp[0][j] = dp[0][j-2];
        }
        
        for(int i=1; i <= sLen; i++)
        {
            for(int j=1; j <= pLen; j++)
            {
                // Case 1 - If curr char in s matches with curr char in p OR curr char in p is '.'
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                
                else if(p[j-1] == '*')
                {
                    // Case 2.a - zero occurences of prev char in p
                    dp[i][j] = dp[i][j-2];
                    
                    // Case 2.b - multiple occurences of prev char in p
                    // e.g p = ab* and s = abb
                    // remove b from s and check if ab* matches with ab -> dp[i-1][j]
                    if(p[j-2] == '.' || s[i-1] == p[j-2])
                        dp[i][j] |= dp[i-1][j];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[sLen][pLen];
    }
};

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
        int sLen = s.length();
        int pLen = p.length();
        
        bool T[sLen+1][pLen+1];
        for(int i=0; i<sLen+1; i++)
        {
            for(int j=0; j<pLen+1; j++)
                T[i][j] = false;
        }
        T[0][0] = true;
        
        for(int j=1; j<pLen+1; j++)         // Deals with patterns like a* or a*b* or a*b*c*
        {
            if(p[j-1] == '*')
                T[0][j] = T[0][j-2];
        }
        
        for(int i=1; i<sLen+1; i++)
        {
            for(int j=1; j<pLen+1; j++)
            {
                if(p[j-1]==s[i-1] || p[j-1] == '.')
                    T[i][j] = T[i-1][j-1];
                else if(p[j-1] == '*')
                {
                    T[i][j] = T[i][j-2];
                    if(p[j-2]=='.' || p[j-2]==s[i-1])
                        T[i][j] |= T[i-1][j];
                }
                else
                    T[i][j] = false;
            }
        }
        return T[sLen][pLen];
    }
};

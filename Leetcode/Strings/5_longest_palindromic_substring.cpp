// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"

// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int sLen = s.size();
        if(sLen < 2)
            return s;
        
        int maxLen = 0;
        int idx = 0;
        int i = 0;
        
        while(i < sLen)
        {
            int lptr = i;
            int rptr = i;
            
             // Skip same characters
            while(rptr < sLen && s[rptr] == s[rptr+1])
                rptr++;
            
            // important to reduce time
            i = rptr + 1;
            
            while(lptr > 0 && rptr < sLen-1 && s[lptr-1] == s[rptr+1])
            {
                lptr--;
                rptr++;
            }
            
            int palLen = rptr - lptr + 1;
            if(palLen > maxLen)
            {
                idx = lptr;
                maxLen = palLen;
            }
        }
        
        return s.substr(idx, maxLen);
    }
};
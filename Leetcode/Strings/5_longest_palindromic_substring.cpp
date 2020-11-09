// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"

// https://leetcode.com/problems/longest-palindromic-substring/

// ***********************************************************************************************************************
// Expand around center approach - faster
// ***********************************************************************************************************************
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


// ***********************************************************************************************************************
// Dynamic Programming approach - slower
// Explanation - https://leetcode.com/problems/longest-palindromic-substring/discuss/151144/Bottom-up-DP-Logical-Thinking
// ***********************************************************************************************************************

class Solution {
public:
    string longestPalindrome(string s) {
        int sLen = s.size();
        if(sLen < 2)
            return s;
        
        vector<vector<bool>> T(sLen , vector<bool>(sLen, false));
        int longestPalLen = 1;
        int longestPalStart = 0;
        
        // Each char by itself is palindrome
        for(int i=0; i<sLen; i++)
        {
            T[i][i] = true;
        }
        
        for(int start=sLen-1; start>=0; start--)
        {
            for(int dist=1; dist<sLen-start; dist++)
            {
                int end = start + dist;
                
                if(dist == 1)
                    T[start][end] = (s[start] == s[end]);
                else
                    T[start][end] = (s[start] == s[end]) && (T[start+1][end-1]);
                
                if(T[start][end] && end - start + 1 > longestPalLen)
                {
                    cout<<start<<" "<<end<<" "<<dist<<endl;
                    longestPalLen = end - start + 1;
                    longestPalStart = start;
                }
            }
        }
        
        return s.substr(longestPalStart, longestPalLen);
    }
};
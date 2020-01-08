// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

// Example 1:
// Input:
// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".

// Example 2:
// Input:
// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb".

// https://leetcode.com/problems/longest-palindromic-subsequence/

// #######################################################################################################################
// Solution 1 : Memoization technique
// #######################################################################################################################
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> mem (n, vector<int> (n, 0));
        
        int maxLen = getMaxPalLenHelper(s, 0, n-1, mem);
        return maxLen;
    }
    
    int getMaxPalLenHelper(string& s, int start, int end, vector<vector<int>>& mem)
    {
        if(start > end)
            return 0;
        
        if(start == end)
                return 1;
        
        if(mem[start][end])
            return mem[start][end];
        
        if(s[start] == s[end])
            mem[start][end] = 2 + getMaxPalLenHelper(s, start+1, end-1, mem);
        else
            mem[start][end] = max(getMaxPalLenHelper(s, start+1, end, mem), getMaxPalLenHelper(s, start, end-1, mem));
        
        return mem[start][end];
    }
};

// #######################################################################################################################
// Solution 2 : DP vector
// #######################################################################################################################
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sLen = s.size();
        if(sLen == 0)
            return 0;
        
        vector<vector<int>> dp (sLen, vector<int> (sLen, 0));
        for(int i=0; i<sLen; i++)
            dp[i][i] = 1;
        
        // subset size will vary from 2 to string length
        for(int k=2; k<=sLen; k++)
        {
            // Start of subset will vary from 0 to string length - subset size + 1
            for(int i=0; i<sLen-k+1; i++)
            {
                // End of subset will be start + subset size - 1
                int j = i + k - 1;
                
                if(k == 2 && s[i] == s[j])                      // Special case of subset size 2
                    dp[i][j] = 2;
                else if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];               // 2 + diagonally opposite element
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);     // max of adjacent values
            }
        }
        
        return dp[0][sLen-1];
    }
};

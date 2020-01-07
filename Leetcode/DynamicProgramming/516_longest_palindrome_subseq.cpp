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
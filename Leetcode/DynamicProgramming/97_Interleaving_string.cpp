// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// Example 1:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true

// Example 2:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

// https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        
        int s1Size = s1.size();
        int s2Size = s2.size();
        
        vector<vector<bool>> dp (s1Size+1, vector<bool>(s2Size+1, false));
        
        // Case 1 : if s1 and s2 both are empty then empty s3 is interleaved
        dp[0][0] = true;
        
        // Case 2 : if s2 is empty
        // curr dp val = curr char match in s1 and s3 && prev val in dp without curr char in s1
        for(int i=0; i<s1Size; i++)
        {
            dp[i+1][0] = dp[i][0] && (s1[i] == s3[i]);
        }
        
        // Case 3 : if s1 is empty
        // curr dp val = curr char match in s2 and s3 && prev val in dp without curr char in s2
        for(int j=0; j<s2Size; j++)
        {
            dp[0][j+1] = dp[0][j] && (s2[j] == s3[j]);
        }
        
        // Case 4 : if both s1 and s2 have valid chars : combination of cases 2 and 3
        // curr dp val = (curr char match in s1 and s3 && prev val in dp without curr char in s1) ||
        //               (curr char match in s2 and s3 && prev val in dp without curr char in s2)
        
        for(int i=0; i<s1Size; i++)
        {
            for(int j=0; j<s2Size; j++)
            {
                dp[i+1][j+1] =  (dp[i][j+1] && (s1[i] == s3[i+j+1])) ||
                                (dp[i+1][j] && (s2[j] == s3[i+j+1]));
            }
        }
        
        return dp[s1Size][s2Size];
    }
};
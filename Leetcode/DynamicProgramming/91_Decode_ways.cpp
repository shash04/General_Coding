// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.

// Example 1:
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).

// Example 2:
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

// https://leetcode.com/problems/decode-ways/

// *****************************************************************************************************
// Recursion with Memoization
// *****************************************************************************************************
class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo (s.size(), -1);
        
        return recursive(s, 0, memo);
    }
    
    int recursive(string& s, int idx, vector<int>& memo)
    {
        if(idx >= s.size())
        {
            return 1;
        }
        
        if(s[idx] - '0' == 0)
            return 0;
        
        if(memo[idx] != -1)
            return memo[idx];

        int currRes = recursive(s, idx + 1, memo);
        
        if(idx + 1 < s.size())
        {
            int num = stoi(s.substr(idx, 2));
            
            if(num >= 10 && num <= 26)
                currRes += recursive(s, idx + 2, memo);
        }
        
        memo[idx] = currRes;
        
        return memo[idx];
    }
};

// *****************************************************************************************************
// Dynamic Programming
// *****************************************************************************************************
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;
        
        vector<int> dp (s.size() + 1, 0);
        
        dp[0] = 1;
        
        // If single digit string, there will be one combination if the num is non zero
        dp[1] = (s[0] == '0') ? 0 : 1;
        
        for(int i = 2; i < s.size() + 1; i++)
        {
            // If non zero number then add value from prev
            if(s[i-1] != '0')
                dp[i] += dp[i - 1];
            
            // Check for two digit numbers
            int num = stoi(s.substr(i - 2, 2));
            
            if(num >= 10 && num <= 26)
                dp[i] += dp[i - 2];
        }
        
        return dp[s.size()];
    }
};
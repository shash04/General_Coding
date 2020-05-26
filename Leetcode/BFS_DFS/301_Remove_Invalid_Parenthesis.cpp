// Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

// Note: The input string may contain letters other than the parentheses ( and ).

// Example 1:
// Input: "()())()"
// Output: ["()()()", "(())()"]

// Example 2:
// Input: "(a)())()"
// Output: ["(a)()()", "(a())()"]

// Example 3:
// Input: ")("
// Output: [""]

// https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // There are multiple ways to reach the valid string
        // Using set avoids adding duplicates
        unordered_set<string> result;
        
        // left keeps track of unmatched left brackets
        // right keeps track of unmatched right brackets
        // left + right = brackets that need to be removed to get ans vec
        int left = 0;
        int right = 0;
        
        for(int i=0; i < s.size(); i++)
        {
            if(s[i] == '(')
                left++;
            else if(s[i] == ')')
            {
                if(left == 0)
                    right++;
                else
                    left--;
            }
        }
        
        recursive(result, s, 0, "", 0, left, right);
        
        return vector<string>(result.begin(), result.end());
    }
    
    void recursive(unordered_set<string>& result, string& s, int idx, string currStr, int openPair, int left, int right)
    {
        if(idx == s.size())
        {
            // Add to result only if left and right unmatched are all deleted and valid parenthesis as Open Pair is zero 
            if(left == 0 && right == 0 && openPair == 0)
                result.insert(currStr);
            return;
        }
        
        // If curr char is not a bracket, add to currStr and recurse
        if(s[idx] != '(' && s[idx] != ')')
        {
            return recursive(result, s, idx + 1, currStr + s[idx], openPair, left, right);
        }
        
        if(s[idx] == '(')
        {
            // Don't include the opening bracket
            if(left > 0)
                recursive(result, s, idx + 1, currStr, openPair, left - 1, right);
            
            // Include the opening bracket
            recursive(result, s, idx + 1, currStr + s[idx], openPair + 1, left, right);
        }
        
        else if(s[idx] == ')')
        {
            // Don't include the closing bracket
            if(right > 0)
                recursive(result, s, idx + 1, currStr, openPair, left, right - 1);
            
            // Include the closing bracket only if open Pair - there is unclosed open bracket
            if(openPair > 0)
               recursive(result, s, idx + 1, currStr + s[idx], openPair - 1, left, right);
        } 
    }
};
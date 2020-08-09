// Given a string s of '(' , ')' and lowercase English characters. 

// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

// Formally, a parentheses string is valid if and only if:

// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.

// Example 1:
// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

// Example 2:
// Input: s = "a)b(c)d"
// Output: "ab(c)d"

// Example 3:
// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.

// Example 4:
// Input: s = "(a(b(c)d)"
// Output: "a(b(c)d)"
 

// Constraints:
// 1 <= s.length <= 10^5
// s[i] is one of  '(' , ')' and lowercase English letters.

// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Stack to keep track of open bracket index
        stack<int> openS;
        
        // set to know which chars to drop in O(1) time
        unordered_set<int> idxToRemove;
        
        // answer string
        string ans;
        
        for(int i=0; i < s.size(); i++)
        {
            // Add opening bracket index to stack
            if(s[i] == '(')
                openS.push(i);
            
            if(s[i] == ')')
            {
                // If stack is empty and closing bracket, it needs to be removed
                // Else remove opening bracket index from top as pair formed
                if(openS.empty())
                    idxToRemove.insert(i);
                else
                    openS.pop();
            }
        }
        
        // All the unmatched opening brackets need to be removed
        while(!openS.empty())
        {
            idxToRemove.insert(openS.top());
            openS.pop();
        }
        
        // Build answer string
        for(int i = 0; i < s.size(); i++)
        {
            if(idxToRemove.count(i))
                continue;
            
            ans += s[i];
        }
        
        return ans;
    }
};
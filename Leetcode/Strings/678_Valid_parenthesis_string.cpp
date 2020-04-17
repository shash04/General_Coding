// Given a string containing only three types of characters: '(', ')' and '*',
// write a function to check whether this string is valid.

// We define the validity of a string by these rules:
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
// An empty string is also valid.

// Example 1:
// Input: "()"
// Output: True

// Example 2:
// Input: "(*)"
// Output: True

// Example 3:
// Input: "(*))"
// Output: True

// Note:
// The string size will be in the range [1, 100].

// https://leetcode.com/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0;
        int cmax = 0;
        
        for(char& c : s)
        {
            if(c == '(')
            {
                cmin++;
                cmax++;
            }
            else if(c == ')')
            {
                cmin--;
                cmax--;
            }
            else if(c == '*')
            {
                cmin--;         // if '*' is considered as ')'
                cmax++;         // if '*' is considered as '('
            }
            
            if(cmax < 0)
                return false;
            
            cmin = max(cmin, 0);    // if cmin is -ve consider '*' as empty string and thus cmin = 0
        }
        
        return cmin == 0;
    }
};
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==')' || s[i]==']' || s[i]=='}')
            {
                if(par.empty() || !isValidClosing(s[i], par))
                    return false;
                else
                    par.pop();
            }
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                par.push(s[i]);
            }
        }
        
        if(par.empty())
            return true;
        else
            return false;
    }
    
    bool isValidClosing(const char &closing, const stack<char> &par)
    {
        char opening = par.top();
        if(opening == '(' && closing == ')')
            return true;
        if(opening == '[' && closing == ']')
            return true;
        if(opening == '{' && closing == '}')
            return true;
        return false;
    }
};
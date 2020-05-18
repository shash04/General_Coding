// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        
        for(char& c : s)
        {
            if(c == '(' || c == '[' || c == '{')
                s1.push(c);
            
            else if(c == ')' || c == ']' || c == '}')
            {
                if(s1.empty())
                    return false;
                
                if(!checkIfValidClosing(s1.top(), c))
                    return false;
                
                s1.pop();
            }
        }
        
        if(!s1.empty())
            return false;
        
        return true;
    }
    
    bool checkIfValidClosing(char& open, char& close)
    {
        if((open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}'))
            return true;
        
        return false;
    }
};

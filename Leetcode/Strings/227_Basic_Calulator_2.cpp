// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces.
// The integer division should truncate toward zero.

// Example 1:
// Input: "3+2*2"
// Output: 7

// Example 2:
// Input: " 3/2 "
// Output: 1

// Example 3:
// Input: " 3+5 / 2 "
// Output: 5

// Note:
// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.

// https://leetcode.com/problems/basic-calculator-ii/

// **********************************************************************************
// Using for loop
// **********************************************************************************
class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        
        int result = 0;
        
        stack<int> numStack;
        
        int currNum = 0;
        char sign = '+';
        
        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                currNum = currNum * 10 + (s[i] - '0');
            }
            
            if(!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1)
            {
                if(sign == '+')
                    numStack.push(currNum);
                else if(sign == '-')
                    numStack.push(-currNum);
                else
                {
                    int tmp = numStack.top();
                    numStack.pop();
                    
                    if(sign == '*')
                        tmp *= currNum;
                    else if(sign == '/')
                        tmp /= currNum;
                    
                    numStack.push(tmp);
                }
                
                sign = s[i];
                currNum = 0;
            }
        }
        
        while(!numStack.empty())
        {
            result += numStack.top();
            numStack.pop();
        }
        
        return result;
    }
};

// **********************************************************************************
// Using istringstream
// **********************************************************************************

class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        
        int result = 0;
        
        stack<int> numStack;
        
        int currNum = 0;
        char sign = '+';
        
        istringstream iss(s);
        
        while(iss >> currNum)
        {
            if(sign == '+')
                numStack.push(currNum);
            else if(sign == '-')
                numStack.push(-currNum);
            else
            {
                int tmp = numStack.top();
                numStack.pop();

                if(sign == '*')
                    tmp *= currNum;
                else if(sign == '/')
                    tmp /= currNum;

                numStack.push(tmp);
            }
            
            iss >> sign;
        }
        
        while(!numStack.empty())
        {
            result += numStack.top();
            numStack.pop();
        }
        
        return result;
    }
};
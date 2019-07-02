// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// Example 1:
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"

// Example 2:
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

// https://leetcode.com/problems/longest-valid-parentheses/

// Logic: For every '(' encountered, we push its index onto the stack.
// For every ')' encountered, we pop the topmost element and subtract the current element's index
// from the top element of the stack, which gives the length of the currently encountered valid
// string of parentheses. If while popping the element, the stack becomes empty, we push the current
// element's index onto the stack. In this way, we keep on calculating the lengths of the valid
// substrings, and return the length of the longest valid string at the end.

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indices;
        int maxLen = 0;
        indices.push(-1);
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
                indices.push(i);
            else
            {
                indices.pop();
                if(indices.empty())
                    indices.push(i);
                else
                    maxLen = max(maxLen, i - indices.top());
            }
        }
        return maxLen;
    }
};
// Given a balanced parentheses string S, compute the score of the string based on the following rule:
// () has score 1
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.

// Example 1:
// Input: "()"
// Output: 1

// Example 2:
// Input: "(())"
// Output: 2

// Example 3:
// Input: "()()"
// Output: 2

// Example 4:
// Input: "(()(()))"
// Output: 6

// Note:
// S is a balanced parentheses string, containing only ( and ).
// 2 <= S.length <= 50

// https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s1;
        int currSum = 0;

        for(int i=0; i<S.size(); i++)
        {
            if(S[i] == '(')
            {
                s1.push(currSum);
                currSum = 0;
            }
            else
            {
                currSum += s1.top() + max(currSum, 1);
                s1.pop();
            }
        }

        return currSum;
    }
};
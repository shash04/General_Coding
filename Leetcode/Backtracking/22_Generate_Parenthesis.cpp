// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return {};
        
        vector<string> retVec;
        genParenthesisHelper(retVec, "", 0, 0, n);
        return retVec;
    }
    
    void genParenthesisHelper(vector<string>& retVec, string currStr, int open, int close, int& n)
    {
        if(currStr.size() == 2 * n)
        {
            retVec.push_back(currStr);
            return;
        }
        
        if(open < n)
            genParenthesisHelper(retVec, currStr + "(", open+1, close, n);
        
        if(close < open)
            genParenthesisHelper(retVec, currStr + ")", open, close+1, n);
    }
};

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
        vector<string> ret;
        genPar(ret, "", n, 0);
        return ret;
    }
    
    void genPar(vector<string> &vec, string str, int n, int m)
    {
        if(n==0 && m==0) {
            vec.push_back(str);
            return;
        }
        if(m > 0)
            genPar(vec, str + ")", n, m-1);
        if(n > 0)
            genPar(vec, str + "(", n-1, m+1);
    }
};

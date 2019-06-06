// Given a string S, we can transform every letter individually to be lowercase or uppercase to
// create another string.  Return a list of all possible strings we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]

// https://leetcode.com/problems/letter-case-permutation/

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        permutationHelper(S, ans,  0);
        return ans;
    }
    
    void permutationHelper(string str, vector<string>& ans, int i)
    {
        if(i == str.size())
        {
            ans.push_back(str);
            return;
        }
        
        permutationHelper(str, ans, i+1);
        
        // If the char is alphabet, flip its case and backtrack
        if(isalpha(str[i]))
        {
            str[i] = islower(str[i]) ? toupper(str[i]) : tolower(str[i]);
            permutationHelper(str, ans, i+1);
        }
    }
};
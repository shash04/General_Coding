// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example:
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size())
            return {};
        
        // Create a map data structure for generating combinations
        unordered_map<int, string> dc = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> result;

        getCombinations(dc, digits, result, "", 0);
        
        return result;
    }
    
    void getCombinations(unordered_map<int, string>& dc, string digits, vector<string>& result, string curr_str, int pos)
    {
        // If reached to last point after recursion
        if(pos == digits.size())
            result.push_back(curr_str);
        
        int curr_digit = (int)(digits[pos] - '0');
        
        // For each char for curr_digit, recursively call same function. Remove the char in the end and repeat.
        for(int i=0; i<dc[curr_digit].size(); i++)
        {
            curr_str += dc[curr_digit][i];
            getCombinations(dc, digits, result, curr_str, pos+1);
            curr_str.pop_back();
        }
    }
};
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// Find all strobogrammatic numbers that are of length = n.
// Example:
// Input:  n = 2
// Output: ["11","69","88","96"]

// https://leetcode.com/problems/strobogrammatic-number-ii/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return findAnsUtil(n, n);
    }
    
    vector<string> findAnsUtil(int m, int n)
    {
        vector<string> v1;
        if(m == 0)
        {
            v1.push_back("");
            return v1;
        }
        if(m == 1)
        {
            v1 = {{'0'}, {'1'}, {'8'}};
            return v1;
        }
        
        vector<string> curr = findAnsUtil(m-2, n);
        vector<string> ret;

        for(int i=0; i<curr.size(); i++)
        {
            if(m != n)
                ret.push_back("0" + curr[i] + "0");     // Middle chars can be 0. Applicable only for recursive calls
            ret.push_back("1" + curr[i] + "1");
            ret.push_back("6" + curr[i] + "9");
            ret.push_back("8" + curr[i] + "8");
            ret.push_back("9" + curr[i] + "6");
        }
        return ret;
    }
};

// Alternate Backtracking solution
class Solution 
{
    vector<int> first = {0, 1, 6, 8, 9}, second = {0, 1, 9, 8, 6};
public:
    vector<string> findStrobogrammatic(int n) 
    {
        vector<string> res;
        string s (n, '0');
        helper(res, s, 0, s.size() / 2);
        return res;
    }
    
    void helper(vector<string>& res, string& s, int digit_start, int upper_border)
    {
        if (digit_start == upper_border)
        {
            res.push_back(s);
            if (s.size() == digit_start * 2)
                return;
            s[digit_start] = '1';
            res.push_back(s);
            s[digit_start] = '8';
            res.push_back(s);
            s[digit_start] = '0';
            return;
        }
        
        int mask_start = (digit_start == 0) ? 1 : 0;  
        for (int j = mask_start; j < 5; j ++)
        {
            s[digit_start] += first[j];
            s[s.size() - 1 - digit_start] += second[j];
            helper(res, s, digit_start + 1, upper_border);
            s[digit_start] -= first[j];
            s[s.size() - 1 - digit_start] -= second[j];
        }
    }
};
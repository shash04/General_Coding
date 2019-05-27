// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// Write a function to determine if a number is strobogrammatic. The number is represented as a string.

// Example 1:
// Input:  "69"
// Output: true

// Example 2:
// Input:  "88"
// Output: true

// Example 3:
// Input:  "962"
// Output: false

// https://leetcode.com/problems/strobogrammatic-number/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m1 = {{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};
        for(int start=0, end=num.size()-1; start<=end; start++, end--)
        {
            if(m1.find(num[start]) == m1.end() || m1[num[start]] != num[end])
                return false;
        }
        return true;
    }
};
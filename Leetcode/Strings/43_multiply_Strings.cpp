// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Example 1:
// Input: num1 = "2", num2 = "3"
// Output: "6"

// Example 2:
// Input: num1 = "123", num2 = "456"
// Output: "56088"

// Note:
// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

// https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string ans(len1+len2, '0');             // Max length of ans = len(num1) + len(num2)
        
        for(int i=len1-1; i>=0; i--)            // For each digit in num 1 
        {
            for(int j=len2-1; j>=0; j--)        // Multiply with each digit in num2 and save result. Save carry to next higher pos 
            {
                int mul     = (num1[i] - '0') * (num2[j] - '0') + (ans[i+j+1] - '0');
                ans[i+j+1]  = mul % 10 + '0';
                ans[i+j]    += mul / 10;
            }
        }
        
        for(int i=0; i<len1+len2; i++)          // Return ans without any leading zeros
        {
            if(ans[i] != '0')
                return ans.substr(i);
        }
        
        return "0";
    }
};
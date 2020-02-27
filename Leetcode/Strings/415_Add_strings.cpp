// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

// https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() == 0)
            return num2;
        
        if(num2.size() == 0)
            return num1;
        
        string retStr;
        
        int ptr1 = num1.size() - 1;
        int ptr2 = num2.size() - 1;
        
        int carry = 0;
        
        while(ptr1 >= 0 || ptr2 >= 0 || carry)
        {
            int currSum = 0;
            
            if(ptr1 >= 0)
            {
                currSum += num1[ptr1] - '0';
                ptr1--;
            }
            
            if(ptr2 >= 0)
            {
                currSum += num2[ptr2] - '0';
                ptr2--;
            }
            
            currSum += carry;
            carry   = currSum / 10;
            currSum = currSum % 10;
            
            retStr += to_string(currSum);
        }
        
        reverse(retStr.begin(), retStr.end());
        
        return retStr;
    }
};

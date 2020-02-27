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
        
        int ptr1 = num1.size() - 1;
        int ptr2 = num2.size() - 1;
        
        // retStr is big enough to hold sum
        string retStr ( num1.size() + num2.size(), '0' );
        int ptrSum = num1.size() + num2.size() - 1;
        int carry = 0;
        
        // Add digits for both num1 and num2 valid
        while(ptr1 >= 0 && ptr2 >= 0)
        {
            int d1 = num1[ptr1] - '0';
            int d2 = num2[ptr2] - '0';
            
            int currSum = d1 + d2 + carry;
            
            if(currSum >= 10)
            {
                carry = 1;
                currSum = currSum %10;
            }
            else
            {
                carry = 0;
            }
            
            retStr[ptrSum] = '0' + currSum;
            ptr1--; ptr2--; ptrSum--;
        }
        
        // Add remaining valid digits for num1
        while(ptr1 >= 0)
        {
            int d1 = num1[ptr1] - '0';
            int currSum = d1 + carry;
  
            if(currSum >= 10)
            {
                carry = 1;
                currSum = currSum %10;
            }
            else
            {
                carry = 0;
            }
            
            retStr[ptrSum] = '0' + currSum;
            ptr1--; ptrSum--;
        }
        
        // Add remaining valid digits for num2
        while(ptr2 >= 0)
        {
            int d2 = num2[ptr2] - '0';
            int currSum = d2 + carry;

            if(currSum >= 10)
            {
                carry = 1;
                currSum = currSum %10;
            }
            else
            {
                carry = 0;
            }
            
            retStr[ptrSum] = '0' + currSum;
            ptr2--; ptrSum--;
        }
        
        // Check if carry is left to add
        if(carry != 0)
        {
            retStr[ptrSum] = '0' + carry;
        }
        
        // Remove all trailing zero. Return 0 if answer is 0
        auto strBegin = retStr.find_first_not_of("0");
        if (strBegin == string::npos)
            return "0";
        
        retStr = retStr.substr(strBegin, retStr.size());
        
        return retStr;
    }
};
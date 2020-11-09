// Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

// Note:
// All letters in hexadecimal (a-f) must be in lowercase.
// The hexadecimal string must not contain extra leading 0s.

// If the number is zero, it is represented by a single zero character '0';
// otherwise, the first character in the hexadecimal string will not be the zero character.

// The given number is guaranteed to fit within the range of a 32-bit signed integer.

// You must not use any method provided by the library which converts/formats the number to hex directly.

// Example 1:
// Input:
// 26
// Output:
// "1a"

// Example 2:
// Input:
// -1
// Output:
// "ffffffff"

// https://leetcode.com/problems/convert-a-number-to-hexadecimal/

class Solution {
    string hexStr = "0123456789abcdef";
    
    string unsignedTypecastMethod(int num)
    {
        // typecasting INT to UNSIGNED INT takes care of negative numbers
        // -1 => UINT_MAX => 0xFFFFFFFFF
        unsigned int n = num;
        
        string result;
        
        while(n)
        {
            result += hexStr[n % 16];
            n = n / 16;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    string bitShiftingMethod(int num)
    {
        int n = num;
        int count = 0;
        
        string result;
        
        // count is required as right shifting negative number is arithmatic
        // arithmatic shift = preserves the sign and 1's are added to left for -ve num
        while(n && count++ < 8)
        {
            // Consider only last 4 digits of binary representation at one time
            result += hexStr[n & 0xF];
            
            // Right shift the number by 4 digits
            n >>= 4;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
        
        return bitShiftingMethod(num);
        
        // return unsignedTypecastMethod(num);
    }
};
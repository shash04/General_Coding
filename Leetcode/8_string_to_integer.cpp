// Example 1:

// Input: "42"
// Output: 42
// Example 2:

// Input: "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', which is the minus sign.
//              Then take as many numerical digits as possible, which gets 42.
// Example 3:

// Input: "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
// Example 4:

// Input: "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which is not a numerical 
//              digit or a +/- sign. Therefore no valid conversion could be performed.
// Example 5:

// Input: "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
//              Thefore INT_MIN (−231) is returned.
             
class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        long ret = 0;
        int sign = 1;
        
        int i=0;
        int k=0;
        while(str[i] == ' ' && i<len)
            i++;
        
        if(str[i] == '+'){
            sign = 1; i++;
        }
        else if(str[i] == '-'){
            sign = -1; i++;
        }
        
        if(!(str[i] >= '0' && str[i] <= '9'))
            return 0;
        
        for(int j=i; j<len; j++)
        {
            if(!(str[j] >= '0' && str[j] <= '9'))
                break;

            ret = (ret * 10) + (str[j] - '0');
            k++;

            if(ret*sign < INT_MIN)
                return INT_MIN;
            if(ret*sign > INT_MAX)
                return INT_MAX; 
        }
        ret = ret * sign;
        return ret;
    }
};
// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero.

// Example 1:
// Input: dividend = 10, divisor = 3
// Output: 3

// Example 2:
// Input: dividend = 7, divisor = -3
// Output: -2

// Note:
// Both dividend and divisor will be 32-bit signed integers.
// The divisor will never be 0.
// Assume we are dealing with an environment which could only store integers within the 32-bit signed
// integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

// https://leetcode.com/problems/divide-two-integers/

// Concept: quotient = number of times divisor can be subtracted from dividend
// Suppose dividend = 15 and divisor = 3, 15 - 3 > 0. We now try to subtract more by shifting 3 to the left by 1 bit (6). Since 15 - 6 > 0, shift 6
// again to 12. Now 15 - 12 > 0, shift 12 again to 24, which is larger than 15. So we can at most subtract 12 from 15. Since 12 is obtained by
// shifting 3 to left twice, it is 1 << 2 = 4 times of 3. We add 4 to an answer variable (initialized to be 0). The above process is like
// 15 = 3 * 4 + 3. We now get part of the quotient (4), with a remaining dividend 3.
//Then we repeat the above process by subtracting divisor = 3 from the remaining dividend = 3 and obtain 0. We are done. In this case, no shift happens.
// We simply add 1 << 0 = 1 to the answer variable.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        long quotient = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        
        while(dvd >= dvs)
        {
            long temp = dvs;
            long curr_shift = 1;
            while(temp << 1 <= dvd)
            {
                temp <<= 1;
                curr_shift <<= 1;
            }
            dvd -= temp;
            quotient += curr_shift;
        }
        
        return sign * quotient;
    }
};
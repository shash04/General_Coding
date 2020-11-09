// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, return any of them.

// Example 1:
// Input: numerator = 1, denominator = 2
// Output: "0.5"

// Example 2:
// Input: numerator = 2, denominator = 1
// Output: "2"

// Example 3:
// Input: numerator = 2, denominator = 3
// Output: "0.(6)"

// Example 4:
// Input: numerator = 4, denominator = 333
// Output: "0.(012)"

// Example 5:
// Input: numerator = 1, denominator = 5
// Output: "0.2"
 

// Constraints:
// -231 <= numerator, denominator <= 231 - 1
// denominator != 0

// https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        
        string result;
        
        if(numerator < 0 ^ denominator < 0)
            result += "-";
        
        long n = abs(numerator);
        long d = abs(denominator);
        
        result += to_string(n / d);
        
        // If only integral ans, return
        if(n % d == 0)
            return result;
        
        // There is a fractional part
        result += ".";
        
        // Store remainder and index as pair in map for checking recurrence
        unordered_map<int, int> remIdx;
        string fractional;
        int idx = 0;
        
        for(long rem = n % d; rem != 0; rem = n % d)
        {
            if(remIdx.count(rem))
            {
                fractional.insert(remIdx[rem], "(");
                fractional += ")";
                break;
            }
            
            remIdx[rem] = idx++;
            n = rem * 10;
            
            fractional += to_string(n / d);
        }
        
        return result + fractional;
    }
};
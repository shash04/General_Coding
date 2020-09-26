// Validate if a given string can be interpreted as a decimal number.

// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// " -90e3   " => true
// " 1e" => false
// "e3" => false
// " 6e-1" => true
// " 99e2.5 " => false
// "53.5e93" => true
// " --6 " => false
// "-+3" => false
// "95a54e53" => false

// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
// However, here is a list of characters that can be in a valid decimal number:

// Numbers 0-9
// Exponent - "e"
// Positive/negative sign - "+"/"-"
// Decimal point - "."
// Of course, the context of these characters also matters in the input.

// https://leetcode.com/problems/valid-number/

class Solution {
    void skipWhiteSpaces(const string& s, int& idx)
    {
        while(idx < s.size() && s[idx] == ' ')
            idx++;
    }
public:
    bool isNumber(string s) {
        int digits = 0;
        int dots = 0;
        
        int idx = 0, n = s.size();
        
        // skip white spaces
        skipWhiteSpaces(s, idx);
        
        // Skip sign
        if (s[idx] == '+' || s[idx] == '-')
            idx++;
        
        // Count digits and decimal points
        while(idx < n && (isdigit(s[idx]) || s[idx] == '.'))
        {
            if(s[idx] == '.')
                dots++;
            else
                digits++;
            
            idx++;
        }
        
        if(!digits || dots > 1)
            return false;
        
        // If exponential component present
        if(idx < s.size() && s[idx] == 'e')
        {
            // skip 'e'
            idx++;
            
            // Skip sign
            if (s[idx] == '+' || s[idx] == '-')
                idx++;
            
            digits = 0;
            
            // Count digits and decimal points
            while(idx < n && isdigit(s[idx]))
            {
                digits++;
                idx++;
            }
                  
            if(!digits)
                return false;
        }
                  
        skipWhiteSpaces(s, idx);
        
        return idx == s.size();
    }
};
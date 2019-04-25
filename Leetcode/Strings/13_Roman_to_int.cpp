// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.

// Example 1:
// Input: "III"
// Output: 3

// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        for(int i=0; i<s.size(); i++)
        {
            switch(s[i])
            {
                case 'M':
                    number += 1000;
                    break;
                case 'D':
                    number += 500;
                    break;
                case 'C':
                    if(i+1<s.size() && s[i+1] == 'D')
                    {
                        number += 400;
                        i++;
                    }
                    else if(i+1<s.size() && s[i+1] == 'M')
                    {
                        number += 900;
                        i++;
                    }
                    else
                        number += 100;
                    break;
                case 'L':
                    number += 50;
                    break;
                case 'X':
                    if(i+1<s.size() && s[i+1] == 'L')
                    {
                        number += 40;
                        i++;
                    }
                    else if(i+1<s.size() && s[i+1] == 'C')
                    {
                        number += 90;
                        i++;
                    }
                    else
                        number += 10;
                    break;
                case 'V':
                    number += 5;
                    break;
                case 'I':
                    if(i+1<s.size() && s[i+1] == 'V')
                    {
                        number += 4;
                        i++;
                    }
                    else if(i+1<s.size() && s[i+1] == 'X')
                    {
                        number += 9;
                        i++;
                    }
                    else
                        number += 1;
                    break;
            }
        }
        return number;
    }
};
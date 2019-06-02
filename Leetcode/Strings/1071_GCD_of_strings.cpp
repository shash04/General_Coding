// For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)
// Return the largest string X such that X divides str1 and X divides str2.

// Example 1:
// Input: str1 = "ABCABC", str2 = "ABC"
// Output: "ABC"

// Example 2:
// Input: str1 = "ABABAB", str2 = "ABAB"
// Output: "AB"

// Example 3:
// Input: str1 = "LEET", str2 = "CODE"
// Output: ""

// Note:
// 1 <= str1.length <= 1000
// 1 <= str2.length <= 1000
// str1[i] and str2[i] are English uppercase letters.

// https://leetcode.com/contest/weekly-contest-139/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        int str1Size = str1.size();
        int str2Size = str2.size();
        
        if (str1Size > str2Size)
            return gcdOfStrings(str2,str1);
        
        for (int k=str1Size; k>=1; k--)
        {
            if(str1Size % k != 0)                       // k should divide string sizes perfectly
                continue;
            if(str2Size % k != 0)
                continue;

            string gcd = str1.substr(0,k);              // Substring from 0 to k
            
            int flag = 1;
            for (int i=0; i<str1Size; i+=k)             // Check if str1 has all substrings equal to gcd
            {
                if (str1.substr(i,k) != gcd)
                {
                    flag = 0;                           // Toggle flag as subtring didn't match gcd == Not a divisor
                    break;
                }
            }
            if (flag==0) continue;                      // Continue to next substr (divisor)
            
            for (int i=0; i<str2Size; i+=k)             // Check if str2 has all substrings equal to gcd
            {
                if (str2.substr(i,k) != gcd)
                {
                    flag = 0;                           // Toggle flag as subtring didn't match gcd == Not a divisor
                    break;
                }
            }
            if (flag==0) continue;                      // Continue to next substr (divisor)
                
            return gcd;
        }
        
        return "";
    }
};

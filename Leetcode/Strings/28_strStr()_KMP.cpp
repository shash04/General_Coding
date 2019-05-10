// Implement strStr().
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2

// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

// https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();
        if(n==0)
            return 0;
        
        vector<int> lps(n,0);
        fillPatternLps(lps, needle);
        
        int i=0, j=0;
        while(i<m && j<n)
        {
            if(haystack[i] == needle[j])
            {
                i++; j++;
            }
            else                        // mismatch found
            {
                if(j != 0)              // we have some suffix matched to prefix in pattern
                {
                    j = lps[j-1];
                }
                else
                {
                    i++;
                }
            }
            
            if(j == n)              // pattern matched
                return i-j;    
        }
        return -1;
    }
    
    void fillPatternLps(vector<int> &lps, string needle)
    {
        int n = needle.length();
        int index = 0;
        int i = 1;
        while(i<n)
        {
            if(needle[i] == needle[index])
            {
                lps[i] = index + 1;
                index++; i++;
            }
            else if(index != 0)
            {
                index = lps[index-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
};
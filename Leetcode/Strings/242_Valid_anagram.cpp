// Given two strings s and t , write a function to determine if t is an anagram of s

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
       int count[256] = {0};
   
       int i;
       for(i=0; s[i] && t[i]; i++)
       {
           count[s[i]]++;
           count[t[i]]--;
       }
        
       if(s[i] || t[i])
           return false;

       for(int j=0; j<256; j++)
       {
           if(count[j] != 0)
               return false;
       }

       return true;
    }
};
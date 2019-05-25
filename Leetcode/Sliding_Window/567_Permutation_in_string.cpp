// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
// In other words, one of the first string's permutations is the substring of the second string.

// Example 1:
// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False

// Note:
// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].

// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s_vec1(26,0), s_vec2(26,0);
        
        if(s1.size() > s2.size())
            return false;
        
        // Increment the vector indices for chars present in strings
        for(int i=0; i<s1.size(); i++)
        {
            ++s_vec1[s1[i] - 'a'];
            ++s_vec2[s2[i] - 'a'];
        }
        
        // If both vectors are equal = substring true
        if(s_vec1 == s_vec2)
            return true;
        
        // Slide window and decrement and increment vector appropriately 
        for(int i=s1.size(); i<s2.size(); i++)
        {
            --s_vec2[s2[i-s1.size()] - 'a'];
            ++s_vec2[s2[i] - 'a'];
            
            if(s_vec1 == s_vec2)
                return true;
        }
        return false;
    }
};
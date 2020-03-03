// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// Example:
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:

// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return "";
        
        unordered_map<char, int> m1;
        int start = 0, end = 0, minLen = INT_MAX, minStart = 0;
        int counter = t.size();
        
        // Increment indices for chars in t 
        for(char& c : t)
            m1[c]++;
        
        while(end < s.size())
        {
            if(m1[s[end]] > 0)              // Char in s exists in t
                counter--;                  // Decrement the remaining char count to match
            
            m1[s[end]]--;                   // Decrement index for char. Unmatched char values would be -1.
            end++;                          // Increment end pointer
            
            while(counter == 0)             // Valid window found
            {
                if((end - start) < minLen)
                {
                    minLen = end - start;   // end already incremented. Thus +1 not required
                    minStart = start;
                }
                
                m1[s[start]]++;             // For sliding window, increment the index which was decremented earlier
                
                if(m1[s[start]] > 0)        // If s[start] is present in t, its value now would be 1
                    counter++;              // Sliding past it should increment the remaining char count to match
                
                start++;                    // Slide window
            }
        }
        
        if(minLen == INT_MAX)
            return "";
        
        return s.substr(minStart, minLen);
    }
};

// Given a string, find the length of the longest substring T that contains at most k distinct characters.

// Example 1:
// Input: s = "eceba", k = 2
// Output: 3
// Explanation: T is "ece" which its length is 3.

// Example 2:
// Input: s = "aa", k = 1
// Output: 2
// Explanation: T is "aa" which its length is 2.

// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size() == 0 || k == 0)
            return 0;
        
        // map that keeps track of char and their freq count
        unordered_map<char, int> freqMap;
        
        // min len will be 1
        int maxLen = 1;
        
        // initialize left ptr to 0
        int left = 0;
        
        for(int i=0; i < s.size(); i++)
        {
            freqMap[s[i]]++;
            
            if(freqMap.size() > k)
            {
                // decrement and check if freq of char at left idx == 0
                // repeat till char found and shift left
                while(--freqMap[s[left]] != 0)
                {
                    left++;
                }
                
                // remove the char from map
                freqMap.erase(s[left]);
                
                // increment the left ptr to point to next char
                left++;
            }
            
            // calculate max len at end of every iteration
            maxLen = max(maxLen, i - left + 1);
        }
        
        return maxLen; 
    }
};

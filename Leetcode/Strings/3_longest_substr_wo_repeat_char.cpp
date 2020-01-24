// Given a string, find the length of the longest substring without repeating characters.

// Example 1:
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 

// Example 2:
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// ****************************************************************************************************
// Approach - Maintain a ptr that indicates the starting index for non-repeating char string
// If there is any char repeated, move the ptr by 1 to right of index of that char stored in map
// ****************************************************************************************************

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size())
            return 0;
        
        unordered_map<char, int> m1;
        int ans = 0;
        int ptr = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(m1.find(s[i]) != m1.end())
                ptr = max(ptr, m1[s[i]] + 1);
                
            m1[s[i]] = i;
            ans = max(ans, i-ptr+1);
        }
        return ans;
    }
};

// ****************************************************************************************************
// Approach - Unordered set to track repeating chars & queue to track substr
// ****************************************************************************************************

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        
        unordered_set<char> charSet;
        queue<char> charQ;
        
        int maxLen = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(charSet.count(s[i]))
            {
                int qSize = charQ.size();
                maxLen = max(qSize, maxLen);
                
                while(charQ.front() != s[i])
                {
                    charSet.erase(charQ.front());
                    charQ.pop();
                }
                
                charSet.erase(charQ.front());
                charQ.pop();                
            }
            
            charSet.insert(s[i]);
            charQ.push(s[i]);
        }
        
        int qSize = charQ.size();
        maxLen = max(qSize, maxLen);
        return maxLen;
    }
};
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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(256, -1);
        int start = -1;
        int maxLen = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(vec[s[i]] > start)
                start = vec[s[i]];
            vec[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};

// Alternate solution
class Solution {
public:    
    int lengthOfLongestSubstring(string s) {
        queue<char> q1;
        int count[256] = {0};
        int len = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(q1.empty())
            {
                q1.push(s[i]);
                count[s[i]] = 1;
            }
            else
            {
                if(count[s[i]])
                {
                    int newLen = q1.size();
                    if (newLen > len)
                        len = newLen;
                    
                    while(q1.front() != s[i]){
                        count[q1.front()] = 0;
                        q1.pop();
                    }
                    count[s[i]] = 0;
                    q1.pop();
                }

                q1.push(s[i]);
                count[s[i]] = 1;
            }
        }
        int newLen = q1.size();
        if (newLen > len)
            len = newLen;
        return len;
    }
};
// Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

// The substrings do not overlap, that is for any two substrings s[i..j] and s[k..l], either j < k or i > l is true.
// A substring that contains a certain character c must also contain all occurrences of c.
// Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings,
// return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

// Notice that you can return the substrings in any order.

// Example 1:
// Input: s = "adefaddaccc"
// Output: ["e","f","ccc"]
// Explanation: The following are all the possible substrings that meet the conditions:
// [
//   "adefaddaccc"
//   "adefadda",
//   "ef",
//   "e",
//   "f",
//   "ccc",
// ]
// If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda",
// we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also,
// that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"]
// which gives us 3 substrings. No other solution of the same number of substrings exist.

// Example 2:
// Input: s = "abbaccd"
// Output: ["d","bb","cc"]
// Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3,
// it's considered incorrect since it has larger total length.

// Constraints:
// 1 <= s.length <= 10^5
// s contains only lowercase English letters.

// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/

class Solution {
    int checkSubstr(string& s, int i, vector<int>& left, vector<int>& right)
    {
        // last occurence of curr starting char
        int rightIdx= right[s[i] - 'a'];
        
        // for every char added to the substr, check if its first occurence is before i - invalid substr
        // if not, then get max right index possible for cur substr
        for(int j = i; j <= rightIdx; j++)
        {
            if(left[s[j] - 'a'] < i)
                return -1;
            
            rightIdx = max(rightIdx, right[s[j] - 'a']);
        }
        
        return rightIdx;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> left(26, INT_MAX), right(26, INT_MIN);
        
        vector<string> result;
        
        for (int i = 0; i < s.size(); i++)
        {
            left[s[i] - 'a'] = min(left[s[i] - 'a'], i);
            right[s[i] - 'a'] = i;
        }
        
        int rightIdx = -1;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(i == left[s[i] - 'a'])
            {
                // Get max right index for substr starting with i index
                int newRight = checkSubstr(s, i, left, right);
                
                // continue for invalid string
                if(newRight == -1)
                    continue;
                
                // Add a new element to the result when a new valid substring that does not overlap
                // with the last valid substring (i > right)
                // Otherwise, we just keep on updating the last valid substring
                // Also - for 2 overlapping substr abba and bb, we will always pick bb. Updating just back works.
                if(i > rightIdx)
                    result.push_back("");
                
                rightIdx = newRight;
                result.back() = s.substr(i, rightIdx - i + 1);
            }
        }
        
        return result;
    }
};
// Given a string S, return the number of substrings of length K with no repeated characters.

// Example 1:
// Input: S = "havefunonleetcode", K = 5
// Output: 6
// Explanation: 
// There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.

// Example 2:
// Input: S = "home", K = 5
// Output: 0
// Explanation: 
// Notice K can be larger than the length of S. In this case is not possible to find any substring.

// Note:
// 1 <= S.length <= 10^4
// All characters of S are lowercase English letters.
// 1 <= K <= 10^4

// https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        vector<int> charFreq (26, 0);
        
        int result = 0;
        int idx = 0;
        int start = 0;
        
        while(idx < S.size())
        {
            charFreq[S[idx] - 'a']++;
            
            while(charFreq[S[idx] - 'a'] > 1 || idx - start + 1 > K)
            {
                charFreq[S[start] - 'a']--;
                start++;
            }
            
            if(idx - start + 1 == K)
                result++;
                        
            idx++;
        }
        
        return result;
    }
};
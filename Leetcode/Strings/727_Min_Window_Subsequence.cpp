// Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

// If there is no such window in S that covers all characters in T, return the empty string "".
// If there are multiple such minimum-length windows, return the one with the left-most starting index.

// Example 1:
// Input: 
// S = "abcdebdde", T = "bde"
// Output: "bcde"
// Explanation: 
// "bcde" is the answer because it occurs before "bdde" which has the same length.
// "deb" is not a smaller window because the elements of T in the window must occur in order.
 

// Note:
// All the strings in the input will only contain lowercase letters.
// The length of S will be in the range [1, 20000].
// The length of T will be in the range [1, 100].

// https://leetcode.com/problems/minimum-window-subsequence/

class Solution {
public:
    string minWindow(string S, string T) {
        int lenS = S.size();
        int lenT = T.size();
        
        if (lenT > lenS)
            return "";
        
        if (lenT == lenS)
            return S == T ? S : "";
        
        // ps = idx for S; pt = idx for T; begin = idx of min window; minL = length of window
        int ps = 0, pt = 0, begin = 0, minL = INT_MAX;
        
        
        // Move ps from 0 to S.size()
        while (ps < lenS)
        {
            // Increment pt only on match
            if (S[ps] == T[pt])
            {
                pt++;
            }
            
            // All chars in T are matched
            if (pt == lenT)
            {
                // reverse will go in reverse from ps - to find if there is smaller string in cur window
                // pt = pt - 1 as pt is at T.size()
                int reverse = ps;
                pt = pt - 1;
                
                while (pt >= 0)
                {
                    if(S[reverse] == T[pt])
                        pt--;
                    
                    reverse--;
                }
                
                // Check if cur window is smaller than min
                if (ps - reverse < minL)
                {
                    minL = ps - reverse;
                    begin = reverse + 1;
                }
                
                // Fix pointers for next idx 
                pt = 0;
                ps = reverse + 1;
            }
            
            ps++;
        }
        
        return minL == INT_MAX ? "" : S.substr(begin, minL);
    }
};
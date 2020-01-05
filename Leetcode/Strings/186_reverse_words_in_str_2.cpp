// Given an input string , reverse the string word by word. 

// Example:
// Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
// Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

// Note:
// A word is defined as a sequence of non-space characters.
// The input string does not contain leading or trailing spaces.
// The words are always separated by a single space.
// Follow up: Could you do it in-place without allocating extra space?

// https://leetcode.com/problems/reverse-words-in-a-string-ii/

// Concept - reverse the string
// Iterate over the reversed string. Maintain two ptrs.
// Find white space. Reverse the word in place. Carry on for loop from white space
// Consider following example = "the sky is blue"
class Solution {
public:
    void reverseWords(vector<char>& s) {
        if(s.size() == 0)
            return;
        
        reverse(s.begin(), s.end());                // reverse the array - "eulb si yks eht"
        int l, r;
        
        for(int i=0; i<s.size(); i++)
        {
            l = i;
            r = i;
            while(r < s.size() && s[r] != ' ')      // stop at white char. First iteration : i=0, r=4
                r++;
            i = r;                                  // Next iteration would start from i = 4 (next word)
            r--;                                    // r points to last char of current word
            
            while(l<r)                              // reverse the reversed word in place
            {
                swap(s[l], s[r]);
                l++; r--;
            }
        }
    }
};
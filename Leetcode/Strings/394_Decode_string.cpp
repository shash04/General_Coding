// Given an encoded string, return it's decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated
// exactly k times. Note that k is guaranteed to be a positive integer.
// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
// Furthermore, you may assume that the original data does not contain any digits and that digits are only for
// those repeat numbers, k. For example, there won't be input like 3a or 2[4].

// Examples:
// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        string ans;
        if(!s.size())
            return ans;
        int i = 0;
        // Imp to pass i by reference as its updated value is required after coming back from recursive call
        ans = decodeStringHelper(s, i);
        return ans;
        
    }
    
    string decodeStringHelper(string& s, int& i)
    {
        string ret;
        
        while(i < s.size() && s[i] != ']')                  // Continue till string ends or you come accross ']'
        {
            if(!isdigit(s[i]) && s[i] != '[')               // Check if its a alphabets
            {
                ret += s[i];                                // Add all alphabets to ret string
                i++;
            }
            else
            {
                int times = 0;
                while(i<s.size() && isdigit(s[i]))          // Determine num of times string in [] is repeated
                {
                    times = times*10 + s[i] - '0';
                    i++;
                }

                i++;                                        // Get past '['
                string curr_str = decodeStringHelper(s, i); // Recursively call for string after '['
                i++;                                        // Get past ']'

                while(times-- > 0)                          // Add returned string num of times
                    ret += curr_str;
            }
        }
        return ret;
    }
};
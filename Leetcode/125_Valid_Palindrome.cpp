// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// Input: "A man, a plan, a canal: Panama"
// Output: true

class Solution {
public:
    char toLower(char c)
    {
        if( c >= 'A' && c <= 'Z')
            return c - ('Z' - 'z');
        return c;
    }
    
    bool isPalindrome(string s) {
        string newStr = "";
        for(int i=0; i<s.size(); i++)
        {
            if((s[i]>='a' && s[i]<='z')
              || (s[i]>='A' && s[i]<='Z')
              || (s[i]>='0' && s[i]<='9'))
            {
                newStr += toLower(s[i]);
            }
        }
        
        for(int i=0; i<newStr.size()/2; i++)
        {
            if(newStr[i] != newStr[newStr.size()-1-i])
                return false;
        }
        return true;
    }
};
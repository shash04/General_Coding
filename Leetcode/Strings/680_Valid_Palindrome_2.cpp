// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

// Example 1:
// Input: "aba"
// Output: True

// Example 2:
// Input: "abca"
// Output: True

// Explanation: You could delete the character 'c'.
// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

// https://leetcode.com/problems/valid-palindrome-ii/


// **************************************************************************************************
// Iterative approach
// **************************************************************************************************
class Solution {
public:
    bool validPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            if(s[i] != s[j])
            {
                if(isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1))
                    return true;
                else
                    return false;
            }
        }
        
        return true;
    }
    
    bool isPalindrome(string& s, int start, int end)
    {
        while(start < end && s[start] == s[end])
        {
            start++;
            end--;
        }
        
        return start >= end;
    }
};

// **************************************************************************************************
// Recursive approach
// **************************************************************************************************
class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        int count = 0;
        
        return helper(s, start, end, count);
    }
    
    bool helper(string& s, int start, int end, int count)
    {
        if(start > end)
            return true;
        
        if(count == 2)
            return false;
        
        if(s[start] != s[end])
            return (helper(s, start + 1, end, count + 1) || helper(s, start, end - 1, count + 1));
        else
            return helper(s, start + 1, end - 1, count);
    }
};
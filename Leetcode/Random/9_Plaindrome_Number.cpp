// Input: 121
// Output: true
// Example 2:

// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

// Solution 1: Reverse the number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int rev = 0;
        int ori = x;
        while(ori)
        {
            rev = rev*10 + ori%10;
            ori = ori/10;
        }
        if(rev == x)
            return true;
        else
            return false;
    }
};

// Solution 2: Optimized solution = reverse onlt half the number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int rev = 0;
        
        while(rev < x)
        {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }
        
        if(rev == x || rev/10 == x)
            return true;
        else
            return false;
    }
};

// Solution 3: Converting int to string

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string s = to_string(x);
        for(int i=0; i<s.size(); i++){
            if(s[i] != s[s.size()-1-i])
                return false;
        }
        return true;
    }
};
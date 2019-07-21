// Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

// Example 1:
// Input: "aabb"
// Output: ["abba", "baab"]

// Example 2:
// Input: "abc"
// Output: []

// https://leetcode.com/problems/palindrome-permutation-ii/

// Logic: Create a map to register count of chars. Odd count char would be in middle
// Create first half of palindrome string as second half would be just reverse of it
// Use next_permutation function to get all permutations of first half
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> ans;
        unordered_map<char, int> charCount;
        int odd = 0;
        char mid;
        string firstHalf;
        
        for(char c : s)                         // map to keep count of chars
        {
            charCount[c]++;
        }
        
        for(auto entry : charCount)
        {
            if(entry.second % 2)
            {    
                odd++;
                mid = entry.first;              // Odd count char would be in middle
                if(odd > 1)
                    return ans;                 // invalid string for palindrome
            }
            firstHalf += string(entry.second/2, entry.first);   // add char count/2 times to first half 
        }
        
        getAllPermutations(ans, firstHalf);     // get all permutations of first half
        
        for(string& curr_string : ans)          // reverse the first half and add to it to create palindrome
        {
            string rev(curr_string);
            reverse(rev.begin(), rev.end());
            if(odd) rev = mid + rev;
            curr_string += rev;
        }
        
        return ans;
    }
    
    void getAllPermutations(vector<string>& ans, string firstHalf)
    {
        string temp(firstHalf);
        do
        {
            ans.push_back(firstHalf);
            next_permutation(firstHalf.begin(), firstHalf.end());
        } while( firstHalf != temp );
    }
};
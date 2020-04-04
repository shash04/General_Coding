// Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

// Return the maximum possible length of s.

// Example 1:
// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
// Maximum length is 4.

// Example 2:
// Input: arr = ["cha","r","act","ers"]
// Output: 6
// Explanation: Possible solutions are "chaers" and "acters".

// Example 3:
// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26

// Constraints:
// 1 <= arr.length <= 16
// 1 <= arr[i].length <= 26
// arr[i] contains only lower case English letters.

// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

// Optimal approach - DFS with bitset
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> bitsArr;
        
        for(string& s : arr)
        {
            bitset<26> bs;
            
            // Populate current bitset vec
            for(char& c : s)
                bs.set(c - 'a');
            
            // If all the chars are unique, add to bitsArr
            if(bs.count() == s.size())
                bitsArr.push_back(bs);
        }
        
        return maxLenHelper(bitsArr, bitset<26>(), 0);
    }
    
    int maxLenHelper(vector<bitset<26>>& bitsArr, bitset<26> bs, int start)
    {
        int currMaxLen = bs.count();
        
        for(int i=start; i < bitsArr.size(); i++)
        {
            // Check if add the two strings would have all unique chars 
            if((bitsArr[i] & bs).none())
            {
                currMaxLen = max(currMaxLen, maxLenHelper(bitsArr, bitsArr[i] | bs, i+1));
            }
        }
        
        return currMaxLen;
    }
};

// DFS with string
class Solution {
public:
    int maxLength(vector<string>& arr) {
        if(arr.size() == 0)
            return 0;
        
        int maxLen = 0;
        string currStr = "";
        
        for(int i=0; i < arr.size(); i++)
        {
            maxLen = max(maxLen, backtrack(arr, currStr, i));
        }
        
        return maxLen;
    }
    
    int backtrack(vector<string>& arr, string currStr, int start)
    {
        unordered_set<char> charSet (currStr.begin(), currStr.end());
        
        if(charSet.size() != currStr.size())
            return 0;
        
        int currMaxLen = currStr.size();
        
        for(int i=start; i < arr.size(); i++)
        {
            currMaxLen = max(currMaxLen, backtrack(arr, currStr + arr[i], i + 1));
        }
        
        return currMaxLen;
    }
};

// Classic solution - Not optimal
class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Note - initializing with empty string required for first iteration over allCombList
        vector<string> allCombList {""};
        int maxLen = 0;
        
        for(string& currStr : arr)
        {
            // if chars repeat in the curr str = skip and continue
            if(!areAllCharUnique(currStr))
                continue;
            
            // require local list as we are iterating over allCombList
            vector<string> currCombList;
            
            for(string& s : allCombList)
            {
                string newStr = s + currStr;
                
                // add the new string to local list if all chars are unique
                if(areAllCharUnique(newStr))
                    currCombList.push_back(newStr);
            }
            
            // Concatenate local list with allCombList
            allCombList.insert(allCombList.end(), currCombList.begin(), currCombList.end());
        }
        
        for(string& str : allCombList)
        {
            // string size() returns size_t type. Need to typecast
            maxLen = max(maxLen, (int)str.size());
        }
        
        return maxLen;
    }
    
    bool areAllCharUnique(string s)
    {
        if(s.size() > 26)
            return false;
        
        vector<bool> charVec (26, false);
        
        for(char& c : s)
        {
            if(charVec[c - 'a'])
                return false;
            
            charVec[c - 'a'] = true;
        }
        
        return true;
    }
};
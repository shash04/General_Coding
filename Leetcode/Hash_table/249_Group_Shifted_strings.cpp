// Given a string, we can "shift" each of its letter to its successive letter,
// for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

// "abc" -> "bcd" -> ... -> "xyz"
// Given a list of non-empty strings which contains only lowercase alphabets,
// group all strings that belong to the same shifting sequence.

// Example:

// Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
// Output: 
// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]

// https://leetcode.com/problems/group-shifted-strings/

class Solution {
    string getHash(const string& s)
    {
        string retStr;
        
        // For every char, calculate diff with prev char
        // add the diff to 'a' and add ',' to avoid confusion with actual strings
        for(int i = 1; i < s.size(); i++)
        {
            int diff = s[i] - s[i-1];
            
            if(diff < 0)
                diff += 26;
            
            retStr += ('a' + diff) + ','; 
        }
        
        return retStr;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> strMap;
        
        for(string& s : strings)
            strMap[getHash(s)].push_back(s);
            
        for(auto& entry : strMap)
            result.push_back(entry.second);
        
        return result;
    }
};
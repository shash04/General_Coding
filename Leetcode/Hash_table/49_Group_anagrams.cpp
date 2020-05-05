// Given an array of strings, group anagrams together.

// Example:
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]

// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retVec;
        
        unordered_map<string, vector<string>> anagramMap;
        
        for(int i=0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            anagramMap[temp].push_back(strs[i]);
        }
        
        for(auto& entry : anagramMap)
            retVec.push_back(entry.second);
        
        return retVec;
    }
};


// ********************************************************************
// Alternate method
// ********************************************************************
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retVec;
        
        unordered_map<string, vector<string>> anagramMap;
        
        for(int i=0; i < strs.size(); i++)
        {
            string hashKey = getHashKey(strs[i]);
            anagramMap[hashKey].push_back(strs[i]);
        }
        
        for(auto& entry : anagramMap)
            retVec.push_back(entry.second);
        
        return retVec;
    }
    
    string getHashKey(string& s)
    {
        string hashKey;
        
        // Using map as the char entries will always be sorted
        map<char, int> m1;
        
        for(char& c : s)
            m1[c]++;
        
        for(auto& entry : m1)
        {
            hashKey += entry.first + to_string(entry.second);
        }
        
        return hashKey;
    }
};


// ********************************************************************
// Alternate method
// ********************************************************************
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retVec;
        
        map<vector<int>, vector<string>> anagramMap;
        
        for(int i=0; i < strs.size(); i++)
        {
            vector<int> hashKey = getHashKey(strs[i]);
            anagramMap[hashKey].push_back(strs[i]);
        }
        
        for(auto& entry : anagramMap)
            retVec.push_back(entry.second);
        
        return retVec;
    }
    
    vector<int> getHashKey(string& s)
    {
        vector<int> hashKey (26, 0);
        
        for(char& c : s)
            hashKey[c - 'a']++;
        
        return hashKey;
    }
};

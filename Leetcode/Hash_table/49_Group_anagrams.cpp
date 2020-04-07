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

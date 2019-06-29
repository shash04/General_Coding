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

// ****************************************************************************
// Optimal solution
// Approach - Create a map of sorted string as key and all anagrams as value
// ****************************************************************************
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        if(!strs.size())
            return ans;
        
        unordered_map<string, vector<string>> m1;
        
        for(auto curr_str : strs)
        {
            string temp = curr_str;
            sort(temp.begin(), temp.end());
            m1[temp].push_back(curr_str);
        }
        
        for(auto entry : m1)
        {
            ans.push_back(entry.second);
        }
        
        return ans;
    }
};

// ****************************************************************************
// Slightly slower solution
// Approach - create a map of vector<int> as key and anagrams as value
// ****************************************************************************
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(!strs.size())
            return ans;
        
        map<vector<int>, vector<string>> m1;
        
        for(auto curr_str : strs)
        {
            vector<int> curr_vec (26, 0);
            for(int i=0; i<curr_str.size(); i++)
            {
                int index = curr_str[i] - 'a';
                curr_vec[index]++;
            }
            if(m1.find(curr_vec) != m1.end())
            {
                m1[curr_vec].push_back(curr_str);
            }
            else
            {
                vector<string> new_vec;
                new_vec.push_back(curr_str);
                m1.insert({curr_vec, new_vec});
            }
        }
        
        for(auto entry : m1)
        {
            vector<string> temp;
            for( auto str : entry.second )
            {
                temp.push_back(str);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};